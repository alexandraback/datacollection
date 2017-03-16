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
const ll linf = 1e17;
const int mod = 1000000007;

int a [MXN];
int n,b;

ll check( ll m ){
    ll q = 0;
    rep(i,b){
        q += m/a[i] + 1;
    }
    return q;
}

void solve(){
    scanf("%d%d", &b, &n);
    rep(i,b) scanf("%d", &a[i]);

    ll l = -1, r = linf;
    while(l<r-1){
        ll m = (l+r)/2;
        if(check(m) >= n) r = m;
        else l = m;
    }
    n -= check(r-1);

    int mxi = 0;
    ll mx = 0;

    rep(i,b){
        ll q = (r/a[i])*a[i];
        if(q>mx) mx = q, mxi = i;
    }
    rep(i,b){
        ll q = (r/a[i])*a[i];
        if(q==mx){
            n--;
            mxi = i;
            if(!n) break;
        }
    }
    printf("%d", mxi+1);
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
