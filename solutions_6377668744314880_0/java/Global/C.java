import java.io.*;
import java.util.*;
import java.math.*;

public class C {
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
            long A[][] = new long[N][2];
            for (int i = 0; i < N; i++) {
                A[i][0] = scanner.nextLong();
                A[i][1] = scanner.nextLong();
            }

            System.out.println("Case #" + t + ":");
            for (int i = 0; i < N; i++) {
                int minCutDown = 9999;
                for (int j = 0; j < N; j++) {
                    if ((A[i][0] != A[j][0] || A[i][1] != A[j][1])) {
                        int numPos = 0, numNeg = 0;
                        for (int k = 0; k < N; k++) {
                            if ((A[i][0] != A[j][0] || A[i][1] != A[j][1]) &&
                                (A[i][0] != A[k][0] || A[i][1] != A[k][1]))  {
                                
                                long sign = checkSign(A[i], A[j], A[k]);
                                //System.out.println(i + " " + j + " " + k + ": " + sign);
                                if (sign < 0) {
                                    numNeg++;
                                }
                                else if (sign > 0) {
                                    numPos++;
                                }
                            }                            
                        }
                        //System.out.println("::::" + numPos + " " + numNeg);
                        int m = (numPos > numNeg) ? numNeg : numPos;
                        if (m < minCutDown) {
                            minCutDown = m;
                        }
                    }
                }
                if (minCutDown == 9999) minCutDown = 0;
                System.out.println(minCutDown);
            }
        }
    }

    public long checkSign(long[] A, long B[], long M[]) {
        return (B[0]-A[0])*(M[1]-A[1]) - (B[1]-A[1])*(M[0]-A[0]);
    }
}
