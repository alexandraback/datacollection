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

int T, cas, n, m, a[N];

LL Gao(LL x) {
    LL ret = 0;
    for (int i = 0; i < m; i ++) {
        ret += x / a[i] + 1;
    }
    return ret;
}

int main(){
//    freopen("in.txt", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    cin >> T;
    while (T --) {
        cin >> m >> n;
        for (int i = 0; i < m; i ++) {
             scanf("%d", &a[i]);
        }
        LL l = 0, r = 1e15 + 7;
        while (l < r) {
            LL mid = (l + r) / 2;
//            cout << mid << ' ' << Gao(mid) << endl;
            if (Gao(mid) >= n) r = mid;
            else l = mid + 1;
        }
        for (int i = 0; i < m; i ++) {
            n -= (1 + (l - 1) / a[i]);
        }
//        cout << l << ' ' << n << endl;
        int res = -1;
        for (int i = 0; i < m; i ++) {
            if (l % a[i] == 0) {
                n --;
                if (n == 0) {
                    res = i + 1;
                    break;
                }
            }
        }
//        cout << l << endl;
        printf("Case #%d: %d\n", ++ cas, res);
    }
}
