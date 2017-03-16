package round1b;

import java.util.Scanner;

/**
 * Created by tomas on 03.05.14.
 */
public class A {

    public static void main(String[] argv) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 1; i <= T; i++) {
            int N = sc.nextInt();
            sc.nextLine();
            String[] str = new String[N];
            for (int j = 0; j < N; j++) {
                str[j] = sc.nextLine();
            }

            int l0 = str[0].length() + 1;
            int l1 = str[1].length() + 1;
            int[][] A = new int[l0][l1];
            for (int j = 1; j < l0; j++) {
                A[j][0] = -1;
            }
            for (int j = 1; j < l1; j++) {
                A[0][j] = -1;
            }
            A[0][0] = 0;
            for (int j = 1; j < l0; j++) {
                for (int k = 1; k < l1; k++) {
                    if (str[0].charAt(j-1) == str[1].charAt(k-1)) {
                        A[j][k] = A[j-1][k-1];
                        if (k > 1 && str[0].charAt(j-1) == str[1].charAt(k-2)) {
                            A[j][k] = res(A[j][k], add(A[j][k-1]));
                        }
                        if (j > 1 && str[0].charAt(j-2) == str[1].charAt(k-1)) {
                            A[j][k] = res(A[j][k], add(A[j-1][k]));
                        }
                    } else {
                        A[j][k] = -1;
                    }
                }
            }

            System.out.println("Case #" + i + ": " + (A[l0-1][l1-1] == -1 ? "Fegla Won" : A[l0-1][l1-1]));
        }
    }

    private static int res(int a, int b) {
        if (a == -1) {
            return b;
        }
        if (b == -1) {
            return a;
        }
        return Math.min(a,b);
    }

    private static int add(int a) {
        if (a == -1) {
            return -1;
        }
        return a + 1;
    }
}
