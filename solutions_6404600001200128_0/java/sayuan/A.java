import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.util.*;
import java.util.regex.*;
import static java.lang.Math.*;
import static java.lang.System.*;
public class A {

    void solve(int caseNum) {
        int n = in.nextInt();
        int[] m = new int[n];
        for (int i=0; i<n; i++) m[i] = in.nextInt();

        int y = 0;
        for (int i=1; i<n; i++) y += max(m[i-1]-m[i], 0);
        int z = 0;

        int e = -1;
        for (int i=n-2; i>=0; i--) {
            if (m[i] > m[i+1]) {
                e = i+1;
                break;
            }
        }

        // debug(e);

        if (e!=-1) {
            for (int i=0; i<e; i++) z += m[i];
            if (n>1 && m[e]>=m[n-1]) z -= m[n-1];
        }


        // for (int i=0; i<n-1; i++) z += m[i];
        // if (n>1 && m[n-2]>=m[n-1]) z -= m[n-1];

        out.println(y+" "+z);
    }

    // {{{
    Scanner in = new Scanner(System.in);
    public A() throws Exception {
        int caseCount = in.nextInt();
        for (int caseNum=1; caseNum<=caseCount; caseNum++) {
            out.printf("Case #%d: ", caseNum);
            solve(caseNum);
        }
    }
    public static void main(String[] args) throws Exception {
        new A();
    }
    public static void debug(Object... arr) {
        System.err.println(Arrays.deepToString(arr));
    }
    // }}}
}
