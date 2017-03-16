import java.io.PrintWriter;
import java.util.*;
import java.util.stream.Collectors;


public class A {
    static PrintWriter pw;
    static Scanner sc;

    public static void main(String[] args) {
        pw = new PrintWriter(System.out);
        sc = new Scanner(System.in);

        new A().run();
        pw.flush();
    }

    private void run() {
        int T = sc.nextInt();
        for (int t = 0; t < T; ++t) {
            System.err.printf("Case %d of %d\n", t + 1, T);
            pw.printf("Case #%d: %s\n", t + 1, nextCase(t));
        }
    }

    int argmax(int[] arr) {
        int idx = 0;
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] > arr[idx]) {
                idx = i;
            }
        }
        return idx;
    }

    int sum(int[] arr) {
        int ans = 0;
        for (int i = 0; i < arr.length; ++i) {
            ans += arr[i];
        }
        return ans;
    }

    int qty(int[] arr) {
        int ans = 0;
        for (int i = 0; i < arr.length; ++i) {
            if (arr[i] > 0) {
                ans++;
            }
        }
        return ans;
    }

    private String nextCase(int caseNum) {
        int n = sc.nextInt();
        int[] P = new int[n];
        for (int i = 0; i < n; ++i) {
            P[i] = sc.nextInt();
        }
        StringBuilder ans = new StringBuilder();
        while (true) {
            int idx = argmax(P);
            int S = sum(P);
            int q = qty(P);
            if (q == 0) {
                break;
            }
            if (q == 2 && P[idx] * 2 == S) {
                P[idx]--;
                int idx2 = argmax(P);
                P[idx2]--;
                ans.append("" + (char)(idx + 'A') + (char)(idx2 + 'A'));
            } else {
                ans.append((char)(idx + 'A'));
                P[idx]--;
            }
            ans.append(' ');
        }
        return ans.toString();
    }
}