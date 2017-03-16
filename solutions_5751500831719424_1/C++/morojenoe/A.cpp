#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <vector>
#include <memory.h>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <string.h>
#include <sstream>
#include <cmath>
#include <math.h>
#include <queue>
#include <deque>
#include <cassert>
#include <time.h>

#define forn(i,n) for (int i = 0; i < (int)n; i++)
#define fornd(i, n) for (int i = (int)n - 1; i >= 0; i--)
#define forab(i,a,b) for (int i = (int)a; i <= (int)b; i++)
#define forabd(i, b, a) for (int i = (int)(b); i >= (int)(a); i--)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define zero(a) memset (a, 0, sizeof (a))
#define last(v) (int)v.size() - 1
#define _(a, val) memset (a, val, sizeof (a))
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

#ifdef _DEBUG
#define dbg(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#define dbgx(x) {cerr << #x << " = " << x << endl;}
#define dbgv(v) {cerr << #v << " = {"; for (typeof(v.begin()) it = v.begin(); it != v.end(); it ++) cerr << *it << ", "; cerr << "}"; cerr << endl;}
#else
#define dbg(...) { }
#define dbgx(x) { }
#define dbgv(v) { }
#endif

typedef long long lint;
typedef unsigned long long ull;
typedef long double ld;

const lint LINF = 1000000000000000000LL;
const int INF = 1000000000;
const long double eps = 1e-9;
const long double PI = 3.1415926535897932384626433832795l;

using namespace std;

void prepare (string s)
{
#ifdef _DEBUG
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);
#else
	if (s.length() != 0)
	{
		freopen ((s + ".in").c_str(), "r", stdin);
		freopen ((s + ".out").c_str(), "w", stdout);
	}
#endif
}

const int NMAX = 155;
int n;
string s[NMAX];
char buf[NMAX];

void read()
{
	scanf("%d", &n);
	forn(i, n)
	{
		scanf("%s", buf);
		s[i] = buf;
	}
}

string get(int id)
{
	string tmp;
	char cur = 0;
	forn(i, s[id].length())
	{
		if (s[id][i] == cur) continue;
		tmp += s[id][i];
		cur = s[id][i];
	}
	return tmp;
}

void solve()
{	
	string t = get( 0 );
	forn(i, n)
	{
		if (get(i) != t)
		{
			printf("Fegla Won\n");
			return;
		}
	}
	vector<int> v;
	vector<int> ptr(n, 0);
	int answer = 0;
	forn(i, sz(t))
	{
		v.clear();
		forn(j, n)
		{
			int c = 0;
			while(ptr[j] < sz(s[j]) && s[j][ptr[j]] == t[i]) c++, ptr[j]++;
			v.pb ( c );
		}
		
		int ans = INF;	
		for(int k = 1; k <= 100; k++)
		{
			int r = 0;
			forn(j, n)
			{
				r += abs( k - v[j] );
			}
			ans = min(ans, r);
		}
		answer += ans;
	}
	printf("%d\n", answer);
}

int main ()
{
	prepare ("");
	
	int t;
	scanf("%d", &t);
	forn(i, t)
	{
		printf("Case #%d: ", i + 1);
		read();
		solve();
	}

	return 0;
}
