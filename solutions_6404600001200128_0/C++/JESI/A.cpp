#include <bits/stdc++.h>

using namespace  std;

using ll = long long;

#define clr(a) (a.clear())
#define MP(a,b) make_pair(a,b)
#define sz(x) (int)x.size()
#define mem(a,b) memset(a, b, sizeof(a))
#define Unique(store) store.resize(unique(store.begin(),store.end())-store.begin())
#define pb push_back
#define FAST ios_base::sync_with_stdio(0);cin.tie(0);

#define X first
#define Y second

using pii = pair <int , int>;
using pll = pair <ll , ll>;
const ll inf = 1;
const ll mod = 1E9;

#define SZ 1000+10

int a[SZ];

int main() {
    #if defined JESI
        freopen("1.txt", "r", stdin);
        freopen("2.txt", "w", stdout);
    #endif

    int t;
    scanf("%d", &t);

    for (int cs = 0; cs < t; cs++) {
        int n;
        scanf("%d", &n);

        int ans1 = 0, ans2 = 0;
        int dif = 0;

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (i) {
                if (a[i] < a[i-1]) {
                    ans1 += a[i-1] - a[i];
                }
                dif = max(dif, a[i-1] - a[i]);
            }
        }

        for (int i = 0; i < n - 1; i++) {
            ans2 += min(a[i], dif);
        }

        printf("Case #%d: %d %d\n", cs + 1, ans1, ans2);
    }


    return 0;
}







