#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair <int, int> PII;
const int N = 1005;
const ll INF = 1LL << 60;
int Tc, n;
int a[N];

int main() {
    scanf("%d", &Tc);
    rep (ri, Tc) {
        scanf("%d", &n);
        rep (i, n) scanf("%d", &a[i]);
        printf("Case #%d: ", ri + 1);
        ll lhs = 0, rhs = INF;
        rep (i, n - 1) {
            if (a[i + 1] < a[i]) {
                lhs += a[i] - a[i + 1];
            }
        }
        rep (eatRate, 10005) {
            ll cur = 0;
            rep (i, n - 1) {
                ll eat = min(a[i], eatRate);
                cur += eat;
                if (a[i] - eat > a[i + 1]) {
                    cur = -1;
                    break;
                }
            }
            if (cur >= 0) {
                rhs = min(rhs, cur);
            }
        }
        cout << lhs << " " << rhs << endl;
    }
}

