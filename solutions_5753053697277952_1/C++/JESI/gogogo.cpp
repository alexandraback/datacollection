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

#define SZ 100010


int main() {
//    #if defined JESI
        freopen("A-large.in", "r", stdin);
        freopen("2.txt", "w", stdout);
//    #endif

    int t;
    cin >> t;

    for (int cs = 0; cs < t; cs++) {
        int n;
        cin >> n;

        int mn = 100000, mx = -1;

        vector <int> a(n);
        for (int &x: a) {
            cin >> x;
            mn = min(mn, x);
            mx = max(mx, x);
        }

        cout << "Case #" << cs + 1 << ":";

        while (true) {
            bool flag = false;
            int indx = -1, best = -1;
            for (int i = 0; i < n; i++) {
                if (a[i] > mn && a[i] > best) {
                    best = a[i];
                    flag = true;
                    indx = i;
                }
            }
            if (!flag) break;
            a[indx]--;
            cout << ' ' << (char)(indx + 'A');
        }

        while (true) {
            bool flag = false;
            int indx = -1, best = -1;
            for (int i = 2; i < n; i++) {
                if (a[i] > 0) {
                    best = a[i];
                    flag = true;
                    indx = i;
                }
            }
            if (!flag) break;
            a[indx]--;
            cout << ' ' << (char)(indx + 'A');
        }

        while (a[0] > 0) {
            a[0]--;
            cout << " AB";
        }

        cout << endl;
    }


    return 0;
}






