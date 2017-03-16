package p1;

import java.io.File;
import java.util.Scanner;

public class MushroomMaster {

    private int n;
    private int m[];

    public MushroomMaster(Scanner sr) {
        n = sr.nextInt();
        m = new int[n];
        for (int i = 0; i < n; ++i) {
            m[i] = sr.nextInt();
        }
    }

    public int solve() {
        int ans[] = new int[2];
        int maxDiff = 0;
        ans[0] = 0;
        for (int i = 1; i < m.length; ++i) {
            if (m[i] < m[i - 1]) {
                ans[0] += m[i - 1] - m[i];
                maxDiff = (maxDiff < m[i - 1] - m[i]) ? m[i - 1] - m[i] : maxDiff;
            }
        }
        ans[1] = 0;
        for (int i = 0; i < m.length - 1; ++i) {
            ans[1] += (maxDiff > m[i]) ? m[i] : maxDiff;
        }
        System.out.println(ans[0] + " " + ans[1]);
        return n;
    }

    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File("src/p1/input1.txt"));
            int cases = Integer.valueOf(sc.nextLine());
            for (int c = 0; c < cases; c++) {
                System.out.print("Case #" + (c + 1) + ": ");
                new MushroomMaster(sc).solve();
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}