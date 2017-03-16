#include<bits/stdc++.h>
using namespace std;
#define pi (2.0*acos(0.0))
#define eps 1e-6
#define ll long long
#define inf (1<<29)
#define vi vector<int>
#define vll vector<ll>
#define sc(x) scanf("%d",&x)
#define scl(x) scanf("%lld",&x)
#define all(v) v.begin() , v.end()
#define me(a,val) memset( a , val ,sizeof(a) )
#define pb(x) push_back(x)
#define pii pair<int,int> 
#define mp(a,b) make_pair(a,b)
#define Q(x) (x) * (x)
#define L(x) ((x<<1) + 1)
#define R(x) ((x<<1) + 2)
#define M(x,y) ((x+y)>>1)
#define fi first
#define se second
#define MOD 1000000007
#define ios ios::sync_with_stdio(0);
#define N 105

string s[N];
int P[N];

int main(){
    int tc;
    sc(tc);
    for(int tt = 1 ; tt <= tc ; tt++){
        int n;
        sc(n);
        for(int i = 0 ; i < n ; i++)
            cin >> s[i];
        
        me(P,0);
        char x = s[0][0];
        bool ok = 1;
        int ans = 0;
        for(int i = 0 ; i < s[0].size() and ok ; i++){
            if( s[0][i] == x ) continue;
            else{
                vi v(n, 0);
                for(int j = 0 ; j < n  and ok; j++){
                    int r = P[j];
                    while( P[j] < s[j].size() and s[j][P[j]] == x ){
                        P[j]++;
                    }
                    v[j] = P[j] - r;
                    if( v[j] == 0 ) ok = 0;
                }
                if( !ok ) break;
                sort( all(v) );
                int g = inf;
                for(int j = v[0] ; j <= v[n-1] ; j++){
                    int r = 0;
                    for(int k = 0 ; k < n ; k++)
                        r += abs( v[k] - j );
                    g = min( g , r );
                }
                ans += g;
                
                x = s[0][i];
            }
        }
        vi v(n, 0);
        for(int j = 0 ; j < n and ok; j++){
            int r = P[j];
            while( P[j] < s[j].size() and s[j][P[j]] == x ){
                P[j]++;
            }
            v[j] = P[j] - r;
            if( v[j] == 0 ) ok = 0;
        }
        sort( all(v) );
        int g = inf;
        for(int j = v[0] ; j <= v[n-1] ; j++){
            int r = 0;
            for(int k = 0 ; k < n ; k++)
                r += abs( v[k] - j );
            g = min( g , r );
        }
        ans += g;
        for(int i = 0 ; i < n ; i++)
            if( P[i] != s[i].size() ) ok = 0;
        
        printf("Case #%d: ",tt);
        if(ok) printf("%d\n",ans);
        else printf("Fegla Won\n");
    }
    return 0;
}
