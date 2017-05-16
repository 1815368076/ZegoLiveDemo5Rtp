package com.zego.livedemo5.ui.activities.wolvesgame;

import android.Manifest;
import android.app.Activity;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Rect;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.provider.Settings;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v7.app.AlertDialog;
import android.text.TextUtils;
import android.view.View;
import android.widget.Toast;

import com.zego.livedemo5.R;
import com.zego.livedemo5.ZegoApiManager;
import com.zego.livedemo5.constants.IntentExtra;
import com.zego.livedemo5.presenters.RoomInfo;
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

import butterknife.OnClick;

public class WolvesGameInTurnActivity extends WolvesGameBaseActivity {
    private String roomId;
    private String roomName;
    private String anchorId;
    private String anchorName;

    private LinkedList<WolfInfo> wolfMembers;
    /**
     * @see ZegoSpeakingMode
     */
    private int speakingMode;
    private boolean isUltraServer;
    private boolean isSpeaking;
    private boolean isPublishing;
    private boolean hasLoginRoom;

    public static void actionStart(Activity context, RoomInfo room)  {
        Intent intent = new Intent(context, WolvesGameInTurnActivity.class);
        intent.putExtra(IntentExtra.ROOM_ID, room.room_id);
        intent.putExtra(IntentExtra.ROOM_NAME, room.room_name);
        intent.putExtra(IntentExtra.ANCHOR_ID, room.anchor_id_name);
        intent.putExtra(IntentExtra.ANCHOR_NAME, room.anchor_nick_name);
        context.startActivity(intent);
        context.overridePendingTransition(R.anim.scale_translate,
                R.anim.my_alpha_action);
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Override
    public void onBackPressed() {
        super.onBackPressed();

        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.setZegoLivePublisherCallback(null);
        zegoLiveRoom.setZegoLivePlayerCallback(null);
        zegoLiveRoom.setZegoRoomCallback(null);
        zegoLiveRoom.setZegoIMCallback(null);

        if (hasLoginRoom) {
            zegoLiveRoom.logoutRoom();
        }

        mHandler.removeCallbacksAndMessages(null);
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        switch (requestCode) {
            case 101: {
                boolean openSettingActivity = false;
                if (grantResults[0] == PackageManager.PERMISSION_DENIED) {
                    Toast.makeText(this, R.string.allow_camera_permission, Toast.LENGTH_LONG).show();
                    openSettingActivity = true;
                }
                if (grantResults[1] == PackageManager.PERMISSION_DENIED) {
                    Toast.makeText(this, R.string.open_recorder_permission, Toast.LENGTH_LONG).show();
                    openSettingActivity = true;
                }

                if (openSettingActivity) {
                    Intent intent = new Intent(Settings.ACTION_APPLICATION_DETAILS_SETTINGS);
                    intent.setData(Uri.parse("package:" + getPackageName()));
                    startActivity(intent);
                } else {
                    startTalking();
                }
            }
                break;
            default:
                super.onRequestPermissionsResult(requestCode, permissions, grantResults);
                break;
        }
    }

    private boolean requestPermission() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            if (ContextCompat.checkSelfPermission(this, Manifest.permission.CAMERA) != PackageManager.PERMISSION_GRANTED
                    || ContextCompat.checkSelfPermission(this, Manifest.permission.RECORD_AUDIO) != PackageManager.PERMISSION_GRANTED) {
                ActivityCompat.requestPermissions(this, new String[]{
                        Manifest.permission.CAMERA, Manifest.permission.RECORD_AUDIO}, 101);
                return true;
            }
        }
        return false;
    }

    /**
     * 初始化从外部传递过来的数据.
     */
    protected void initExtraData(Bundle savedInstanceState) {
        if (savedInstanceState == null) {
            Intent intent = getIntent();
            roomId = intent.getStringExtra(IntentExtra.ROOM_ID);
            roomName = intent.getStringExtra(IntentExtra.ROOM_NAME);
            anchorId = intent.getStringExtra(IntentExtra.ANCHOR_ID);
            anchorName = intent.getStringExtra(IntentExtra.ANCHOR_NAME);
        }
    }

    /**
     * 初始化子类中的变量.
     */
    protected void initVariables(Bundle savedInstanceState) {
        wolfMembers = new LinkedList<>();
        mRecyclerAdapter = new RecyclerGridViewAdapter(this);
    }

    @Override
    protected void initViews(Bundle savedInstanceState) {
        super.initViews(savedInstanceState);
        mInTurnSpeaking.setVisibility(View.GONE);
        mEndInTurnSpeaking.setVisibility(View.GONE);
    }

    /**
     * 加载数据.
     */
    protected void doBusiness(Bundle savedInstanceState) {
        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.setZegoRoomCallback(new ZegoRoomCallback());
        zegoLiveRoom.setZegoLivePublisherCallback(new ZegoLivePublisherCallback());
        zegoLiveRoom.setZegoLivePlayerCallback(new ZegoLivePlayerCallback());
        zegoLiveRoom.setZegoIMCallback(new ZegoIMCallback());

        loginChatRoom(zegoLiveRoom);
    }

    @OnClick(R.id.btn_start_or_stop_speaking)
    public void onStartOrStopSpeakingClick(View view) {
        if (isSpeaking) {
            stopTalking();
        } else {
            if (!requestPermission()) {
                startTalking();
            }
        }
    }

    private ZegoUser[] getCurrentMembers() {
        ZegoUser[] members = new ZegoUser[wolfMembers.size()];
        int index = 0;
        for (WolfInfo wolf : wolfMembers) {
            members[index++] = wolf;
        }
        return members;
    }

    private void reportStopSpeaking() {
        String myId = PreferenceUtil.getInstance().getUserID();
        if (!isMe(myId)) return;

        JSONObject json = new JSONObject();
        try {
            json.put(kSpeakingCommandKey, ZegoSpeakingCmd.StopSpeaking);
            json.put(kSpeakingUserIdKey, myId);
        } catch (JSONException e) {

        }

        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.sendCustomCommand(getCurrentMembers(), json.toString(), new IZegoCustomCommandCallback() {
            @Override
            public void onSendCustomCommand(int errorCode, String roomId) {
                recordLog("结束说话, errorCode: %d", errorCode);
            }
        });
    }

    private void stopTalking() {
        isSpeaking = false;
        mBtnSpeaking.setText(R.string.start_speaking);

        if (speakingMode == ZegoSpeakingMode.FreeSpeakingMode) {
            mTextTips.setText(R.string.mode_free_speaking);
        } else if (speakingMode == ZegoSpeakingMode.InTurnSpeakingMode) {
            mTextTips.setText(R.string.mode_in_turn_speaking);
            mBtnSpeaking.setEnabled(false);
        }

        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.stopPublishing();

        zegoLiveRoom.stopPreview();
        zegoLiveRoom.setPreviewView(null);
        mCurrentSpeakingHead.setVisibility(View.GONE);

        WolfInfo myInfo = getWolfById(PreferenceUtil.getInstance().getUserID());
        if (myInfo != null) {
            myInfo.setStreamId(null);
            mRecyclerAdapter.updateItem(myInfo);
        }

        if (speakingMode == ZegoSpeakingMode.InTurnSpeakingMode) {
            reportStopSpeaking();
        }
    }

    private void startTalking() {
        mBtnSpeaking.setText(R.string.end_speaking);
        mTextTips.setText(R.string.mode_updating_system);

        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        zegoLiveRoom.setWaterMarkImagePath(null);
        Rect zeroRect = new Rect(0, 0, 0, 0);
        zegoLiveRoom.setPreviewWaterMarkRect(zeroRect);
        zegoLiveRoom.setPublishWaterMarkRect(zeroRect);

        String streamId = ZegoRoomUtil.getPublishStreamID();
        boolean success = zegoLiveRoom.startPublishing(streamId, roomName, isUltraServer ? ZegoConstants.PublishFlag.JoinPublish : ZegoConstants.PublishFlag.SingleAnchor);
        if (success) {
            isPublishing = true;
            isSpeaking = true;
            recordLog("开始直播，流Id: %s", streamId);
        } else {
            recordLog("推直播流失败");
        }
    }

    private void loginChatRoom(final ZegoLiveRoom zegoLiveRoom) {
        zegoLiveRoom.setRoomConfig(false, true);
        zegoLiveRoom.loginRoom(roomId, ZegoConstants.RoomRole.Audience, new IZegoLoginCompletionCallback() {
            @Override
            public void onLoginCompletion(int errorCode, ZegoStreamInfo[] zegoStreamInfos) {
                if (isFinishing()) return;

                if (errorCode == 0) {
                    hasLoginRoom = true;
                    mTextTips.setText(R.string.tips_login_success);

                    recordLog("登录成功, roomId: %s", roomId);
                    int maxStreamCount = zegoLiveRoom.getMaxPlayChannelCount();
                    if (zegoStreamInfos.length < maxStreamCount) {
                        askAnchorRoomInfo(zegoLiveRoom);
                    }
                } else {
                    mTextTips.setText(R.string.tips_login_failed);
                    recordLog("登录房间失败，errorCode: %d", errorCode);

                    if (errorCode == 1048680) { // 主播离开房间
                        notifyAnchorLogout();
                    }
                }
            }
        });
    }

    private void askAnchorRoomInfo(ZegoLiveRoom zegoLiveRoom) {
        mTextTips.setText(R.string.tips_wait_anchor_answer);

        JSONObject jsonObject = new JSONObject();
        try {
            jsonObject.put(kSpeakingCommandKey, ZegoSpeakingCmd.AskRoomInfo);
        } catch (JSONException e) {

        }

        ZegoUser anchor = new ZegoUser();
        anchor.userID = anchorId;
        anchor.userName = anchorName;

        zegoLiveRoom.sendCustomCommand(new ZegoUser[]{anchor}, jsonObject.toString(), new IZegoCustomCommandCallback() {
            @Override
            public void onSendCustomCommand(int errorCode, String roomId) {
                recordLog("向主持人获取房间信息, errorCode: %d", errorCode);
            }
        });
    }

    private void notifyAnchorLogout() {
        AlertDialog.Builder dialogBuilder = new AlertDialog.Builder(this);
        dialogBuilder.setTitle(R.string.hint)
                .setMessage(R.string.dialog_anchor_leave_room)
                .setNegativeButton(R.string.got_it, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        dialog.dismiss();
                        onBackPressed();
                    }
                });
        dialogBuilder.create().show();
    }

    private void processAnswerRoomInfo(JSONObject answerJson) {
        isUltraServer = answerJson.optBoolean(kServerModeIndexKey, false);
        speakingMode = answerJson.optInt(kSpeakingModeKey, 0);
        mRecyclerAdapter.setCurrentSpeakingMode(speakingMode);

        recordLog("主持人同意了你的请求，use UltraServer: %s", isUltraServer);

        int myIndex = answerJson.optInt(kUserIndexKey, 0);
        WolfInfo myInfo = new WolfInfo(PreferenceUtil.getInstance().getUserID(), PreferenceUtil.getInstance().getUserName());
        myInfo.setIndex(myIndex);
        wolfMembers.add(myInfo);

        JSONArray jsonUserList = answerJson.optJSONArray(kCurrentUserListKey);
        if (jsonUserList == null || jsonUserList.length() == 0) return;

        for (int i = 0; i < jsonUserList.length(); i++) {
            JSONObject jsonObject = jsonUserList.optJSONObject(i);
            if (jsonObject == null) continue;

            int userIndex = jsonObject.optInt(kUserIndexKey);
            String userId = jsonObject.optString(kUserIdKey);
            String userName = jsonObject.optString(kUserNameKey);
            WolfInfo wolf = new WolfInfo(userId, userName);
            wolf.setIndex(userIndex);
            wolfMembers.add(wolf);
        }

        if (myIndex > 1) {
            if (speakingMode == ZegoSpeakingMode.FreeSpeakingMode) {    // 自由说话
                mTextTips.setText(R.string.mode_free_speaking);
                mBtnSpeaking.setEnabled(true);
            } else if (speakingMode == ZegoSpeakingMode.InTurnSpeakingMode) {   // 正在游戏，等待下一局
                mTextTips.setText(R.string.mode_in_turn_speaking_wait);
                mBtnSpeaking.setEnabled(false);
            }
            mBtnSpeaking.setText(R.string.start_speaking);

            //TODO 创建Publish

            mRecyclerAdapter.updateData(wolfMembers, true);
        } else {
            recordLog("主持人返回的座位号（%d）错误", myIndex);
        }

    }

    private void processAllowSpeaking(JSONObject json) {
        String userId = json.optString(kUserIdKey);
        if (TextUtils.isEmpty(userId)) return;

        // 轮到自己说话
        String myId = PreferenceUtil.getInstance().getUserID();
        if (userId.equals(myId)) {
            mBtnSpeaking.setEnabled(true);
            mBtnSpeaking.setText(R.string.start_speaking);

            //TODO process speaking
        }

        //TODO update wolfMembers status and update ui
    }

    private void processStopSpeaking(JSONObject json) {
        String userId = json.optString(kUserIdKey);
        if (isSpeaking && isMe(userId)) {
            stopTalking();
        } else {
            WolfInfo wolf = getWolfById(userId);
            if (wolf != null) {
                wolf.setStreamId(null);
                mRecyclerAdapter.updateItem(wolf);
            }
        }
    }

    private void processNewUserJoinRoom(JSONObject json) {
        JSONObject newUserJson = json.optJSONObject(kNewUserKey);
        if (newUserJson != null) {
            String userId = newUserJson.optString(kUserIdKey);
            String userName = newUserJson.optString(kUserNameKey);
            int index = newUserJson.optInt(kUserIndexKey);
            WolfInfo newWolf = new WolfInfo(userId, userName);
            newWolf.setIndex(index);
            wolfMembers.add(newWolf);
//            mRecyclerAdapter.updateData(wolfMembers, true);
            mRecyclerAdapter.insertItem(newWolf);
        }

    }

    private boolean removeMemberById(String userId) {
        boolean foundWolf = false;
        for (WolfInfo wolf : wolfMembers) {
            if (userId.equals(wolf.getUserId())) {
                foundWolf = true;
                wolfMembers.remove(wolf);
//                mRecyclerAdapter.deleteItem(wolf);
                break;
            }
        }

        if (foundWolf) {
            mRecyclerAdapter.updateData(wolfMembers, true);
        }

        return foundWolf;
    }

    private void processUserLeaveRoom(JSONObject json) {
        String userId = json.optString(kUserIdKey);
        if (TextUtils.isEmpty(userId)) return;

        removeMemberById(userId);
    }

    private void stopCurrentMode() {
        ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
        for (WolfInfo wolf : wolfMembers) {
            if (wolf == null || TextUtils.isEmpty(wolf.getStreamId())) continue;

            if (isMe(wolf.getUserId())) {
                zegoLiveRoom.stopPreview();
                zegoLiveRoom.setPreviewView(null);
                zegoLiveRoom.stopPublishing();
            } else {
                zegoLiveRoom.stopPlayingStream(wolf.getStreamId());
            }
            wolf.setStreamId(null);
            mRecyclerAdapter.updateItem(wolf);
        }
    }

    private void processInTurnSpeaking(JSONObject json) {
        speakingMode = ZegoSpeakingMode.InTurnSpeakingMode;
        mTextTips.setText(R.string.mode_in_turn_speaking);
        mBtnSpeaking.setEnabled(false);

        JSONObject wolfCharacters = json.optJSONObject(kUserCharacterKey);
        if (wolfCharacters != null) {
            String myId = PreferenceUtil.getInstance().getUserID();
            int myCharacter = wolfCharacters.optInt(myId);
            mTextRole.setText(getString(R.string.wolf_role, myCharacter));
            mTextRole.setVisibility(View.VISIBLE);
        }

        mRecyclerAdapter.setCurrentSpeakingMode(ZegoSpeakingMode.InTurnSpeakingMode);

        stopCurrentMode();
    }

    private void processFreeSpeaking(JSONObject json) {
        speakingMode = ZegoSpeakingMode.FreeSpeakingMode;
        mTextTips.setText(R.string.mode_free_speaking);

        mBtnSpeaking.setText(R.string.start_speaking);
        mBtnSpeaking.setEnabled(true);

        mTextRole.setVisibility(View.INVISIBLE);

        mRecyclerAdapter.setCurrentSpeakingMode(ZegoSpeakingMode.FreeSpeakingMode);

        stopCurrentMode();
    }

    private void handleStreamAdded(ZegoStreamInfo[] streamList, String roomId) {
        for (ZegoStreamInfo stream : streamList) {
            WolfInfo wolf = getWolfById(stream.userID);
            if (wolf == null) continue;

            wolf.setStreamId(stream.streamID);
            mRecyclerAdapter.updateItem(wolf);

            if (speakingMode == ZegoSpeakingMode.InTurnSpeakingMode) {
                ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
                if (isMe(stream.userID)) {
                    zegoLiveRoom.setPreviewViewMode(ZegoVideoViewMode.ScaleAspectFill);
                    zegoLiveRoom.setPreviewView(mCurrentSpeakingHead);
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

            if (speakingMode == ZegoSpeakingMode.InTurnSpeakingMode) {

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

    private WolfInfo getWolfById(String userId) {
        for (WolfInfo wolf : wolfMembers) {
            if (userId.equals(wolf.getUserId())) {
                return wolf;
            }
        }
        return null;
    }

    //============ call back delegates ===============//
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
                WolfInfo myInfo = getWolfById(PreferenceUtil.getInstance().getUserID());
                if (myInfo == null) return;

                myInfo.setStreamId(streamId);
                mRecyclerAdapter.updateItem(myInfo);

                mTextTips.setText(R.string.mode_update_system_success);

                ZegoLiveRoom zegoLiveRoom = ZegoApiManager.getInstance().getZegoLiveRoom();
                zegoLiveRoom.enableMic(true);
                zegoLiveRoom.enableCamera(true);

                if (speakingMode == ZegoSpeakingMode.InTurnSpeakingMode) {
                    mCurrentSpeakingHead.setVisibility(View.VISIBLE);

                    zegoLiveRoom.setPreviewView(mCurrentSpeakingHead);
                    zegoLiveRoom.setPreviewViewMode(ZegoVideoViewMode.ScaleAspectFill);
                    zegoLiveRoom.startPreview();
                }
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
            recordLog("收到帧数据, streamId: %s; width: %d; height: %d", streamId, width, height);
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
            for (ZegoUserState user : listUser) {
                if (user.roomRole == ZegoConstants.RoomRole.Anchor && user.updateFlag == ZegoIM.UserUpdateFlag.Deleted) {
                    notifyAnchorLogout();
                    break;
                }

                if (user.updateFlag == ZegoIM.UserUpdateFlag.Added) {
                    recordLog("%s 进入房间，等待主持人处理", user.userName);
                } else if (user.updateFlag == ZegoIM.UserUpdateFlag.Deleted) {
                    removeMemberById(user.userID);
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
            } else if (wolfMembers.size() == 0) {
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
            JSONObject json = (JSONObject) JsonUtil.safeDecodeFromString(content);
            int command = json.optInt(kSpeakingCommandKey, 0);
            switch (command) {
                case ZegoSpeakingCmd.AnswerRoomInfo:
                    processAnswerRoomInfo(json);
                    break;

                case ZegoSpeakingCmd.AllowSpeaking:
                    processAllowSpeaking(json);
                    break;

                case ZegoSpeakingCmd.StopSpeaking:
                    processStopSpeaking(json);
                    break;

                case ZegoSpeakingCmd.NewUserJoinRoom:
                    processNewUserJoinRoom(json);
                    break;

                case ZegoSpeakingCmd.UserLeaveRoom:
                    processUserLeaveRoom(json);
                    break;

                case ZegoSpeakingCmd.InTurnSpeaking:
                    processInTurnSpeaking(json);
                    break;

                case ZegoSpeakingCmd.FreeSpeaking:
                    processFreeSpeaking(json);
                    break;

                default:
                    recordLog("参与者无需处理此消息，command: %d", command);
                    break;
            }
        }
    }
}
