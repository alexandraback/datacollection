/*
ID: keyvank2
TASK: combo
LANG: C++
*/

#include <bits/stdc++.h>

#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define FOR(i,j,k) for(int i = j; i < (int)(k); i++)
#define FORV(i, v) FOR(i, 0, ((v).size()))
#define REP(i,j,k) for(int i = j; i >= (int)(k); i--)
#define setmax(i) const int maxn = (int) i;
#define setmod(i) const int MOD = (int) i;
#define all(a) a.begin(),a.end()
#define autodef(x,v) typeof(v) x = (v)
#define autoref(x,v) typeof(v)& x = (v)
#define forit(it, c) for (autodef(it, ((c).begin())); it != ((c).end()); ++it)

//typedef complex<double> Point;
//#define X real()
//#define Y imag()

using namespace std;

//ifstream fin("");
//ofstream fout("");
//#define cin fin
//#define cout fout

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef pair<pii,int> ppi;
typedef pair<pll,ll> ppl;
typedef pair<int,pii> pip;
typedef pair<ll,pll> plp;
typedef pair<pii,pii> ppp;

const int INF = (int) 2e9;
const ll INFL = (ll) 9e18;
const int MAXINT = ((~0) ^ (1 << 31));
const ll MAXLL = ((~0) ^ ((ll)1 << 63));

template<class T> inline T pow2(T a) { return a*a;}
template<class T> inline bool mineq(T& a, T b){return (a > b) ? (a=b, true) : false;}
template<class T> inline bool maxeq(T& a, T b){return (a < b) ? (a=b, true) : false;}

//srand (time(NULL));

setmax(1e5+10);
ll n,b, t[maxn];

ll check(ll T)
{
    ll ans = 0;
    FOR(i,0,b)
    {
	ans += T/t[i] + 1;
	if(ans > INF)
	    return INF;
    }
    return ans;
}

ll solve()
{
    cin >> b >> n;
    FOR(i,0,b)
	cin >> t[i];

    ll l = 0, r = INFL, ans = -1;
    while(l <= r)
    {
	ll mid = (l+r)/2;
//	cerr << "& " << mid << endl;
	if(check(mid) < n)
	{
	    ans = mid;
	    l = mid+1;
	}
	else
	    r = mid-1;
    }
    
    ll pcount = n - check(ans), cnt = 0;

    //cerr <<"* " <<  ans << " " << pcount << endl;

    FOR(i,0,b)
    {
	if((ans+1)%t[i]==0)
	{
	    cnt++;
	    if(cnt == pcount)
		return i+1;
	}
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int t;
    cin >> t;
    FOR(i,1,t+1)
    {
	cout << "Case #" << i << ": " << solve() << endl;
	cerr << "Case #" << i << " Done" << endl;
    }
}
