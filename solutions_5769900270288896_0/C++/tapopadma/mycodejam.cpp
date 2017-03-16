// Headers
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<vector>
#include<map>
#include<fstream>
#include<list>
#include<stack>
#include<queue>
#include<algorithm>
#include<bitset>
#include<set>
using namespace std;
// Global declarations
typedef long long int ll;
typedef vector<int> vi;
typedef vector<char> vc;
typedef pair<int,int> pi;
const double eps = 1e-6;
int const mod  = 1e9+7;
int const INF = 1<<29;
// Macros
#define mp make_pair
#define el putchar('\n')
#define sp putchar(' ')
#define Fill(a,val) memset(a,val,sizeof a)
#define pb push_back
#define ppb pop_back
#define gcd __gcd
#define all(a) a.begin(),a.end()
#define ff first
#define ss second

bool vis[100];

int main(){
    freopen("ip.in","r",stdin);
    freopen("op.out","w",stdout);
    ll t,x=1;cin>>t;
    while(t--){
        ll N,R,C;
        cin>>R>>C>>N;
        cout<<"Case #"<<x++<<": ";
        if(N == 0) {cout<<"0\n";continue;}
        ll arr[25],tot=0;
        ll ans = INF;
        for(ll i=0;i<R;++i){
            for(ll j=0;j<C;++j){
                arr[tot++] = i*C+j;
            }
        }
        ll mx = (1ll<<tot);
        for(ll i=0;i<mx;++i){
            ll L = 0;
            Fill(vis,0);
            vector<ll>v;
            for(ll j=0;j<tot;++j){
                if((1ll<<j)&i) {
                    ++L;
                    v.pb(arr[j]);
                }
            }
            if(L == N){
                ll sz = v.size();
                ll cur = 0;
                for(ll k=0;k<sz;++k) vis[v[k]] = 1;
                for(ll j=0;j<R;++j){
                    for(ll k=0;k<C;++k){
                        if(!vis[j*C+k]) continue;
                        if(j+1 < R && vis[(j+1)*C+k]) ++cur;
                        if(k+1 < C && vis[j*C+k+1]) ++cur;
                    }
                }
                ans = min(ans,cur);
            }
        }
        cout<<ans;el;
    }
    return 0;
}
