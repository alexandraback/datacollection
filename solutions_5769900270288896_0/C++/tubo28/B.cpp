#define _CRT_SECURE_NO_WARNINGS
//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
//#define int ll
//#define endl "\n"
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
#define all(c) (c).begin(), (c).end()
#define loop(i,a,b) for(ll i=a; i<ll(b); i++)
#define rep(i,b) loop(i,0,b)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
template<class T> ostream & operator<<(ostream & os, vector<T> const &);
template<int n, class...T> typename enable_if<(n>=sizeof...(T))>::type _ot(ostream &, tuple<T...> const &){}
template<int n, class...T> typename enable_if<(n< sizeof...(T))>::type _ot(ostream & os, tuple<T...> const & t){ os << (n==0?"":" ") << get<n>(t); _ot<n+1>(os, t); }
template<class...T> ostream & operator<<(ostream & os, tuple<T...> const & t){ _ot<0>(os, t); return os; }
template<class T, class U> ostream & operator<<(ostream & os, pair<T,U> const & p){ return os << "(" << p.first << ", " << p.second << ") "; }
template<class T> ostream & operator<<(ostream & os, vector<T> const & v){ rep(i,v.size()) os << v[i] << (i+1==(int)v.size()?"":" "); return os; }
template<class T> inline bool chmax(T & x, T const & y){ return x<y ? x=y,true : false; }
template<class T> inline bool chmin(T & x, T const & y){ return x>y ? x=y,true : false; }
#ifdef DEBUG
#define dump(...) (cerr<<#__VA_ARGS__<<" = "<<mt(__VA_ARGS__)<<" ["<<__LINE__<<"]"<<endl)
#else
#define dump(...)
#endif
// ll const mod = 1000000007;
// ll const inf = 1LL<<60;

// Small : dijkstra
// Large : greedy

int popcount(int x){
    return __builtin_popcount(x);
}

int solve(){
    int R,C,N;
    cin >> R >> C >> N;
    int K = R*C;
    int ans = 200;
    rep(mask,1<<K)if(popcount(mask)==N){
        int cell[20][20] = {};
        rep(i,K){
            if(mask >> i & 1){
                int x = i%C;
                int y = i/C;
                cell[y][x] = 1;
            }
        }
        int c = 0;
        rep(i,R)rep(j,C){
            if(cell[i][j]){
                int dx[] = {0,1};
                int dy[] = {1,0};
                rep(d,2){
                    int ni = i+dy[d];
                    int nj = j+dx[d];
                    if(cell[ni][nj]) c++;
                }
            }
        }
        ans = min(ans, c);
    }
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    rep(i,T){
        int ans = solve();
        printf("Case #%d: %d\n", (int)i+1,ans);
    }
}
