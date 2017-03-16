import java.io.*;
import java.util.*;
import java.math.*;

public class A {
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
            int A[] = new int[N];
            for (int i = 0; i < N; i++) {
                A[i] = scanner.nextInt();
            }

            int X = 0;
            for (int i = 0; i < N-1; i++) {
                if (A[i] > A[i+1]) {
                    X += A[i]-A[i+1];
                }
            }

            int Y = 0;
            int rate = 0;
            for (int i = 0; i < N-1; i++) {
                if (A[i] > A[i+1]) {
                    if (A[i]-A[i+1] > rate) {
                        rate = A[i]-A[i+1];
                    }
                }
            }
            //int r = (rate / 10) + (rate % 10 == 0 ? 0 : 1);
            for (int i = 0; i < N-1; i++) {
                if (A[i] <= rate) {
                    Y += A[i];
                }
                else {
                    Y += rate;
                }
            }

            System.out.println("Case #" + t + ": " + X + " " + Y);
        }
    }
}
