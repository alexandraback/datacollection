#define fi first
#define se second
#define REP(_x, _y) for(_x=0;_x<_y;_x++)
#define REPI(_x, _y) for(_x=1;_x<=_y;_x++)
#define ALL(x) (x).begin(),(x).end()
#define compress(x) {sort(ALL(x));(x).resize(distance((x).begin, unique(ALL(x))));}
#define pb push_back
#define mp make_pair
#define EL printf("\n");
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define IT iterator
#define foreach(it,x) for(__typeof(x.begin())it=x.begin();it!=x.end();it++)
#define dump(x) cerr<<#x<<"="<<x<<"\n"
#define sz(_x) (int)_x.size()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;

int i, n, k, N, M, K;

int s[100010];

priority_queue<pii, vector<pii>, greater<pii> > Q;

int main(){
freopen("B-large (1).in", "r", stdin);
freopen("B-l.txt", "w", stdout);
int a, b, c, d;
int T;
cin >> T;
REPI(i, T){
    cin >> N >> M;
    REPI(a, N){
        scanf("%d", &s[a]);
    }
    ll lo = 0, hi = 1e14+10, mi, sm;
    while(lo < hi){
        mi = (lo)+(hi-lo+1)/2;
        sm = 0;
        REPI(a, N){
            sm += ceil(mi/(double)s[a]);
        }
        if(sm >= M){
            hi = mi-1;
        }
        else {
            lo = mi;
        }
    }
    sm = 0;
    REPI(a, N){
        sm += ceil(lo/(double)s[a]);
    }
    vector<pair<ll, int> > ans;
    ll tt;
    REPI(a, N){
        if(lo % s[a] == 0) tt = lo;
        else tt = lo + s[a] - lo % s[a];
        ans.pb({tt, a});
    }
    sort(ALL(ans));
    dump(sm);
    dump(lo);
    printf("Case #%d: ", i);
    cout << ans[M-sm-1].se << "\n";
}


return 0;
}
