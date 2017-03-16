import java.io.*;
import java.util.*;
import java.math.*;

public class B {
    public static void main(String[] args) { 
        PrintWriter out = new PrintWriter(System.out);

        Application application = new Application();
        application.solve(System.in, out);

        out.close();
    }
}


class Application {
    public void solve(InputStream in, PrintWriter out) {
        Scanner scanner = new Scanner(in);

        int T = scanner.nextInt();
        for (int t = 1; t <= T; t++) {
            int N = scanner.nextInt();
            long K = scanner.nextLong();
            int A[] = new int[N];
            for (int i = 0; i < N; i++) {
                A[i] = scanner.nextInt();
            }

            long L = 0;
            long R = (long) 1e18;
            while (L < R) {
                long M = (L+R)/2;
                long numServe = calcNumServe(A, N, M);
                if (numServe < K) {
                    L = M+1;
                }
                else {
                    R = M;
                }
            }

            //System.out.println("Case #" + t + ":" );

            long p = calcNumServe(A, N, L) - K;
            //System.out.println(L + " " + p);
            int ans = 0;
            for (int i = N-1; i >= 0; i--) {
                if (L % A[i] == 0) {
                    p--;
                    if (p < 0) {
                        ans = i+1;
                        break;
                    }
                }
            }
            System.out.println("Case #" + t + ": " + ans);
        }
    }

    public long calcNumServe(int A[], int N, long T) {
        long numServe = 0;
        for (int i = 0; i < N; i++) {
            numServe += (T / A[i])+1;
        }
        return numServe;
    }
}
