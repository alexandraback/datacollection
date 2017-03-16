import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class B {

    void solve(int caseNum) {
        int R = in.nextInt();
        int C = in.nextInt();
        int N = in.nextInt();

        int m = R*C;
        int ans = 1<<30;
        for (int i=0; i<(1<<m); i++) {
            boolean[][] map = new boolean[R+1][C+1];
            int d = Integer.bitCount(i);
            if (d!=N) continue;
            for (int j=0; j<m; j++) {
                if ((i&(1<<j))!=0) {
                    int r = j/C;
                    int c = j%C;
                    map[r][c] = true;
                }
            }
            int t = 0;
            for (int r=0; r<R; r++) {
                for (int c=0; c<C; c++) {
                    if (!map[r][c]) continue;
                    if (map[r+1][c]) t++;
                    if (map[r][c+1]) t++;
                }
            }
            ans = min(ans, t);
        }
        out.println(ans);
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public B() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);
            solve(caseNum);
        }
    }
    public static void main(String[] args) throws Exception {
        new B();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
