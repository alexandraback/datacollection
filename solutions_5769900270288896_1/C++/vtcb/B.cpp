#include <bits/stdc++.h>

using namespace std;

#define fr(a, b, c) for(int a = b, __ = c; a < __; a++)
#define fe(a, b, c) for(int a = b, __ = c; a <= __; a++)

#define rp(a, b) fr(a, 0, b)

#define iter(c) __typeof((c).begin())
#define tr(a,b) for(iter(b) a = (b).begin(); a != (b).end(); ++a)

#define iz(a) if(a == 0) { break; }

#define FASTIO ios_base::sync_with_stdio(0);

#define F first
#define S second

#define clr(a, b) memset(a, b, sizeof(a))

#define mp make_pair
#define pb push_back

#define sd(x) scanf("%d", &x)
#define sll(x) scanf("%lld", &x)
#define slf(x) scanf("%lf", &x)
#define sii(x) scanf("%d%d", &x.F, &x.S)
#define sc(x) scanf(" %c", &x)
#define ss(x) scanf(" %s", x)
#define sn(x) scanf(" %[^\n]", x)

#define sd1(a) scanf("%d", &a)
#define sd2(a,b) scanf("%d %d", &a, &b)
#define sd3(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sd4(a,b,c,d) scanf("%d %d %d %d", &a, &b, &c, &d)

#define dbg(x) cout << x << endl;
#define db2(x) cout << #x << " = " << x << endl;
#define _ << ", " <<
#define line(x) { fr(i, 0, x) putchar('-'); puts(""); }
#define hello dbg("hello");

template <class T1, class T2>
	ostream& operator<< (ostream& c, pair<T1, T2> p) { return c << "(" << p.F << ", " << p.S << ")"; }

template <class _T> inline string tostr(const _T& a){ ostringstream os(""); os << a; return os.str(); }
template <class T> inline T sqr(const T& x) { return x * x; }

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<double, double> dd;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const double eps = 1e-7;

int r, c, n;
int ma[10011][10011];

int de[2][4] = 
{
	{0, 1, 0, -1},
	{1, 0, -1, 0}
};
bool valid(int i, int j) { return i >= 0 && j >= 0 && i < r && j < c;}
int numAd(int i, int j)
{
	int ans = 0;
	rp(k, 4)
	{
		int dx = i + de[0][k];
		int dy = j + de[1][k];
		
		if(!valid(dx, dy)) continue;
		
		if(ma[dx][dy] == 1) ans++;
	}
	return ans;
}

ll solution1()
{
	ll ans = 0;
	int cur = 0;
	rp(i, r) rp(j, c)
	{
		if((i + j)&1)
		{
			ma[i][j] = 1;
			cur++;
		}
		else
		{	
			ma[i][j] = 0;
		}
	}
	
	if(cur >= n) return 0;
	
	if(ma[0][0] == 0)
	{
		ma[0][0] = 1;
		cur++;
		ans += numAd(0, 0);
	}
	
	if(cur == n) return ans;
	
	if(ma[r - 1][0] == 0)
	{
		ma[r - 1][0] = 1;
		cur++;
		ans += numAd(r - 1, 0);
	}
	
	if(cur == n) return ans;
	
	if(ma[0][c - 1] == 0)
	{
		ma[0][c - 1] = 1;
		cur++;
		ans += numAd(0, c - 1);
	}
	
	if(cur == n) return ans;
	
	if(ma[r - 1][c - 1] == 0)
	{
		ma[r - 1][c - 1] = 1;
		cur++;
		ans += numAd(r - 1, c - 1);
	}
	
	if(cur == n) return ans;
	
	rp(i, r)
	{
		if(ma[i][0] == 0)
		{
			ma[i][0] = 1;
			cur++;
			ans += numAd(i, 0);
		}
		
		if(cur == n) return ans;
		
		if(ma[i][c - 1] == 0)
		{
			ma[i][c - 1] = 1;
			cur++;
			ans += numAd(i, c - 1);
		}
		
		if(cur == n) return ans;
	}
	
	rp(j, c)
	{
		if(ma[0][j] == 0)
		{
			ma[0][j] = 1;
			cur++;
			ans += numAd(0, j);
		}
		
		if(cur == n) return ans;
		
		if(ma[r - 1][j] == 0)
		{
			ma[r - 1][j] = 1;
			cur++;
			ans += numAd(r - 1, j);
		}
		
		if(cur == n) return ans;
	}
	
	rp(i, r) rp(j, c)
	{
		if(ma[i][j] == 1) continue;
		ma[i][j] = 1;
		cur++;
		ans += numAd(i, j);
		
		if(cur == n) return ans;
	}
	return ans;
	assert(false);
}

ll solution2()
{
	ll ans = 0;
	int cur = 0;
	rp(i, r) rp(j, c)
	{
		if((i + j)&1)
		{
			ma[i][j] = 0;
		}
		else
		{	
			ma[i][j] = 1;
			cur++;
		}
	}
	
	if(cur >= n) return 0;
	
	if(ma[0][0] == 0)
	{
		ma[0][0] = 1;
		cur++;
		ans += numAd(0, 0);
	}
	
	if(cur == n) return ans;
	
	if(ma[r - 1][0] == 0)
	{
		ma[r - 1][0] = 1;
		cur++;
		ans += numAd(r - 1, 0);
	}
	
	if(cur == n) return ans;
	
	if(ma[0][c - 1] == 0)
	{
		ma[0][c - 1] = 1;
		cur++;
		ans += numAd(0, c - 1);
	}
	
	if(cur == n) return ans;
	
	if(ma[r - 1][c - 1] == 0)
	{
		ma[r - 1][c - 1] = 1;
		cur++;
		ans += numAd(r - 1, c - 1);
	}
	
	if(cur == n) return ans;
	
	rp(i, r)
	{
		if(ma[i][0] == 0)
		{
			ma[i][0] = 1;
			cur++;
			ans += numAd(i, 0);
		}
		
		if(cur == n) return ans;
		
		if(ma[i][c - 1] == 0)
		{
			ma[i][c - 1] = 1;
			cur++;
			ans += numAd(i, c - 1);
		}
		
		if(cur == n) return ans;
	}
	
	rp(j, c)
	{
		if(ma[0][j] == 0)
		{
			ma[0][j] = 1;
			cur++;
			ans += numAd(0, j);
		}
		
		if(cur == n) return ans;
		
		if(ma[r - 1][j] == 0)
		{
			ma[r - 1][j] = 1;
			cur++;
			ans += numAd(r - 1, j);
		}
		
		if(cur == n) return ans;
	}
	
	rp(i, r) rp(j, c)
	{
		if(ma[i][j] == 1) continue;
		ma[i][j] = 1;
		cur++;
		ans += numAd(i, j);
		
		if(cur == n) return ans;
	}
	
	return ans;
	assert(false);
}

int main()
{
	int T;
	sd(T);
	
	fe(cas, 1, T)
	{
		sd(r);
		sd(c);
		sd(n);
		
		ll ans = min(solution1(), solution2());
		
		printf("Case #%d: %lld\n", cas, ans);
	}
}

