//package denxx;

import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	    Scanner stdin = new Scanner(System.in);
        int T = stdin.nextInt();
        for (int t = 1; t <= T; ++t) {
            int n = stdin.nextInt();
            String[] str = new String[n];
            for (int i = 0; i < n; ++i) {
                str[i] = stdin.next();
            }

            int[] pos = new int[n];

            int res = 0;

            boolean fail = false;
            while (pos[0] < str[0].length()) {
                char ch = str[0].charAt(pos[0]);
                int[] count = new int[n];
                for (int i = 0; i < n; ++i) {
                    while (pos[i] < str[i].length() && str[i].charAt(pos[i]) == ch) {
                        ++pos[i];
                        ++count[i];
                    }
                }
                Arrays.sort(count);
                if (count[0] == 0) {
                    fail = true;
                    break;
                }
                int median = count[count.length / 2];
                for (int i = 0; i < n; ++i) {
                    res += Math.abs(median - count[i]);
                }
            }
            for (int i = 0; i < n; ++i) {
                if (pos[i] < str[i].length()) {
                    fail = true;
                }
            }
            if (fail) {
                System.out.println("Case #" + t + ": Fegla Won");
            } else {
                System.out.println("Case #" + t + ": " + res);
            }
        }
    }
}
