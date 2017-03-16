import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class B {

    void solve(int caseNum) {
        int b = in.nextInt();
        int n = in.nextInt();
        int[] m = new int[b];
        for (int i=0; i<b; i++) m[i] = in.nextInt();

        long lower = 0;
        long upper = 1L<<60;
        while (lower<upper) {
            long mid = (lower+upper)/2;

            long c = b;
            for (int i=0; i<b; i++) c += mid/m[i];
            if (c>=n)
                upper = mid;
            else
                lower = mid+1;
        }

        long c = 0;
        for (int i=0; i<b; i++) {
            c += (lower+m[i]-1)/m[i];
        }

        long ans = -1;
        for (int i=0; i<b; i++) {
            if (lower%m[i] != 0) continue;
            c++;
            if (c==n) {
                ans = i+1;
                break;
            }
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
