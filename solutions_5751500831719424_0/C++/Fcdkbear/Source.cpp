#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <unordered_map>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.14159265358979
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

vector<string> s;
vector<vector<pnt > > g;
vector<pnt > get(int v)
{
	vector<pnt > res;
	int idx = 0;
	FOR(i, 1, s[v].size())
	{
		if (s[v][i] != s[v][idx])
		{
			res.push_back(mp(s[v][idx] - 'a', i - idx));
			idx = i;
		}
	}
	res.push_back(mp(s[v][idx] - 'a', s[v].size() - idx));
	return res;
}
inline bool go(int v1, int v2)
{
	vector<pnt> a = g[v1];
	vector<pnt> b = g[v2];
	if (a.size() != b.size())
		return false;
	FOR(i, 0, a.size())
	{
		if (a[i].first != b[i].first)
			return false;
	}
	return true;
}

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
	double beg = clock();
#else
	freopen("in.txt", "r", stdin);
	freopen("out.txt","w",stdout);
#endif

	int t;
	scanf("%d", &t);
	FOR(it, 1, t + 1)
	{
		s.clear();
		int res = 1000000000;
		int n;
		scanf("%d", &n);
		s.resize(n);
		g.clear();
		FOR(i, 0, n)
		{
			cin >> s[i];
			g.push_back(get(i));
		}
		bool f = true;
		FOR(i,0,n)
			FOR(j, 0, n)
			{
				bool f1 = go(i, j);
				if (!f1)
					f = false;
			}
		printf("Case #%d: ", it);
		if (!f)
			printf("Fegla Won\n");
		else
		{
			int res = 0;
			FOR(j, 0, g[0].size())
			{
				int min1 = 1000000000;
				FOR(k, 0, 105)
				{
					int now = 0;
					FOR(i, 0, g.size())
						now += ABS(g[i][j].second - k);
					min1 = MIN(min1, now);
				}
				res += min1;
			}
			printf("%d\n", res);
		}

	}
	
#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
}