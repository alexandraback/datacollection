import java.util.Scanner;

public class R1BA {

    public static void main(String args[]) {



        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int t = 1; t <= T; t++) {
            // Set<Integer> r1 = readRow(in, in.nextInt());

            int N = in.nextInt();

            String[] list = new String[N];
            for(int i = 0; i < N; i ++)
                list[i] = in.next();

            int[] lens = new int[N];
            int result = 0;
            boolean bad = false;
            while(!list[0].equals("")) {
                char eat = list[0].charAt(0);
                for (int i = 0; i < N; i++) {
                    int len = 0;
                    String s = list[i];
                    while(len < s.length() && s.charAt(len) == eat) len++;
                    if(0 != len) {
                        list[i] = s.substring(len);
                        lens[i] = len;
                    } else {
                        bad = true;
                    }
                }
                if(bad)
                    break;
                result += min(lens);
            }

            // make sure eat up
            for(int i = 0; i < N && !bad; i ++) {
                if(!list[i].equals("")) {
                    bad = true;
                }
            }

            if(!bad) {
                System.out.format("Case #%d: %d\n", t, result);
            } else {
                System.out.format("Case #%d: Fegla Won\n", t);
            }
        }
    }

    public static int min(int[] lens) {
        int min = lens[0], max = lens[0];
        for(int i = 1; i < lens.length; i++) {
            if (lens[i] > max) max = lens[i];
            if (lens[i] < min) min = lens[i];
        }
        int result = Integer.MAX_VALUE;
        for(int len = min; len <= max; len++) {
            int actions = 0;
            for (int i = 0; i < lens.length; i++) {
                actions += Math.abs(lens[i] - len);
            }
            if(actions < result)
                result = actions;
        }
        return result;
    }

}
