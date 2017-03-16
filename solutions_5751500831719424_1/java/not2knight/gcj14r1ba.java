import java.io.File;
import java.io.PrintWriter;
import java.util.Locale;
import java.util.Scanner;

public class gcj14r1ba {
    public static void main(String[] args) {
        try {
            new gcj14r1ba().solve();
        } catch (Exception e) {
            e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
        }
    }

    void solve() throws Exception {
        Locale.setDefault(Locale.US);

//        String fn = "E:\\isinev\\develop\\contests\\training\\spoj\\work\\a.in";
        String fn = "E:\\isinev\\download\\A-large.in";

        File fin = new File(fn + ".res");
        PrintWriter pw = new PrintWriter(fin);
        Scanner sc = new Scanner(new File(fn));

        int tc = sc.nextInt();

        for (int tci = 1; tci <= tc; tci++) {
            pw.format("Case #%d: %s%n", tci, solve1(sc));
            pw.flush();
        }
        pw.close();
    }

    private String solve1(Scanner sc) {
        int n = sc.nextInt();

        String fwon = "Fegla Won";
        int res = 0;
        char[][] sl = new char[n][];
        for (int i = 0; i < n; i++) {
            sl[i] = sc.next().toCharArray();
        }
        int[] ia = new int[n];
        for (int i = 0; i < n; i++) {
            ia[i] = 0;
        }

        while (true) {
            char fc = '0';
            int[] cs = new int[n];
            int mcs = 0;
            boolean onlyz = false;
            for (int i = 0; i < n; i++) {
                if (ia[i] >= sl[i].length) {
                    if (fc != '0') {
                        return fwon;
                    } else {
                        onlyz = true;
                    }
                } else {
                    if (onlyz) {
                        return fwon;
                    }
                    if (fc == '0') {
                        fc = sl[i][ia[i]];
                    } else if (fc != sl[i][ia[i]]) {
                        return fwon;
                    }
                    while (ia[i] + 1 < sl[i].length && sl[i][ia[i]] == sl[i][ia[i] + 1]) {
                        ia[i]++;
                        cs[i]++;
                    }
                    if (mcs < cs[i]) {
                        mcs = cs[i];
                    }
                }
            }
            if (fc == '0') {
                return String.valueOf(res);
            }

            int mr = mcs * n;
            for (int tv = 0; tv <= mcs; tv++) {
                int cr = 0;
                for (int i = 0; i < n; i++) {
                    cr += Math.abs(cs[i] - tv);
                }
                if (mr > cr) {
                    mr = cr;
                }
            }
            res += mr;
            for (int i = 0; i < n; i++) {
                ia[i]++;
            }
        }
    }
}