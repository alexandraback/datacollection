package com.rotciv.rounda.b;

/**
 * Created by Administrator on 2015/4/18.
 */
public class Barber {

    int index;

    int time;

    int remain;

    public Barber(int index, int time) {
        this.index = index;
        this.time = time;
        remain = time;
    }

    public int getIndex() {
        return index;
    }

    public void setIndex(int index) {
        this.index = index;
    }

    public int getTime() {
        return time;
    }

    public void setTime(int time) {
        this.time = time;
    }

    public int getRemain() {
        return remain;
    }

    public void setRemain(int remain) {
        this.remain = remain;
    }

    public void decreaseTime(int time) {

        if (time > remain)
            throw new IllegalArgumentException();

        remain -= time;
    }

    public void resetRemain() {
        remain = time;
    }
}
