import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.Scanner;


public class B {

    public static void main(String[] args) throws FileNotFoundException {
        System.setIn(new FileInputStream(new File("B_small.in")));
        System.setOut(new PrintStream(new FileOutputStream(new File("B_small.out"))));
        Scanner in = new Scanner(System.in);

        int T = in.nextInt();
        for (int t = 1; t<=T;t++) {
            if (t == 4) {
                int x = 0;
                x++;
            }
            System.err.println(t);
            int B = in.nextInt();
            int N = in.nextInt();
            long[] M = new long[B];
            for (int i = 0; i < B; i++) {
                M[i] = in.nextLong();
            }
            int ans = 0;
            if (B == 1){
                ans = 1;
            } else if (B >= N) {
                ans = N;
            } else {
                long c;
                long l = 0;
                long r = 1L << 55L;
                long serviced;
                long servicedThisMin;
                while (true) {
                    c = (l + r) / 2;
                    serviced = 0;
                    servicedThisMin = 0;
                    for (int i = 0; i < B; i++) {
                        serviced += c / M[i];
                        serviced += 1;
                        if (c % M[i] == 0) {
                            servicedThisMin++;
                        }
                    }
                    if (serviced >= N && serviced - servicedThisMin < N) {
                        break;
                    }
                    if (serviced == N) {
                        r = c - 1;
                    }
                    if (serviced < N) {
                        l = c + 1;
                    }
                    if (serviced > N) {
                        r = c - 1;
                    }
                }
                long n = serviced;
                n -= servicedThisMin;
                int k = -1;
                for (int i = 0; i < B && n < N; i++) {
                    if (c % M[i] == 0){
                        n++;
                        if (n == N) {
                            k = i+1;
                        }
                    }
                }
                ans = k;
            }
            System.out.printf("Case #%d: %d", t, ans);
            System.out.println();
        }
    }
}
