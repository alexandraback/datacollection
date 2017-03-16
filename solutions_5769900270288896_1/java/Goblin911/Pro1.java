import java.util.*;
import java.io.*;

public class Pro1 {

    static Scanner cin = new Scanner(System.in);
    static PrintStream cout = System.out;

    int n, m, k;
    int ans;

    boolean[][] a;

    int calc() {
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i > 0 && a[i][j] && a[i - 1][j])
                    res++;
                if (j > 0 && a[i][j] && a[i][j - 1])
                    res++;
            }
        }
        return res;
    }

    void dfs(int x, int y, int z) {
        if (z == k) {
            ans = Math.min(ans, calc());
        } else {
            if (x == n)
                return;
            a[x][y] = true;
            if (y + 1 < m) {
                dfs(x, y + 1, z + 1);
            } else {
                dfs(x + 1, 0, z + 1);
            }
            a[x][y] = false;
            if (y + 1 < m) {
                dfs(x, y + 1, z);
            } else {
                dfs(x + 1, 0, z);
            }
        }
    }

    void solve() {
        n = cin.nextInt();
        m = cin.nextInt();
        k = cin.nextInt();
        a = new boolean[n][m];
        ans = Integer.MAX_VALUE;
        dfs(0, 0, 0);
        cout.println(ans);

    }

    void init() {
        n = cin.nextInt();
        m = cin.nextInt();
        k = cin.nextInt();
        ans = 0;
        int sum = 0;
        if (n % 2 == 0) {
            int t = n;
            n = m;
            m = t;
        }

        if (n == 1 || m == 1) {
            int t = n == 1 ? m : n;
            if (t % 2 == 0) {
                sum += t / 2;
                if (sum >= k) {
                    cout.println(0);
                    return;
                } else {
                    sum++;
                    if (sum >= k) {
                        cout.println(1);
                        return;
                    } else {
                        cout.println((k - sum) * 2 + 1);
                        return;
                    }
                }
            } else {
                sum += t / 2 + 1;
                if (sum >= k) {
                    cout.println(0);
                    return;
                } else {
                    cout.println((k - sum) * 2);
                    return;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (m % 2 == 0)
                sum += m / 2;
            else if (i % 2 == 0)
                sum += (m + 1) / 2;
            else
                sum += m / 2;
        }
        if (sum >= k) {
            cout.println(0);
            return;
        }

        if (m % 2 == 0 || n % 2 == 0) {
            if (k - sum <= 2) {
                ans += 2 * (k - sum);
                cout.println(ans);
                return;
            } else {
                ans += 4;
                sum += 2;

                int ceil = m + n - 2 - 2;

                if (sum + ceil >= k) {
                    ans += 3 * (k - sum);
                    cout.println(ans);
                    return;
                } else {
                    ans += 3 * ceil + 4 * (k - sum - ceil);
                    cout.println(ans);
                    return;
                }
            }
        } else {
            
            int xx = ans;
            int ceil = (n - 1) + (m - 1);
            if (sum + ceil >= k) {
                xx += 3 * (k - sum);
//              cout.println(ans);
            } else {
                xx += 3 * ceil + 4 * (k - sum - ceil);
//              cout.println(ans);
//              return;
            }
            
            
            int yy = 0, s = 0;
            for (int i = 0; i < n; i++) {
                if (i % 2 == 1)
                    s += (m + 1) / 2;
                else
                    s += m / 2;
            }
            if (k - s <= 4) {
                yy += 2 * (k - s);
            } else {
                yy += 8;
                s += 4;
                ceil = (m - m / 2 - 2) * 2 + (n - n / 2 - 2) * 2;
                if (s + ceil >= k) {
                    yy += 3 * (k - s);
//                  cout.println(ans);
                } else {
                    yy += 3 * ceil + 4 * (k - s - ceil);
//                  cout.println(ans);
//                  return;
                }
            }
            
            cout.println(Math.min(xx, yy));
        }
    }

    Pro1() {
        int t = cin.nextInt();
        for (int i = 1; i <= t; i++) {
            cout.print("Case #" + i + ": ");
            init();
            // solve();
        }

    }

    public static void main(String[] args) {
        new Pro1();
    }

}
