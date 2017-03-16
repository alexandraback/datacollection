#include "bits/stdc++.h"
#pragma comment(linker, "/STACK:102400000,102400000")
#define debug(a) cout<<a<<endl
#define PB push_back
#define PF push_front
#define LB lower_bound
#define UB upper_bound
#define fr(x) freopen(x,"r",stdin)
#define fw(x) freopen(x,"w",stdout)
#define in(x) (read(x))
#define iout(x) printf("%d\n",x)
#define lout(x) printf("%lld\n",x)
#define REP(x,l,u) for(ll x = l;x<u;x++)
#define RREP(x,l,u) for(ll x = l;x>=u;x--)
#define complete_unique(a) a.erase(unique(a.begin(),a.end()),a.end())
#define mst(x,a) memset(x,a,sizeof(x))
#define _sort(a) sort(a.begin(),a.end())
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define MP make_pair
#define lowbit(x) (x&(-x))
#define lson (ind<<1)
#define rson (ind<<1|1)
#define se second
#define fi first
#define sz(x) ((int)x.size())
typedef  long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
using namespace std;
const int block_size = 320;
typedef complex<ll> point;
const ll mod = 1e9+7;
const ld eps = 1e-9;
const int inf = mod;
template<typename T>
inline int sign(const T&a){if(a<0)return -1;if(a>0)return 1;return 0;}


template<typename T> inline void read(T &x){
    x = 0; T f = 1; char ch = getchar();
    while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
    while (isdigit(ch))  {x = x * 10 + ch - '0'; ch = getchar();}
    x *= f;
}


void solve(){
    priority_queue<pair<int, char>>pq;
    int n;
    cin>>n;
    REP(i,0,n){
        int temp;
        cin>>temp;
        pq.push(MP(temp,i+'A'));
    }
    while (!pq.empty()) {
        if(pq.size() == 2){
            pair<int, char>p[2];
            p[0] = pq.top();
            pq.pop();
            p[1] = pq.top();
            
            pq.pop();
            if(p[0].fi == p[1].fi){
                REP(i,0,p[0].fi){
                    cout<<p[0].se<<p[1].se<<' ';
                }
            }else if (p[0].fi == p[1].fi+1){
                cout<<p[0].se<<' ';
                REP(i,0,p[0].se){
                    cout<<p[0].se<<p[1].se<<' ';
                }
            }else{
                assert(0==-1);
            }
            cout<<endl;
            return;
        }else{
            cout<<pq.top().se<<' ';
            auto c = pq.top();
            c.fi--;
            pq.pop();
            
            if(c.fi!=0)pq.push(c);
        }
    }
}
int main(){
  //  fw("out.txt");
    int n;
    cin>>n;
    REP(i,0,n){
        cout<<"Case #"<<i+1<<": ";
        solve();
    }
    return 0;
}