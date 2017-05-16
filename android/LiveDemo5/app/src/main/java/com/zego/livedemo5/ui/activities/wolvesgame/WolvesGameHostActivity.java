package com.zego.livedemo5.ui.activities.wolvesgame;

import android.app.Activity;
import android.content.DialogInterface;
import android.content.Intent;
import android.graphics.Rect;
import android.os.Bundle;
import android.support.v7.app.AlertDialog;
import android.text.TextUtils;
import android.view.Surface;
import android.view.View;
import android.widget.ArrayAdapter;

import com.zego.livedemo5.R;
import com.zego.livedemo5.ZegoApiManager;
import com.zego.livedemo5.constants.IntentExtra;
import com.zego.livedemo5.presenters.WolfInfo;
import com.zego.livedemo5.utils.JsonUtil;
import com.zego.livedemo5.utils.PreferenceUtil;
import com.zego.livedemo5.utils.ZegoRoomUtil;
import com.zego.zegoliveroom.ZegoLiveRoom;
import com.zego.zegoliveroom.callback.IZegoCustomCommandCallback;
import com.zego.zegoliveroom.callback.IZegoLivePlayerCallback;
import com.zego.zegoliveroom.callback.IZegoLivePublisherCallback;
import com.zego.zegoliveroom.callback.IZegoLoginCompletionCallback;
import com.zego.zegoliveroom.callback.IZegoRoomCallback;
import com.zego.zegoliveroom.callback.im.IZegoIMCallback;
import com.zego.zegoliveroom.constants.ZegoConstants;
import com.zego.zegoliveroom.constants.ZegoIM;
import com.zego.zegoliveroom.constants.ZegoVideoViewMode;
import com.zego.zegoliveroom.entity.AuxData;
import com.zego.zegoliveroom.entity.ZegoConversationMessage;
import com.zego.zegoliveroom.entity.ZegoRoomMessage;
import com.zego.zegoliveroom.entity.ZegoStreamInfo;
import com.zego.zegoliveroom.entity.ZegoUser;
import com.zego.zegoliveroom.entity.ZegoUserState;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

import java.util.HashMap;
import java.util.LinkedList;
import java.util.Map;
import java.util.Random;

import butterknife.OnClick;

public class WolvesGameHostActivity extends WolvesGameBaseActivity {
    private boolean isUltraServer;  // true: 使用自己的服务器进行推流(低延迟), false 使用CDN推流(低成本)
    private String roomId;
    private String roomName = "Wolves Game";
    private int appOrientation = Surface.ROTATION_0;

    private boolean mHasLoginRoom = false;

    private int currentSpeakingMode;

    private int currentIndex;
    private int currentSpeakingIndex;
    private String currentSpeakingUserId;
    private boolean isSpeaking;
    private boolean isPublishing;
    private int myCharacter;

    /**
     * 房间里的所有成员
     */
    private LinkedList<WolfInfo> allWolfMembers;

    /**
     * 当前参与游戏的人员列表
     */
    private LinkedList<WolfInfo> inGamingMembers;

    public static void actionStart(Activity activity, String publishTitle, int appOrientation) {
        Intent intent = new Intent(activity, WolvesGameHostActivity.class);
        intent.putExtra(IntentExtra.PUBLISH_TITLE, publishTitle);
        intent.putExtra(IntentExtra.APP_ORIENTATION, appOrientation);
        activity.startActivity(intent);
        activity.overridePendingTransition(R.anim.scale_translate,
                R.anim.my_alpha_action);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        showSelectPublishWayDialog();
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();

        allWolfMembers.clear();
        inGamingMembers.clear();

        stopCurrentMode();

        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.setZegoLivePublisherCallback(null);
        zegoLiveRoom.setZegoLivePlayerCallback(null);
        zegoLiveRoom.setZegoRoomCallback(null);
        zegoLiveRoom.setZegoIMCallback(null);

        if (mHasLoginRoom) {
            boolean logoutSuccess = zegoLiveRoom.logoutRoom();
            recordLog("退出房间成功？%s", logoutSuccess);
        }

        mHandler.removeCallbacksAndMessages(null);
    }

    /**
     * 初始化从外部传递过来的数据.
     */
    protected void initExtraData(Bundle savedInstanceState) {
        if (savedInstanceState == null) {
            Intent intent = getIntent();
            String publishTitle = intent.getStringExtra(IntentExtra.PUBLISH_TITLE);
            if (TextUtils.isEmpty(publishTitle)) {
                roomName += PreferenceUtil.getInstance().getUserName();
            } else {
                roomName = publishTitle;
            }
            appOrientation = intent.getIntExtra(IntentExtra.APP_ORIENTATION, Surface.ROTATION_0);
        }
    }

    /**
     * 初始化子类中的变量.
     */
    protected void initVariables(Bundle savedInstanceState) {
        allWolfMembers = new LinkedList<>();
        inGamingMembers = new LinkedList<>();
        mRecyclerAdapter = new RecyclerGridViewAdapter(this);
        currentSpeakingMode = ZegoSpeakingMode.FreeSpeakingMode;
    }

    /**
     * 加载数据.
     */
    protected void doBusiness(Bundle savedInstanceState) {
        // nothing to do
    }

    @OnClick({R.id.btn_start_or_stop_speaking, R.id.in_turn_speaking, R.id.end_in_turn_speaking})
    public void onButtonClick(View view) {
        switch (view.getId()) {
            case R.id.btn_start_or_stop_speaking:
                onSpeakingButtonClick();
                break;

            case R.id.in_turn_speaking:
                onInTurnSpeaking();
                break;

            case R.id.end_in_turn_speaking:
                onEndInTurnSpeaking();
                break;
        }
    }

    private void reportStopSpeaking() {
        JSONObject json = new JSONObject();
        try {
            json.put(kSpeakingCommandKey, ZegoSpeakingCmd.StopSpeaking);
            json.put(kSpeakingUserIdKey, PreferenceUtil.getInstance().getUserID());
        } catch (JSONException e) {

        }

        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.sendCustomCommand(getCurrentMembers(), json.toString(), new IZegoCustomCommandCallback() {
            @Override
            public void onSendCustomCommand(int i, String s) {
                recordLog("结束说话");

                arrangeNextSpeaker();
            }
        });
    }

    private void onStopSpeaking() {
        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.stopPublishing();

        mBtnSpeaking.setText(R.string.start_speaking);
        if (currentSpeakingMode == ZegoSpeakingMode.InTurnSpeakingMode) {
            mCurrentSpeakingHead.setVisibility(View.GONE);

            mTextTips.setText(R.string.mode_in_turn_speaking);
            mBtnSpeaking.setEnabled(false);
            reportStopSpeaking();
        } else if (currentSpeakingMode == ZegoSpeakingMode.FreeSpeakingMode) {
            mTextTips.setText(R.string.mode_free_speaking);
            mBtnSpeaking.setEnabled(true);
        }

        WolfInfo myInfo = getMyInfo();
        myInfo.setStreamId(null);
        mRecyclerAdapter.updateItem(myInfo);
    }

    private void stopTalking() {
        isSpeaking = false;

        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.enableMic(false);
        zegoLiveRoom.enableCamera(false);
        zegoLiveRoom.setPreviewView(null);

        WolfInfo myInfo = getMyInfo();
        if (myInfo == null) return;

        if (TextUtils.isEmpty(myInfo.getStreamId())) {
            zegoLiveRoom.stopPublishing();
            mBtnSpeaking.setText(R.string.start_speaking);
            mBtnSpeaking.setEnabled(true);
            mTextTips.setText(R.string.tips_publish_stop);
        } else {
            mTextTips.setText(R.string.mode_updating_system);
            mBtnSpeaking.setEnabled(false);

            onStopSpeaking();
        }
    }

    private void doPublish(ZegoLiveRoom zegoLiveRoom) {
        WolfInfo wolf = getMyInfo();
        if (wolf == null) return;

        wolf.setStreamId(ZegoRoomUtil.getPublishStreamID());
        zegoLiveRoom.setWaterMarkImagePath(null);
        Rect zeroRect = new Rect(0, 0, 0, 0);
        zegoLiveRoom.setPreviewWaterMarkRect(zeroRect);
        zegoLiveRoom.setPublishWaterMarkRect(zeroRect);

        zegoLiveRoom.startPreview();
        zegoLiveRoom.setPreviewView(null);

        boolean success = zegoLiveRoom.startPublishing(wolf.getStreamId(), roomName, isUltraServer ? ZegoConstants.PublishFlag.JoinPublish : ZegoConstants.PublishFlag.SingleAnchor);
        if (success) {
            isSpeaking = true;
            isPublishing = true;
            recordLog("开始直播，流Id: %s", wolf.getStreamId());
        }
    }

    private void startTalking() {
        mTextTips.setText(R.string.mode_updating_system);
        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.enableMic(false);
        zegoLiveRoom.enableCamera(false);

        // 每个人最多只允许说话 60s 时间
        mHandler.postDelayed(new Runnable() {
            @Override
            public void run() {
                // TODO stop speaking???
            }
        }, kSpeakingTimerInterval);

        doPublish(zegoLiveRoom);
    }

    private void onSpeakingButtonClick() {
        if (isSpeaking) {
            stopTalking();
        } else {
            mBtnSpeaking.setText(R.string.end_speaking);
            startTalking();
        }
    }

    private void stopPublish(ZegoLiveRoom zegoLiveRoom) {
        zegoLiveRoom.stopPreview();
        zegoLiveRoom.setPreviewView(null);
        zegoLiveRoom.stopPublishing();

        isSpeaking = false;
    }

    private void stopPlay(ZegoLiveRoom zegoLiveRoom, String streamId) {
        if (TextUtils.isEmpty(streamId)) return;

        zegoLiveRoom.stopPlayingStream(streamId);
    }

    private HashMap<Integer, String> randomCharacter() {
        int count = inGamingMembers.size();
        HashMap<Integer, String> characters = new HashMap<>(count);
        Random randomIns = new Random();
        for (WolfInfo wolf : inGamingMembers) {
            int character = randomIns.nextInt(count) + 1;
            while (characters.containsKey(character)) {
                character = randomIns.nextInt(count) + 1;
            }

            String userId = wolf.getUserId();
            characters.put(character, userId);

            if (myCharacter == 0 && isMe(userId)) {
                myCharacter = character;
            }
        }
        return characters;
    }

    private void broadInTurnSpeaking(HashMap<Integer, String> characters) {
        JSONObject jsonCmd = new JSONObject();
        try {
            JSONObject jsonCharacters = new JSONObject();
            for (Map.Entry<Integer, String> entry : characters.entrySet()) {
                jsonCharacters.put(entry.getValue(), entry.getKey());
            }
            jsonCmd.put(kSpeakingCommandKey, ZegoSpeakingCmd.InTurnSpeaking);
            jsonCmd.put(kUserCharacterKey, jsonCharacters);
        } catch (JSONException e) {

        }

        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.sendCustomCommand(getCurrentInGamingMembers(), jsonCmd.toString(), new IZegoCustomCommandCallback() {
            @Override
            public void onSendCustomCommand(int errorCode, String roomId) {
                recordLog("切换到轮流说话模式，errorCode: %d", errorCode);
                if (errorCode == 0) {
                    mTextRole.setText(getString(R.string.wolf_role, myCharacter));
                    mTextRole.setVisibility(View.VISIBLE);

                    currentSpeakingIndex = 0;
                    currentSpeakingMode = ZegoSpeakingMode.InTurnSpeakingMode;

                    mInTurnSpeaking.setEnabled(false);
                    mEndInTurnSpeaking.setEnabled(true);
                    mTextTips.setText(R.string.mode_in_turn_speaking);

                    mRecyclerAdapter.setCurrentSpeakingMode(ZegoSpeakingMode.InTurnSpeakingMode);

                    arrangeNextSpeaker();
                }
            }
        });
    }

    private void stopCurrentMode() {
        // stop current mode
        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        for (WolfInfo wolf : allWolfMembers) {
            if (wolf == null) continue;

            String streamId = wolf.getStreamId();
            if (TextUtils.isEmpty(streamId)) continue;

            if (isMe(wolf.getUserId())) {
                stopPublish(zegoLiveRoom);
            } else {
                stopPlay(zegoLiveRoom, streamId);
            }

            wolf.setStreamId(null);
            mRecyclerAdapter.updateItem(wolf);
        }
    }

    private void onInTurnSpeaking() {
        stopCurrentMode();

        inGamingMembers.clear();
        inGamingMembers.addAll(allWolfMembers);
        HashMap<Integer, String> characters = randomCharacter();
        broadInTurnSpeaking(characters);
    }

    private void broadFreeSpeaking() {
        JSONObject jsonCmd = new JSONObject();
        try {
            jsonCmd.put(kSpeakingCommandKey, ZegoSpeakingCmd.FreeSpeaking);
        } catch (JSONException e) {

        }
        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.sendCustomCommand(getCurrentMembers(), jsonCmd.toString(), new IZegoCustomCommandCallback() {
            @Override
            public void onSendCustomCommand(int errorCode, String roomId) {
                recordLog("切换到自由说话模式，errorCode: %d", errorCode);

                currentSpeakingMode = ZegoSpeakingMode.FreeSpeakingMode;
                mBtnSpeaking.setEnabled(true);
                mTextTips.setText(R.string.mode_free_speaking);

                mRecyclerAdapter.setCurrentSpeakingMode(ZegoSpeakingMode.FreeSpeakingMode);
            }
        });
    }

    private void onEndInTurnSpeaking() {
        inGamingMembers.clear();
        mEndInTurnSpeaking.setEnabled(false);
        mInTurnSpeaking.setEnabled(true);
        mTextRole.setVisibility(View.INVISIBLE);
        mBtnSpeaking.setEnabled(true);

        stopCurrentMode();
        currentSpeakingIndex = 0;
        currentSpeakingUserId = "";

        mCurrentSpeakingHead.setVisibility(View.GONE);

        broadFreeSpeaking();
    }

    private void showSelectPublishWayDialog() {
        String[] publishWays = new String[] {
                getString(R.string.publish_way_low_delay), getString(R.string.publish_way_low_cost)
        };
        final AlertDialog.Builder dialogBuilder = new AlertDialog.Builder(this);
        dialogBuilder.setTitle(R.string.publish_way_title)
                .setAdapter(new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, android.R.id.text1, publishWays), new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        switch (which) {
                            case 0: // PublishWay.Low_Delay
                                isUltraServer = true;
                                break;

                            case 1: // PublishWay.Low_Cost
                                isUltraServer = false;
                                break;
                        }
                        _doBusiness();
                    }
                });
        dialogBuilder.setNegativeButton(R.string.cancel, new DialogInterface.OnClickListener() {
            @Override
            public void onClick(DialogInterface dialog, int which) {
                dialog.dismiss();
                onBackPressed();
            }
        });
        mHandler.postDelayed(new Runnable() {
            public void run() {
                dialogBuilder.create().show();
            }
        }, 100);
    }

    private void _doBusiness() {
        roomId = ZegoRoomUtil.getRoomID(ZegoRoomUtil.ROOM_TYPE_WOLF);
        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.setRoomConfig(false, true);
        zegoLiveRoom.setZegoLivePublisherCallback(new ZegoLivePublisherCallback());
        zegoLiveRoom.setZegoLivePlayerCallback(new ZegoLivePlayerCallback());
        zegoLiveRoom.setZegoRoomCallback(new ZegoRoomCallback());
        zegoLiveRoom.setZegoIMCallback(new ZegoIMCallback());
        zegoLiveRoom.loginRoom(roomId, roomName, ZegoConstants.RoomRole.Anchor, new IZegoLoginCompletionCallback() {
            @Override
            public void onLoginCompletion(int errorCode, ZegoStreamInfo[] zegoStreamInfos) {
                if (isFinishing()) return;

                if (errorCode == 0) {
                    mHasLoginRoom = true;
                    mTextTips.setText(R.string.tips_login_success);
                    recordLog("登录房间成功. roomId: " + roomId);

                    currentIndex = 1;
                    WolfInfo wolf = new WolfInfo(PreferenceUtil.getInstance().getUserID(), PreferenceUtil.getInstance().getUserName());
                    wolf.setIndex(currentIndex);
                    allWolfMembers.add(wolf);
                    mRecyclerAdapter.updateData(allWolfMembers, true);

                    mBtnSpeaking.setEnabled(true);
                    mTextTips.setText(R.string.mode_free_speaking);
                } else {
                    mTextTips.setText(getString(R.string.tips_login_failed, errorCode));
                    recordLog("登录房间失败. errorCode: " + errorCode);
                }
            }
        });
    }

    private void resetPlayViewAndStop(String userId) {
        WolfInfo wolf = getWolfById(userId);
        if (wolf == null) return;

        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.stopPlayingStream(wolf.getStreamId());

        wolf.setStreamId(null);
        mRecyclerAdapter.updateItem(wolf);
    }

    private void broadAllowSpeaking(WolfInfo wolf) {
        String userId = wolf.getUserId();
        final String userName = wolf.getUserName();
        JSONObject json = new JSONObject();
        try {
            json.put(kSpeakingCommandKey, ZegoSpeakingCmd.AllowSpeaking);
            json.put(kSpeakingUserIdKey, userId);
        } catch (JSONException e) {

        }

        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.sendCustomCommand(getCurrentInGamingMembers(), json.toString(), new IZegoCustomCommandCallback() {
            @Override
            public void onSendCustomCommand(int errorCode, String roomId) {
                recordLog("下一个说话的人(errorCode: %d)：%s", errorCode, userName);
            }
        });
    }

    private void arrangeNextSpeaker() {
        recordLog("当前说话的人: %d", currentSpeakingIndex);

        int index = 0;
        int minDelta = Integer.MAX_VALUE;
        for (WolfInfo wolf : inGamingMembers) {
            if (wolf.getIndex() > currentSpeakingIndex && wolf.getIndex() - currentSpeakingIndex < minDelta) {
                minDelta = wolf.getIndex() - currentSpeakingIndex;
                index = inGamingMembers.indexOf(wolf);
            }
        }

        if (index >= inGamingMembers.size()) {
            recordLog("索引越界了，index: %d, inGamingMembers's count: %d", index, inGamingMembers.size());
            return;
        }

        WolfInfo wolf = inGamingMembers.get(index);
        currentSpeakingIndex = wolf.getIndex();
        currentSpeakingUserId = wolf.getUserId();

        recordLog("允许下一个说话的人: %d-%s", wolf.getIndex(), wolf.getUserName());

        if (isMe(currentSpeakingUserId)) {
            mBtnSpeaking.setText(R.string.start_speaking);
            mBtnSpeaking.setEnabled(true);

            //TODO auto stop current state after 60s
        }

        broadAllowSpeaking(wolf);
    }

    private void answerRoomInfo(String userId, String userName) {
        removeOlderUser(userId, true);

        currentIndex ++;

        JSONObject cmdJson = new JSONObject();
        try {
            cmdJson.put(kSpeakingCommandKey, ZegoSpeakingCmd.AnswerRoomInfo);
            cmdJson.put(kUserIndexKey, currentIndex);
            cmdJson.put(kSpeakingModeKey, currentSpeakingMode);
            cmdJson.put(kServerModeIndexKey, isUltraServer);

            JSONArray wolves = new JSONArray();
            for (WolfInfo wolf : allWolfMembers) {
                JSONObject wolfJson = encodeWolfInfo(wolf);
                wolves.put(wolfJson);
            }
            cmdJson.put(kCurrentUserListKey, wolves);
        } catch (JSONException e) {

        }

        ZegoUser zegoUser = new ZegoUser();
        zegoUser.userID = userId;
        zegoUser.userName = userName;
        ZegoApiManager.getInstance().getZegoLiveRoom().sendCustomCommand(new ZegoUser[] { zegoUser }, cmdJson.toString(), new IZegoCustomCommandCallback() {

            @Override
            public void onSendCustomCommand(int errorCode, String roomId) {
                recordLog("回复新加入狼消息返回，errorCode: %d; roomId: %s", errorCode, roomId);
            }
        });

        WolfInfo newWolf = new WolfInfo(zegoUser);
        newWolf.setIndex(currentIndex);

        // 通知其他人有新狼加入
        JSONObject newUserJoinCmd = new JSONObject();
        try {
            newUserJoinCmd.put(kSpeakingCommandKey, ZegoSpeakingCmd.NewUserJoinRoom);
            newUserJoinCmd.put(kNewUserKey, encodeWolfInfo(newWolf));
        } catch (JSONException e) {

        }

        ZegoApiManager.getInstance().getZegoLiveRoom().sendCustomCommand(getCurrentMembers(), newUserJoinCmd.toString(), new IZegoCustomCommandCallback() {
            @Override
            public void onSendCustomCommand(int errorCode, String roomId) {
                recordLog("通知新狼加入消息返回，errorCode: %d; roomId: %s", errorCode, roomId);
            }
        });

        allWolfMembers.add(newWolf);
//        mRecyclerAdapter.updateData(allWolfMembers, true);
        mRecyclerAdapter.insertItem(newWolf);

        if (currentSpeakingMode == ZegoSpeakingMode.FreeSpeakingMode) {
            mInTurnSpeaking.setEnabled(true);
        }
    }

    private void broadUserLeave(final String userId) {
        JSONObject json = new JSONObject();
        try {
            json.put(kSpeakingCommandKey, ZegoSpeakingCmd.UserLeaveRoom);
            json.put(kSpeakingUserIdKey, userId);
        } catch (JSONException e) {

        }

        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.sendCustomCommand(getCurrentMembers(), json.toString(), new IZegoCustomCommandCallback() {
            @Override
            public void onSendCustomCommand(int errorCode, String roomId) {
                recordLog("通知有用户离开, errorCode: %d, userId: %s", errorCode, userId);
            }
        });
    }

    private void removeOlderUser(String userId, boolean broadcast) {
        WolfInfo wolf = getWolfById(userId);
        if (wolf == null) return;

        if (!TextUtils.isEmpty(wolf.getStreamId())) {
            stopPlay(ZegoApiManager.getInstance().getZegoLiveRoom(), wolf.getStreamId());
            wolf.setStreamId(null);
        }

        allWolfMembers.remove(wolf);
        mRecyclerAdapter.deleteItem(wolf);

        if (currentSpeakingMode == ZegoSpeakingMode.InTurnSpeakingMode) {
            for (WolfInfo _wolf : inGamingMembers) {
                if (userId.equals(_wolf.getUserId())) {
                    inGamingMembers.remove(_wolf);
                    break;
                }
            }

            if (inGamingMembers.size() < 2) {
                mInTurnSpeaking.setEnabled(false);
                mEndInTurnSpeaking.setEnabled(false);

                stopCurrentMode();
                currentSpeakingMode = ZegoSpeakingMode.FreeSpeakingMode;
                mBtnSpeaking.setEnabled(true);

                mTextTips.setText(R.string.tips_all_members_leave);
            }
        }

        if (broadcast) {
            broadUserLeave(userId);
        }
    }

    private ZegoUser[] getCurrentMembers() {
        ZegoUser[] members = new ZegoUser[allWolfMembers.size()];
        int index = 0;
        for (WolfInfo wolf : allWolfMembers) {
            members[index++] = wolf;
        }
        return members;
    }

    private ZegoUser[] getCurrentInGamingMembers() {
        ZegoUser[] members = new ZegoUser[inGamingMembers.size()];
        int index = 0;
        for (WolfInfo wolf : inGamingMembers) {
            members[index++] = wolf;
        }
        return members;
    }

    private WolfInfo getWolfById(String userId) {
        for (WolfInfo wolf : allWolfMembers) {
            if (userId.equals(wolf.getUserId())) {
                return wolf;
            }
        }
        return null;
    }

    private WolfInfo getMyInfo() {
        String userId = PreferenceUtil.getInstance().getUserID();
        return getWolfById(userId);
    }

    private void handleStreamAdded(ZegoStreamInfo[] streamList, String roomId) {
        for (ZegoStreamInfo stream : streamList) {
            WolfInfo wolf = getWolfById(stream.userID);
            if (wolf == null) continue;

            wolf.setStreamId(stream.streamID);
            mRecyclerAdapter.updateItem(wolf);

            if (currentSpeakingMode == ZegoSpeakingMode.InTurnSpeakingMode) {
                ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
                if (isMe(stream.userID)) {
                    zegoLiveRoom.setPreviewView(mCurrentSpeakingHead);
                    zegoLiveRoom.setPreviewViewMode(ZegoVideoViewMode.ScaleAspectFill);
                    zegoLiveRoom.startPreview();
                } else {
                    zegoLiveRoom.setViewMode(ZegoVideoViewMode.ScaleAspectFill, stream.streamID);
                    zegoLiveRoom.startPlayingStream(stream.streamID, mCurrentSpeakingHead);
                }
                mCurrentSpeakingHead.setVisibility(View.VISIBLE);
            }
        }
    }

    private void handleStreamDeleted(ZegoStreamInfo[] streamList, String roomId) {
        for (ZegoStreamInfo stream : streamList) {
            WolfInfo wolf = getWolfById(stream.userID);
            if (wolf == null) continue;

            wolf.setStreamId(null);
            mRecyclerAdapter.updateItem(wolf);

            if (currentSpeakingMode == ZegoSpeakingMode.InTurnSpeakingMode) {
                ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
                if (isMe(stream.userID)) {
                    zegoLiveRoom.setPreviewView(null);
                    zegoLiveRoom.stopPreview();
                } else {
                    zegoLiveRoom.stopPlayingStream(stream.streamID);
                }
                mCurrentSpeakingHead.setVisibility(View.GONE);
            }
        }
    }

    private class ZegoLivePublisherCallback implements IZegoLivePublisherCallback {
        /**
         * 推流状态更新.
         *
         * @param stateCode     状态码, 0:成功, 其它:失败
         * @param streamId      流ID
         * @param streamInfo    推流信息
         */
        @Override
        public void onPublishStateUpdate(int stateCode, String streamId, HashMap<String, Object> streamInfo) {
            recordLog("推流状态更新, stateCode: %d; streamId: %s; Stream: %s", stateCode, streamId, streamInfo);
            isPublishing = false;
            if (stateCode == 0) {
                mTextTips.setText(R.string.mode_update_system_success);

                WolfInfo myInfo = getMyInfo();
                if (myInfo == null || !TextUtils.equals(myInfo.getStreamId(), streamId)) return;

                myInfo.setStreamId(streamId);
                ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
                zegoLiveRoom.enableMic(true);
                zegoLiveRoom.enableCamera(true);
                mRecyclerAdapter.updateItem(myInfo);

                if (currentSpeakingMode == ZegoSpeakingMode.InTurnSpeakingMode) {
                    zegoLiveRoom.setPreviewView(mCurrentSpeakingHead);
                    zegoLiveRoom.startPreview();
                    mCurrentSpeakingHead.setVisibility(View.VISIBLE);
                }
            } else {
                WolfInfo myInfo = getMyInfo();
                if (myInfo == null || !TextUtils.equals(myInfo.getStreamId(), streamId)) return;

                myInfo.setStreamId(null);
                mTextTips.setText(R.string.mode_update_system_failed);

                String errorMsg;
                if (stateCode == 1) {
                    errorMsg = getString(R.string.tips_publish_failed, stateCode, streamId);
                } else {
                    errorMsg = getString(R.string.tips_publish_finish, stateCode, streamId);
                }
                mTextTips.setText(errorMsg);
            }

        }

        /**
         * 收到连麦请求.
         *
         * @param seq            请求seq
         * @param fromUserId     来源用户ID
         * @param fromUserName   来源用户名
         * @param roomId         房间ID
         */
        @Override
        public void onJoinLiveRequest(int seq, String fromUserId, String fromUserName, String roomId) {
            recordLog("收到连麦请求, seq: %d; roomId: %s; fromUserId: %s; fromUserName: %s", seq, roomId, fromUserId, fromUserName);
        }

        /**
         * 推流质量更新.
         *
         * @param streamId      流ID
         * @param quality       0 ~ 3 分别对应优良中差
         * @param videoFPS      帧率
         * @param videoBitrate  码率
         */
        @Override
        public void onPublishQualityUpdate(String streamId, int quality, double videoFPS, double videoBitrate) {

        }

        /**
         * 音乐伴奏回调, 每次取20毫秒的数据.
         *
         * @param dataLen  20毫秒的数据长度
         * @return 背景音乐数据
         */
        @Override
        public AuxData onAuxCallback(int dataLen) {
            return null;
        }

        /**
         * 采集视频的宽度和高度变化通知.
         *
         * @param width     视频宽度
         * @param height    视频高度
         */
        @Override
        public void onCaptureVideoSizeChangedTo(int width, int height) {

        }

        /**
         * 混流配置更新。
         *
         * @param stateCode     状态码, 0:成功, 其它:失败
         * @param mixStreamId   混流ID
         * @param streamInfo    混流信息
         */
        @Override
        public void onMixStreamConfigUpdate(int stateCode, String mixStreamId, HashMap<String, Object> streamInfo) {

        }
    }

    private class ZegoLivePlayerCallback implements IZegoLivePlayerCallback {
        /**
         * 拉流状态更新.
         *
         * @param stateCode     状态码, 0:成功, 其它:失败
         * @param streamId      流ID
         */
        @Override
        public void onPlayStateUpdate(int stateCode, String streamId) {
            recordLog("拉流状态更新, stateCode: %d; streamId: %s", stateCode, streamId);
        }

        /**
         * 推流质量更新.
         *
         * @param streamId      流ID
         * @param quality       0 ~ 3 分别对应优良中差
         * @param videoFPS      帧率
         * @param videoBitrate  码率
         */
        @Override
        public void onPlayQualityUpdate(String streamId, int quality, double videoFPS, double videoBitrate) {

        }

        /**
         * 收到连麦邀请.
         *
         * @param seq           请求 seq
         * @param fromUserId    来源用户ID
         * @param fromUserName  来源用户名
         * @param roomId        房间ID
         */
        @Override
        public void onInviteJoinLiveRequest(int seq, String fromUserId, String fromUserName, String roomId) {
            recordLog("收到连麦邀请, seq: %d; roomId: %s; fromUserId: %s; fromUserName: %s", seq, roomId, fromUserId, fromUserName);
        }

        /**
         * 视频宽高变化通知,startPlay后，如果视频宽度或者高度发生变化(首次的值也会)，则收到该通知.
         *
         * @param streamId  流ID
         * @param width     视频宽度
         * @param height    视频高度
         */
        @Override
        public void onVideoSizeChangedTo(String streamId, int width, int height) {

        }
    }

    private class ZegoIMCallback implements IZegoIMCallback {
        /**
         * 房间成员更新回调.
         *
         * @param listUser     成员更新列表
         * @param updateType   @see com.zego.zegoliveroom.constants.ZegoIM#UserUpdateType
         */
        @Override
        public void onUserUpdate(ZegoUserState[] listUser, int updateType) {
            recordLog("房间成员有更新, updateType: %d; UserCount: %d", updateType, listUser.length);
            if (updateType == ZegoIM.UserUpdateType.Total) {
                //TODO
            } else if (updateType == ZegoIM.UserUpdateType.Increase) {
                for (ZegoUserState userState : listUser) {
                    if (userState.updateFlag == ZegoIM.UserUpdateFlag.Added) {
                        //TODO
                    } else if (userState.updateFlag == ZegoIM.UserUpdateFlag.Deleted) {
                        removeOlderUser(userState.userID, true);
                    }
                }
            }
        }

        /**
         * 收到房间的广播消息.
         *
         * @param roomId        房间ID
         * @param listMsg       消息列表, 包括消息内容，消息分类，消息类型，发送者等信息
         */
        @Override
        public void onRecvRoomMessage(String roomId, ZegoRoomMessage[] listMsg) {
            recordLog("收到房间消息，roomId: " + roomId);
        }

        /**
         * 收到会话消息.
         *
         * @param roomId            房间ID
         * @param conversationId    会话ID
         * @param message           会话消息, 包括消息内容，消息类型，发送者，发送时间等信息
         */
        @Override
        public void onRecvConversationMessage(String roomId, String conversationId, ZegoConversationMessage message) {
            recordLog("收到会话消息, roomId: %s; conversationId: %s", roomId, conversationId);
        }
    }

    private class ZegoRoomCallback implements IZegoRoomCallback {
        /**
         * 因为登陆抢占原因等被挤出房间.
         *
         * @param reason    原因
         * @param roomId    房间ID
         */
        @Override
        public void onKickOut(int reason, String roomId) {
            recordLog("被挤出房间, reason: %d; roomId: %s", reason, roomId);
        }

        /**
         * 与 server 断开.
         *
         * @param errorCode  错误码
         * @param roomId     房间ID
         */
        @Override
        public void onDisconnect(int errorCode, String roomId) {
            recordLog("连接丢失, errorCode: %d; roomId: %s", errorCode, roomId);
        }

        /**
         *  房间流列表更新.
         *
         * @param type          2001:增加, 2002:删除
         * @param listStream    流列表
         * @param roomId        房间ID
         */
        @Override
        public void onStreamUpdated(int type, ZegoStreamInfo[] listStream, String roomId) {
            recordLog("有流更新, type: %d; roomId: %s; streamCount: %d", type, roomId, listStream.length);
            if (listStream == null || listStream.length == 0 || TextUtils.isEmpty(roomId)) {
                // 无效流信息，忽略
            } else if (allWolfMembers.size() == 0) {
                // 信令到达前的流更新，暂存

            } else {
                switch (type) {
                    case ZegoConstants.StreamUpdateType.Added:
                        handleStreamAdded(listStream, roomId);
                        break;
                    case ZegoConstants.StreamUpdateType.Deleted:
                        handleStreamDeleted(listStream, roomId);
                        break;
                }
            }
        }

        /**
         * 更新流的额外信息.
         * @param listStream
         * @param roomId
         */
        @Override
        public void onStreamExtraInfoUpdated(ZegoStreamInfo[] listStream, String roomId) {
            recordLog("有流更新Ex, roomId: %s; streamCount: %d", roomId, listStream.length);
        }

        /**
         * 收到自定义消息.
         *
         * @param fromUserId     消息来源UserID
         * @param fromUserName   消息来源UserName
         * @param content    消息内容
         * @param roomId     房间ID
         */
        @Override
        public void onRecvCustomCommand(String fromUserId, String fromUserName, String content, String roomId) {
            recordLog("收到自定义消息, fromUserId: %s; fromUserName: %s; roomId: %s; content: %s", fromUserId, fromUserName, roomId, content);
            JSONObject json = (JSONObject)JsonUtil.safeDecodeFromString(content);
            int command = json.optInt(kSpeakingCommandKey, 0);
            switch (command) {
                case ZegoSpeakingCmd.StopSpeaking: {
                    String userId = json.optString(kSpeakingUserIdKey);
                    if (isMe(userId)) return;

                    resetPlayViewAndStop(userId);

                    arrangeNextSpeaker();
                }
                    break;

                case ZegoSpeakingCmd.AskRoomInfo: {
                    answerRoomInfo(fromUserId, fromUserName);
                }
                    break;

                case ZegoSpeakingCmd.UserLeaveRoom: {
                    String userId = json.optString(kSpeakingUserIdKey);
                    if (isMe(userId)) return;

                    removeOlderUser(userId, false);
                }
                    break;

                default:
                    recordLog("主播忽略消息, fromUserName: %s; Command: %d", fromUserName, command);
                    break;
            }
        }
    }
}
