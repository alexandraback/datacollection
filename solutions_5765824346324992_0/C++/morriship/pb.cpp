#include<bits/stdc++.h>
#define two(a) (1<<(a))
#define LINF (1ll<<61)
#define EPS (1e-14)
#define Lshift(a,b) (a<<b)
#define Rshift(a,b) (a>>b)
#define rep(a,b) for(a=0 ; a<b ; a++)
#define xrep(a,b,c) for(a=b ; a<c ; a++)
#define INF (1<<29)
#define swap(a,b) ( (a^=b) , (b^=a) , (a^=b) )
typedef long long ll;
using namespace std;

ll m[100011];
int n;
int b;

int check(ll now) {
    int i;
    ll count(0);
    rep(i, b) { count += now / m[i] + 1; }
    if (count >= n) { return 1; }
    return 0;
}

int get(ll now) {
    int i, count(0);
    rep(i, b) { count += now / m[i] + (now % m[i] != 0); }
//  cout << count << endl;
    rep(i, b) {
        if (now % m[i] == 0) {
            count++;
//            cout << "count: " << count << endl;
            if (count == n) {
//                cout << i << ' ' << b << endl;
                return i;
            }
        }
    }
}

int bs(ll st, ll ed) {
    ll mi;
    while (st < ed) {
        mi = (st+ed)/2;
        if (check(mi)) { ed = mi; }
        else { st = mi+1; }
    }
//    cout << "st: " << st << endl;
    return get(st);
}

int main() {
    ll ed;
    int i, j, k, t, tt;
    cin >> tt;
    xrep(t, 1, tt+1) {
        cin >> b >> n;
        rep(i, b) {
            scanf("%lld", &m[i]);
            ed = max(m[i], ed);
        }
        cout << "Case #" << t << ": " << bs(0, ed*n+1)+1 << endl;
    }
}
