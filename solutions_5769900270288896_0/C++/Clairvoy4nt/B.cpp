#include <cstring>
#include <map>
#include <numeric>
#include <sstream>
#include <cmath>
#include <stack>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>
#include <string>
#include <cctype>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb(x) push_back((x))
#define REP(i,x,y) for(int i = x; i < int(y); i++)
#define FOR(it,A) for(typeof (A.begin()) it = A.begin(); it!= A.end(); it++)
#define CUA(x) (x) * (x)
#define mp(x,y) make_pair((x),(y))
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
#define I (1LL << 40)
#define sz size()
#define oo (1<<30)
#define EPS (1e-9)

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define si(c) ((int)(c).size())
#define forsn(i,s,n) for(int i = (int)(s); i<((int)n); i++)
#define dforsn(i,s,n) for(int i = (int)(n)-1; i>=((int)s); i--)
#define decl(v, c) typeof(c) v = c
#define forall(i, c) for(decl(i, c.begin()); i!=c.end(); ++i)
#define dforall(i, c) for(decl(i, c.rbegin()); i!=c.rend(); ++i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<pii> vii;
typedef vector<string> vs;
typedef vector<int> vi;

int man[1 << 18];
int j, C, N;


 int measure(int i);
int main()
{
#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		cin >> j >> C >> N;

		int best = j * C * N * 100;
		for (int i = 1; i < (1 << (j * C)); i++)
		{
			man[i] = man[i - (i & -i)] + 1;
			if (man[i] == N) best = min(best, measure(i));
		}
		printf("Case #%d: %d\n", t, best);
	}
}
int measure(int i)
{
	int ans = 0;
	for (int r = 0; r < j; r++)
	{
		for (int c = 0; c < C; c++)
		{
			if (c > 0 and (i & (1 << (r * C + c))) and (i & (1 << (r * C + c - 1))))
				ans++;
			if (r > 0 and (i & (1 << (r * C + c))) and (i & (1 << (r * C + c - C))))
				ans++;
		}
	}
	return ans;
}
