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

int N, T;
int m[1005];

void solve_case(int i) {
    cout << "Case #" << i << ": ";
    cin >> N;
    int maxd = 0;
    int ans1 = 0;
    int ans2 = 0;
    for (int i=0; i < N; i++) {
        cin >> m[i];
        if (i > 0) {
            if (m[i] < m[i-1]) {
                ans1 += m[i-1] - m[i];
                if (m[i-1] - m[i] > maxd) {
                    maxd = m[i - 1] - m[i];
                }
            }
        }
    }
    for (int i=0; i < N - 1; i++) {
        ans2 += min(m[i], maxd);
    }
    cout << ans1 << " " << ans2 << "\n";
}
int main(){
    cin >> T;
    for (int i=1; i <= T; ++i) solve_case(i);
    return 0;
}
