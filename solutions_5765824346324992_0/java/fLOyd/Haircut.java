package p2;

import java.io.File;
import java.util.Scanner;

public class Haircut {
    private int n;
    private int b;
    private int m[];
    private int num[];
    private int loop = 0;
    private int mul = 1;

    public Haircut(Scanner sr) {
        b = sr.nextInt();
        n = sr.nextInt();
        m = new int[b];
        for (int i = 0; i < b; ++i) {
            m[i] = sr.nextInt();
            mul = mul * m[i];
        }
        for (int i = 0; i < b; ++i) {
            loop += mul / m[i];
        }
        num = new int[loop + b];

    }

    private int minid(int[] arr) {
        int result = - 1, id = -1;
        for (int i = 0; i < arr.length; ++i) {
            if (result == - 1 || result > arr[i]) {
                result = arr[i];
                id = i;
            }
        }
        return id;
    }

    public int solve() {
        int time[] = new int[b];
        for (int i = 0; i < b; ++i) {
            time[i] = m[i];
            num[i] = i;
        }
        for (int i = b; i < b + loop; ++i) {
            int current = minid(time);
            num[i] = current;
            time[current] += m[current];
        }
        return num[(n-1) % loop] + 1;
    }

    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(new File("src/p2/input1.txt"));
            int cases = Integer.valueOf(sc.nextLine());
            for (int c = 0; c < cases; c++) {
                System.out.println("Case #" + (c + 1) + ": " + new Haircut(sc).solve());
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}