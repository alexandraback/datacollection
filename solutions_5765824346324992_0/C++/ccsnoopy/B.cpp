#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long long LL;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#ifdef DEBUG
    #define cek(x) cout<<x
#else
    #define cek(x) if(false){}
#endif // DEBUG

#define fi first
#define se second
#define INF 1000000000
#define INFLL 1000000000000000000LL
#define EPS 1e-9
#define PI acos(-1.0)
#define pb push_back
#define TC() while(tc--)
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORN(i,n) for(int i=0;i<=n;i++)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define REPN(i,a,b) for(int i=a;i<=b;i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define sc(x) scanf("%d",&x)

int gcd(int a, int b){return b == 0 ? a : gcd(b, a%b);}
int lcm(int a, int b){return a * (b / gcd(a,b));}

int main(void){
    #ifdef ccsnoopy
        freopen("C:/Users/SONY/Desktop/B-small-attempt0.in","r",stdin);
        freopen("C:/Users/SONY/Desktop/out.txt","w",stdout);
    #endif
    //to compile: g++ -o foo filename.cpp -lm -Dccsnoopy for debug.
    int tc;
    int casecounter = 1;
    sc(tc);
    while(tc--){
        int b, n;
        sc(b);sc(n);
        int arr[10];
        FOR(i,b){
            sc(arr[i]);
        }
        int hasil = 1;
        FOR(i,b){
            hasil = lcm(hasil, arr[i]);
        }
        int totz = 0;
        FOR(i,b){
            totz+=hasil/arr[i];
        }
        int nx = (n-1)%totz;
        //cout<<nx<<endl;
        vector<int>v;
        int ctr = 0;
        int time = 0;
        while(ctr <= nx){
            FOR(j, b){
                if(time%arr[j] == 0){v.pb(j+1);ctr++;}
            }
            time++;
        }
        //cout<<"sampe";
        //FOR(i, (int)v.size())cout<<v[i]<<endl;
        printf("Case #%d: %d\n", casecounter++, v[nx]);

    }

    return 0;
}



