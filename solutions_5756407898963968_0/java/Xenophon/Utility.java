package org.active.nerd.code.jam;

public class Utility {

    public static int[] toIntArray(String spaceDelim, String split) {
        String[] strings = spaceDelim.split(split);
        int[] retArray = new int[strings.length];
        for (int i = 0; i < strings.length; i++) {
            retArray[i] = Integer.parseInt(strings[i]);
        }

        return retArray;
    }

    public static Integer[] toIntgerArray(String ints, String split) {
        String[] strings = ints.split(split);
        Integer[] retArray = new Integer[strings.length];
        for (int i = 0; i < strings.length; i++) {
            retArray[i] = Integer.parseInt(strings[i]);
        }

        return retArray;
    }

}
