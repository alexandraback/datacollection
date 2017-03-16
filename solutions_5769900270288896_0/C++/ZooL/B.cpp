#if 1
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>
 
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> pii;
 
const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LL inf = 1e+9;
 
#define mp make_pair
#define pb push_back
#define X first
#define Y second
 
#define dbg(x) { cerr << #x << " = " << x << endl; }
 
// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;
 
#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
template<typename T> istream & operator >> (istream &, vector<T> &);
template<typename T> ostream & operator << (ostream &, const vector<T> &);
 
#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;
 
#define NAME "basket"

int sm[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

bool check(int x, int y, int R, int C)
{
	return x >= 0 && y >= 0 && x < R && y < C;
}

int bits(int x)
{
	int cnt = 0;
	while (x)
	{
		x &= (x - 1);
		cnt++;
	}
	return cnt;
}
int get(int R, int C, int N)
{
	int ans = inf;
	int n = R * C;
	for (int mask = 0; mask < (1 << n); mask++)
	{
		if (bits(mask) != N)
			continue;

		vector <vector <int> > a(R, vector <int> (C));
		for (int i = 0; i < n; i++)
		{
			int v = (mask & (1 << i)) > 0;
			int x = i / C;
			int y = i % C;
			a[x][y] = v;
		}

		
		int cnt = 0;
		for (int i = 0; i < R; i++)
			for (int k = 0; k < C; k++)
				for (int j = 0; j < 4; j++)
				{
					if (a[i][k] == 1)
					{
						int nx = i + sm[j][0];
						int ny = k + sm[j][1];
						if (check(nx, ny, R, C))
						{
							if (a[nx][ny] == 1)
								cnt++;
						}
					}
				}

		ans = min(ans, cnt / 2);
	}
	return ans;
}


void solve()
{
	int T;
	scanf("%d", &T);
	for (int q = 0; q < T; q++)
	{
		int R, C, N;
		cerr << q << endl;
		scanf("%d %d %d", &R, &C, &N);
		printf("Case #%d: %d\n",q + 1, get(R, C, N));
	}
}
int main()
{
    //START
    //freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    solve();
    //END
    return 0;
}
/*******************************************
*******************************************/
 
template<typename T> istream & operator >> (istream &is, vector<T> &v)
{
    forn(i, v.size())
        is >> v[i];
    return is;
}
template<typename T> ostream & operator << (ostream &os, const vector<T> &v)
{
    forn(i, v.size())
        os << v[i] << " ";
    return os;
}
#endif