 #include <bits/stdc++.h>


using namespace std;

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define forn(i,a,b) for( int i = (a); i < (b); i++)
#define rep(i,n) forn(i,0,n)
#define repe(i,n) for( i = 0; i < (n); i++)
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<ll,ll>


const int MXN = 2010;
const int MXK = 200100;
const int ALP = 500;
const int inf = 1e9+5;
const ll linf = 1e18;
const int mod = 1000000007;

int a [MXN];
void solve(){
    int n;
    scanf("%d", &n);
    int sum = 0, mxd = 0, p = 0;
    rep(i,n){
        scanf("%d", &a[i]);
        if(i && a[i-1]>a[i]){
            sum += a[i-1]-a[i];
            mxd = max(mxd, a[i-1]-a[i]);
        }
    }
    int sum1 = 0;
    rep(i,n-1){
        sum1 += min(a[i],mxd);
    }
    printf("%d %d", sum, sum1);
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    rep(i,t){
        printf("Case #%d: ", i+1);
        solve();
        printf("\n");
    }

    return 0;
}
