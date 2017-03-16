#include <cassert>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
 
using namespace std ;
 
#define forsn(i, s, n) for (int i = s ; i < n ; i++)
#define forn(i, n) forsn(i, 0, n)
#define fore(i, n) forn(i, n.size())
#define fori(i, n) for (auto i = n.begin() ; i != n.end() ; i++)
#define all(n) n.begin(), n.end()
#define pb push_back

#define y first
#define x second

typedef pair <int, char> pic ;
typedef vector <pic> vpi ;

const int big = 100000000 ;

vpi press(const string &n)
{
	vector <pic> r ;

	int l = 0 ;
	fore(i, n)
	{
		l += 1 ;

		if (i == n.size() - 1 || n[i] != n[i + 1])
		{
			r.pb(pic(l, n[i])) ;
			l = 0 ;
		}
	}

	return r ;
}

int solve(const vector <vpi> &g)
{
	assert(g.size() > 0) ;

	int r = 0 ;

	fore(i, g) if (g[i].size() != g[0].size()) return -1 ;
	fore(h, g[0])
	{
		fore(i, g) if (g[i][h].x != g[0][h].x) return -1 ;

		int q = big ;
		fore(x, g)
		{
			int s = 0 ;
			fore(i, g) s += abs(g[i][h].y - g[x][h].y) ;
			q = min(q, s) ;
		}

		assert(q < big) ;
		r += q ;
	}

	return r ;
}

int main()
{
	int t ; cin >> t ;
	forn(z, t)
	{
		int n ; cin >> n ;

		vector <vpi> g(n) ;
		forn(i, n)
		{
			string s ; cin >> s ;
			g[i] = press(s) ;
		}

		int r = solve(g) ;
		printf("Case #%d: ", z + 1) ;
		if (r == -1) printf("Fegla Won\n") ;
		else printf("%d\n", r) ;
	}

	return 0 ;
}
