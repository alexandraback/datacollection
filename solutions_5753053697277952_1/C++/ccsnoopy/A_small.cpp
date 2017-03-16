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

int main(void){
    freopen("C:/Users/SONY/Desktop/A-large.in","r",stdin);
    freopen("D:/Code/GCJ/2016/1C/out.txt", "w", stdout);

    int tc, ctr = 1;
    sc(tc);

    while(tc--){
        int n, arr[30], total;
        map<char, int> mapper;
        sc(n);
        total = 0;
        FOR(i,n){
            sc(arr[i]);
            total+=arr[i];
        }
        printf("Case #%d: ", ctr++);
        while(total){
            int maxi = -10;

            vector<int> vi;
            FOR(i,n){
                if(maxi < arr[i]){
                    vi.clear();
                    vi.pb(i);
                    maxi = arr[i];
                }else if(maxi == arr[i]){
                    vi.pb(i);
                }
            }

            if(vi.size() == 1){
                printf("%c ", vi[0] + 'A');
                arr[vi[0]]--;
                total--;
            }else if(vi.size() == 2){
                printf("%c%c ", vi[0] + 'A', vi[1] + 'A');
                arr[vi[0]]--;arr[vi[1]]--;
                total-=2;
            }else if(vi.size() > 2){
                printf("%c ", vi[0] + 'A');
                arr[vi[0]]--;
                total--;
            }
        }
        printf("\n");
    }
    return 0;
}


