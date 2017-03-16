#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),__tzg_##i=(b);i<__tzg_##i;++i)
#define urp(i,a,b) for(int i=(a),__tzg_##i=(b);i>=__tzg_##i;--i)
#define rp(i,b) rep(i,0,b)
#define repd(i,a,b) rep(i,a,(b)+1)
#define mst(a,b) memset(a,b,sizeof(a))
#define vrp(it,v) for(auto it(v.begin());(it)!=(v.end());++it)
#define vtr(v) (v).begin(),(v).end()
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define pb(a) push_back(a)
#define _0(x) (!(x))
#define _1(x) (x)
#define bit(x,y) (((x)>>(y))&1)
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;

int p[30];
PII k[30];
void opt(int a) {
    cout<<" "<<char(a+'A');
}
void solve() {
    int n, sum = 0;
    cin>>n;
    rp(i, n) cin>>p[i], sum += p[i];
    for (int f = 1; f ;) {
        f = 0;
        rp(i, n) if (p[i]) {
            int nsum = sum-1;
            int hf = 1+nsum/2;
            int ok = 1;
            rp(j,n) if (i!= j && p[j]) {
                if (p[j] >= hf) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                f = 1;
                p[i]--;
                sum--;
                cout<<" "<<char('A'+i);
            }
        }
    }
    VPII v;
    rp(i, n) if (p[i]) v.pb(mp(i, p[i]));
    int o = v[0].se;
    char a = 'A'+v[0].fi, b = 'A'+v[1].fi;
    rp(i, o) {
        cout<<" "<<a<<b;
    }
    cout<<endl;
}

int main() {
#ifdef _TZG_DEBUG
    freopen("A-large.in", "r", stdin);
    freopen("out_a.txt", "w", stdout);
#endif // _TZG_DEBUG
    int t;
    cin>>t;
    repd(_, 1, t) {
        printf("Case #%d:", _);
        solve();
    }
    return 0;
}
