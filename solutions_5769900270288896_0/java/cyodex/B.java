import java.util.*;
import java.io.*;

public class B {

    int INF = 1000000;
    public static void main(String[] args) throws FileNotFoundException {
        new B().solve();
    }

    public void solve() throws FileNotFoundException{
        //Scanner in = new Scanner(System.in);
        Scanner in = new Scanner(new File("b3.in"));
        PrintWriter out = new PrintWriter("b3.out");
        int t = Integer.parseInt(in.nextLine());
        for (int test = 1; test <= t; test++) {
            int r = Integer.parseInt(in.next());
            int c = Integer.parseInt(in.next());
            int n = Integer.parseInt(in.next());
            int ans = Math.min(get(r, c, n, true), get(r, c, n, false));
            //System.out.println("Case #" + test + ": " + ans);
            out.println("Case #" + test + ": " + ans);
        }

        out.close();
    }

    public int get(int r, int c, int n, boolean start) {
        if (n <= (r * c + 1) / 2) return 0;
        boolean[][] a = new boolean[r][c];
        for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            if ((i + j) % 2 == 0)
                a[i][j] = start;
            else
                a[i][j] = !start;
        }
        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        int soFar = start ? (r * c + 1) / 2 : (r * c) / 2;
        int ans = 0;
        while (soFar < n) {
            int minR = -1;
            int minC = -1;
            int min = INF;
            for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                if (a[i][j]) continue;
                int cnt = 0;
                for (int k = 0; k < 4; k++) {
                    int curR = i + dx[k];
                    int curC = j + dy[k];
                    if (curR < r && curR >= 0 && curC < c && curC >= 0 && a[curR][curC])
                        cnt++;
                }
                if (cnt < min) {
                    minR = i;
                    minC = j;
                    min = cnt;
                }
            }

            a[minR][minC] = true;
            soFar++;
            ans += min;
        }
        return ans;
    }
}