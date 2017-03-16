#pragma comment(linker, "/stack:128000000")
#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <algorithm>
#include <iostream>
#include <cassert>
#include <iomanip>
#include <climits>
#include <utility>
#include <cstring>
#include <complex>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <bitset>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair((a), (b))
#define x first
#define y second
#define ft first
#define sc second

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = INT_MAX / 2;
const ld EPS = ld(1e-9);
const ld PI = ld(3.1415926535897932384626433832795);

const int N = 100 + 3;

int n;
string s[N];

char buf[N];

inline bool read()
{
	if (scanf("%d", &n) != 1)
		return false;
		
	assert(n > 0);
		
	forn(i, n)
	{
		assert(scanf("%s", buf) == 1);
		s[i] = string(buf);
	}
	
	return true;
}

vector<pt> z[N];

inline vector<pt> getVector(const string& s)
{
	vector<pt> z;
	
	for(int i = 0; i < sz(s); )
	{
		int j = i;
		while(j < sz(s) && s[i] == s[j])
			j++;
			
		int c = s[i] - 'a';
		int len = j - i;
		z.pb(mp(c, len));
		
		i = j;
	}
	
	return z;
}

inline bool eqChars(const vector<pt>& a, const vector<pt>& b)
{
	if (sz(a) != sz(b))
		return false;
		
	forn(i, sz(a))
		if (a[i].ft != b[i].ft)
			return false;
		
	return true;
}

inline int getVal(const vector<int>& z, int len)
{
	int ans = 0;
	
	forn(i, sz(z))
		ans += abs(z[i] - len);
		
	return ans;
}

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);
	
	forn(i, n)
		z[i] = getVector(s[i]);
		
	bool ok = true;
	
	fore(i, 1, n - 1)
		if (!eqChars(z[0], z[i]))
			ok = false;
			
	if (!ok)
	{
		puts("Fegla Won");
		return;
	}
	
	int ans = 0;
	
	forn(j, sz(z[0]))
	{
		vector<int> cur;
		forn(i, n)
			cur.pb(z[i][j].sc);
			
		int val = INF;
		
		fore(len, 1, N)
			val = min(val, getVal(cur, len));
			
		ans += val;
	}
	
	cout << ans << endl;
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

    int testCnt;

    assert(scanf("%d\n", &testCnt) == 1);

    forn(test, testCnt)
    {
    	assert(read());
		solve(test);
	}

    return 0;
}
