package com.zego.livedemo5.presenters;

import com.zego.zegoliveroom.entity.ZegoUser;

/**
 * Created by realuei on 2017/5/10.
 */

public class WolfInfo extends ZegoUser {
    private String streamId;
    private int index;
    private int role = -1;

    public WolfInfo(String userId, String userName) {
        this.userID = userId;
        this.userName = userName;
    }

    public WolfInfo(ZegoUser zegoUser) {
        this.userID = zegoUser.userID;
        this.userName = zegoUser.userName;
    }

    public String getUserId() {
        return userID;
    }

    public void setUserId(String userId) {
        this.userID = userId;
    }

    public String getUserName() {
        return userName;
    }

    public void setUserName(String userName) {
        this.userName = userName;
    }

    public String getStreamId() {
        return streamId;
    }

    public void setStreamId(String streamId) {
        this.streamId = streamId;
    }

    public int getIndex() {
        return index;
    }

    public void setIndex(int index) {
        this.index = index;
    }

    public int getRole() {
        return role;
    }

    public void setRole(int role) {
        this.role = role;
    }

    public void update(WolfInfo wolf) {
        if (wolf != null) {
            this.userID = wolf.userID;
            this.userName = wolf.userName;
            this.streamId = wolf.streamId;
            this.index = wolf.index;
            this.role = wolf.role;
        }
    }

    @Override
    public boolean equals(Object obj) {
        if (!(obj instanceof WolfInfo)) return false;

        return this.userID.equals(((WolfInfo)obj).userID);
    }
}
