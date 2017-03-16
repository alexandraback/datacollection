import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Created by lin on 4/23/14.
 */
public class ASolution {
    private static List<List<Integer>> ints(List<StringBuilder> strings) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();

        StringBuilder lastStr = null;
        for(StringBuilder str : strings) {
            List<Integer> list = new ArrayList<Integer>();
            String seenChar = null;
            StringBuilder trimedStr = new StringBuilder();
            int count = 0;
            for(int i = 0; i < str.length(); ++i) {
                if(seenChar == null) {
                    seenChar = str.charAt(i) + "";
                    count = 1;
                    trimedStr.append(seenChar);

                } else if (seenChar.equals("" + str.charAt(i))){
                    count ++;
                } else {
                    list.add(count);
                    seenChar = str.charAt(i) + "";
                    count = 1;
                    trimedStr.append(seenChar);
                }
            }
            if(list.size() < trimedStr.length()) {
                list.add(count);
            }

            if(lastStr == null) {
                lastStr = trimedStr;
            } else if (!lastStr.toString().equals(trimedStr.toString())) {
                return null;
            }
            ret.add(list);

        }
        return ret;
    }
    public static String solve(List<StringBuilder> strings) {
        List<List<Integer>> transList = ints(strings);

        /*
        for(List<Integer> list : transList) {
            System.out.println(Arrays.toString(list.toArray()));
        }
        */
        if(transList == null) {
            return "Fegla Won";
        }

        int count = 0;

        for(int i = 0; i < transList.get(0).size(); ++i) {
            int[] cCounts = new int[transList.size()];
            for(int j = 0; j < transList.size(); ++j) {
                cCounts[j] = transList.get(j).get(i);
            }
            Arrays.sort(cCounts);
            int pivot = cCounts[cCounts.length / 2];
            for(int c : cCounts) {
                count += Math.abs(c - pivot);
            }
        }

        return "" + count;

    }

    public static void main(String[] args) {
        List<StringBuilder> strings = new ArrayList<StringBuilder>();
        for(String arg : args) {
            strings.add(new StringBuilder(arg));
        }

        System.out.println(solve(strings));
    }
}
