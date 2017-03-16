#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef stringstream ss;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define mset(t,v) memset((t),(v),sizeof(t))
#define print(a) cout << #a << ": " << a << endl;
#define print_arr(a,n) rep(_##i, n) cout << #a << "[" << _##i << "]: " << a[_##i] << endl

#define rep(i,n) for(int i=0,_##i=(n);i<_##i;++i)
#define repr(i,n) for(int i=(n);--i>=0;)
#define rep2(i,l,r) for(int i=(l),_##i=(r);i<_##i;++i)
#define repr2(i,l,r) for(int i=(r),_##i=(l);--i>=_##i;)

#define vt(args...) vector<tuple<args>>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define em emplace

long long N, B;
long long M[123456];

int barber(long long T) {
    long long maxt = -1;
    int ret = -1;

    long long people = 0;
    for (long long i=0; i < B; ++i) {
        long long tmpt = i + ((T - i) / M[i]) * M[i];
        people += (T - i) / M[i] + 1;
        if (tmpt > maxt) {
            maxt = tmpt;
            ret = i;
        }
    }
    if (people > N) {
        return -1;
    }
    return ret;
}

void solve_case(int t) {
    cout << "Case #" << t << ": ";
    cin >> B >> N;
    for (int i=0; i < B; i++){
        cin >> M[i];
        M[i] *= 1000;
    }
    long long lo = 0, hi = 2000000000000000000;
    while (lo < hi - 1) {
        long long mi = (lo + hi) >> 1;
        if (barber(mi) == -1) {
            hi = mi;
        } else {
            lo = mi;
        }
    }
    cout << barber(lo) + 1 << "\n";
}
int main(){
    /* %%% */
    int T;
    cin >> T;
    for (int i = 1; i <= T; ++i) solve_case(i);
    return 0;
}

