import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        String line = stdin.readLine();
        int T = Integer.parseInt(line);
        
        for (int t = 1; t <= T; t++) {
            line = stdin.readLine();
            String[] prms = line.split(" ");
            int R = Integer.parseInt(prms[0]);
            int C = Integer.parseInt(prms[1]);
            int N = Integer.parseInt(prms[2]);
            
            int ans = (R-1)*C+R*(C-1);
            int v = 1 << R*C;
            for (int i = 0; i < v; i++) {
                int bc = Integer.bitCount(i);
                if (bc == N) {
                    int val = 0;
                    for (int r = 0; r < R; r++) {
                        boolean o = false;
                        int m = 1 << r*C;
                        for (int c = 0; c < C; c++) {
                            if ((i&m) != 0) {
                                if (o) val++;
                                o = true;
                                if ((i&(m<<C)) != 0) {
                                    val++;
                                }
                            } else {
                                o = false;
                            }
                            m <<= 1;
                        }
                    }
                    ans = Math.min(ans, val);
                }
            }
            
            System.out.printf("Case #%d: %d\n", t, ans);
        }
    }
}
