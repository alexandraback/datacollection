#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 1005;
const ll INF = 1e15;

int n, m, ar[MAXN];

ll calc(ll mid) {
    if (mid == 0) return 0;
    ll ret = 0;
    for (int i=0; i<n; i++) ret += (mid-1)/ar[i]+1;
    return ret;
}

void go(int casenum) {
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> ar[i];
    ll lo = 0, hi = INF;
    while (lo < hi) {
        ll mid = (lo + hi + 1) / 2;
        if (calc(mid) < m) lo = mid;
        else hi = mid-1;
    }

    ll k = m-calc(lo);
    for (int i=0; i<n; i++)
        if (lo%ar[i] == 0) {
            k--;
            if (k == 0) {
                printf("Case #%d: %d\n", casenum, i+1);
                return;
            }
        }
    assert(0);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t; cin >> t;
    for (int i=1; i<=t; i++) go(i);
}
