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

int main(){
    freopen("A-large (1).in", "r", stdin);
    freopen("A.txt", "w", stdout);
int a, b, c, d;
int T;
cin >> T;
REPI(i, T){
    cin >> N;
    ll TA=0, TB=0;
    REP(a, N) cin >> s[a];
    REPI(a, N-1){
        if(s[a] < s[a-1]) TA += s[a-1]-s[a];
    }
    int mx = 0;
    REPI(a, N-1){
        if(s[a] < s[a-1]) mx = max(mx, s[a-1]-s[a]);
    }
    REP(a, N-1){
        TB += min(s[a], mx);
    }
    printf("Case #%d: %lld %lld\n", i, TA, TB);
}


return 0;
}
