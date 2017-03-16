#pragma  comment(linker, "/STACK:36777216")
#include <bits/stdc++.h>
#define  lc(x) (x << 1)
#define  rc(x) (lc(x) + 1)
#define  lowbit(x) (x & (-x))
#define  PI    (acos(-1))
#define  lowbit(x) (x & (-x))
#define  LL    long long
#define  DB    double
#define  ULL   unsigned long long
#define  PII   pair<int, int>
#define  PLL   pair<LL, LL>
#define  PB    push_back
#define  MP    make_pair

using namespace std;

const int N = 2005;
const int M = N * N * 2;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const DB  EPS = 1e-8;

int T, cas;

int n, a[N];

int main(){
//    freopen("in.txt", "r", stdin);
    freopen("A-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> T;
    while (T --) {
        cin >> n;
        for (int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
        }
        int res1 = 0, res2 = 0, mx = 0;
        for (int i = 0; i < n - 1; i ++) {
            if (a[i] > a[i + 1]) {
                res1 += (a[i] - a[i + 1]);
                mx = max(mx, a[i] - a[i + 1]);
            }
        }
        for (int i = 0; i < n - 1; i ++) {
            res2 += min(mx, a[i]);
        }
        printf("Case #%d: %d %d\n", ++ cas, res1, res2);
    }
}
