#include<bits/stdc++.h>
#define mp make_pair
#define esp 1e-18
#define lson   l, m, rt<<1
#define rson   m+1, r, rt<<1|1
#define sz(x) ((int)((x).size()))
#define lowbit(x) ((x)&(-(x)))
#define pf(x) ((x)*(x))
#define pb push_back
#define pi acos(-1.0)
#define in freopen("B-small-attempt1.in", "r", stdin);
#define out freopen("solve_out.txt", "w", stdout);
#define IN freopen("solve_in.txt", "r", stdin);
#define OUT freopen("solve_out.txt", "w", stdout);
#define bug(x) cout << "Line : " << (x) << endl;
#define TL cerr << "Time elapsed: " << (double)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define inf 0x0f0f0f0f
using namespace std;


typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned US;
typedef pair<int, int> PII;
typedef map<PII, int> MPS;
typedef MPS::iterator IT;
const int maxn = (int)1e4 + 2;

bitset<maxn> maze[2][maxn];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int n,m;
bool cango(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}
int cnt[2][4];
int main() {
//    in
//    out
//    IN
    int T;
    for (int t = scanf("%d", &T); t <= T; t++) {
        int c;
        scanf("%d%d%d", &n, &m, &c);
//        cout << n << ' ' << m << ' ' << c << ' ';
        int ans = (int)1e9;
        if (n == 1 || m == 1) {
            n = max(n, m);
            if (n-c >= c) {
                ans = 0;
            } else {
                ans = c - (n-c) - 1;
            }
        }  else {
            memset(cnt, 0, sizeof cnt);

            for (int k = 0; k < 2; k++) {
                for (int i = 0; i < n; i++) {
                    maze[k][i].reset();
                    for (int j = (i&1)^k; j < m; j += 2) {
                        maze[k][i][j] = 1;
                        cnt[k][0]++;
                    }
                }
                for (int i = 0; i < n; i++)
                    for (int j = 0; j < m; j++) {
                        if (maze[k][i][j]) continue;
                        int cc = 0;
                        for (int kk = 0; kk < 4; kk++) {
                            int x = i+dx[kk];
                            int y = j+dy[kk];
                            if (!cango(x, y)) continue;
                            cc++;
                        }
                        if (cc > 1)
                            cnt[k][cc-1]++;
                    }
//                puts("");
            }
            if (cnt[0][0] >= c || cnt[1][0] >= c) {
                ans = 0;
            } else {

                for (int k = 0; k < 2; k++) {
                    int cc = c;
                    int tmp = 0;
                    for (int kk = 0; kk < 4 && cc > 0; kk++) {
                        tmp += min(cc, cnt[k][kk]) * (kk ? kk+1 : 0);
                        cc -= min(cc, cnt[k][kk]);
                    }
                    ans = min(ans, tmp);
                }
            }
        }

        printf("Case #%d: %d\n", t, ans);
    }
}
