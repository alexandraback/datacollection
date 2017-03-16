#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;
typedef long long LL;
typedef vector<LL> VLL;
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define VAR(v, n) __typeof(n) v = (n)
#define FOREACH(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) ((int)(x).size())
#define PB push_back
#define MP make_pair
#define ST first
#define ND second
const int INF = 1000000001;
const double EPS = 10e-9;

int Ocen(int r, int c, int b)
{
	int w = 0;
	int j;
	REP(i, r * c) if(b & (1 << i))
	{
		j = i + 1;
		if(j % c != 0 && (b & (1 << j)) != 0)
			w++;
		j = i + c;
		if(j < r * c && (b & (1 << j)) != 0)
			w++;
	}
	return w;
}

int Policz(int b)
{
	int w = 0;
	int i = 1;
	REP(j, 16)
	{
		if(b & i) w++;
		i <<= 1;
	}
	return w;
}

int main()
{
	int t;
	cin >> t;
	FOR(o, 1, t)
	{
		int r, c, n, w = INF;
		cin >> r >> c >> n;
		REP(x, 1 << (r * c))
		{
			if(Policz(x) == n)
				w = min(w, Ocen(r, c, x));
		}
		cout << "Case #" << o << ": " << w << endl;
	}
	return 0;
}