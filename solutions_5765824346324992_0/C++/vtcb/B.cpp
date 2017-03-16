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

struct st
{
	ll tl;
	ll id;
	st(ll tl, ll id) : tl(tl), id(id) {}
	
	bool operator < (const st& s) const
	{
		return true;
		/*
		if(tl == 0 && s.tl != 0) return true;
		if(tl != 0 && s.tl == 0) return false;
		if(tl == 0 && s.tl == 0) return id < s.id;
		return tl < s.tl;
		*/
	}
	
};

ll b, n;
int v[1111];

int main()
{
	FASTIO
	int T;
	cin >> T;
	fe(cas, 1, T)
	{
		cin >> b >> n;
		
		rp(i, b) cin >> v[i];
		ll sum = 0;
		
		rp(i, b) sum += v[i];
		
		n %= sum;
		
		priority_queue<ii> h;
		
		rp(i, b)
		{
			h.push( ii(-i, -i) );
		}
		if(n == 0)
		{
			printf("Case #%d: %d\n", cas, 1);
			continue;
		}	
		
		n--;
		while(n--)
		{
			ii cur = h.top(); h.pop();
			
			h.push( ii(cur.F - v[-cur.S], cur.S) );
		}
		
		printf("Case #%d: %d\n", cas, -h.top().S + 1);
	}
}
