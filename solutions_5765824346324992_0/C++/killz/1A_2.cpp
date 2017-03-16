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
freopen("B-small-attempt1 (1).in", "r", stdin);
//freopen("B-samll.txt", "w", stdout);
int a, b, c, d;
int T;
cin >> T;
REPI(i, T){
    cin >> N >> M;
    while(!Q.empty())Q.pop();
    ll lcd = 1;
    REPI(a, N){
        Q.push({0, a});
        scanf("%d", &s[a]);
        lcd = s[a]*lcd/__gcd((ll)s[a], lcd);
    }
    ll tmp=0;
    REPI(a, N){
        tmp += lcd/s[a];
    }
//    dump(tmp);
    M %= tmp;
    M += tmp;
    for(a=0;a<M-1;a++){
        pii t = Q.top();
        Q.pop();
        Q.push({t.fi+s[t.se], t.se});
    }
    printf("Case #%d: ", i);
    cout << Q.top().se << "\n";
}


return 0;
}
