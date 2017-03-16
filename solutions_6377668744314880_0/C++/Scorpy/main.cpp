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


const int MXN = 3010;
const int MXK = 200100;
const int ALP = 500;
const int inf = 1e9+5;
const ll linf = 1e17;
const int mod = 1000000007;

struct point{
    ll x,y;
    int i;
    point(){}
    point(ll x, ll y):x(x),y(y){}
};

point ps [MXN];
point pss [MXN];

bool ccw( point a, point b, point c ){
    return (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x) > 0;
}
bool cw( point a, point b, point c ){
    return (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x) < 0;
}

point hull [MXN];
int hc;

int ans [MXN];

bool cmp (point a, point b) {
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int n;

point up [MXN];
point down [MXN];
int upc, dwc;

void convex_hull () {
    hc = upc = dwc = 0;
	sort (ps, ps+n, cmp);
	point p1 = ps[0],  p2 = ps[n-1];
	up[upc++] = p1;
	down[dwc++] = p1;
	for (int i=1; i<n; ++i) {
		if (i==n-1 || !ccw (p1, ps[i], p2)) {
			while (upc>=2 && ccw (up[upc-2], up[upc-1], ps[i]))
				upc--;
			up[upc++] = ps[i];
		}
		if (i==n-1 || !cw (p1, ps[i], p2)) {
			while (dwc>=2 && cw (down[dwc-2], down[dwc-1], ps[i]))
                dwc--;
			down[dwc++] = ps[i];
		}
	}
	rep(i,dwc) hull[hc++] = down[i];
	for( int i = upc-2; i>0; i-- ) hull[hc++] = up[i];
}

bool isset( int msk, int i ){
    return (1<<i) & msk;
}

void solve(){
    scanf("%d", &n);
    rep(i,n){
        scanf("%lld%lld", &pss[i].x, &pss[i].y);
        pss[i].i = i;
        ans[i] = n-1;
    }
    int k = n;
    rep(i,(1<<k)){
        n = 0;
        rep(j,k){
            if( isset(i,j) ) ps[n++] = pss[j];
        }
        convex_hull();
        rep(j,k)
            rep(t,hc)
                if(hull[t].x==pss[j].x && hull[t].y==pss[j].y) ans[j] = min(ans[j], k-n);
    }

    rep(i,k) printf("\n%d", ans[i]);
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    rep(i,t){
        printf("Case #%d:", i+1);
        solve();
        printf("\n");
    }

    return 0;
}
