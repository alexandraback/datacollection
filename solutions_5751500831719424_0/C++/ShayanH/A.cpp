#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << (x) << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second
#define EPS (1e-8)

//#define cin fin
//#define cout fout

//ifstream fin("problem.in");
//ofstream fout("problem.out");

const int MAXN = 1 * 100 + 10;

string s[MAXN];
vector<pair<char, int> > v[MAXN];
int sum[MAXN];

int main ()
{
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int o = 1; o <= tc; o ++)
	{
		CLR(sum, 0);
		for (int i = 0; i < MAXN; i ++) 
		{
			v[i].clear();
			s[i].clear();
		}

		int n;
		cin >> n;
		for (int i = 0; i < n; i ++)
		{
			cin >> s[i];
			for (int j = 0; j < SZ(s[i]); j ++)
			{
				int k = j;
				while (k < SZ(s[i]) && s[i][j] == s[i][k]) k ++;
				v[i].pb(mp(s[i][j], k - j));
				j = k - 1;
			}
		}

		bool fegla = false;
		for (int i = 0; i < n; i ++)
		{
			if (SZ(v[i]) != SZ(v[0])) fegla = true;
			for (int j = 0; j < SZ(v[i]); j ++)
			{
				if (v[i][j].X != v[0][j].X) fegla = true;
				sum[j] += v[i][j].Y;
			}
		}

		int ans = 0;
		for (int i = 0; i < n; i ++)
			for (int j = 0; j < SZ(v[i]); j ++)
				ans += abs(v[i][j].Y - sum[j] / n);

		cout << "Case #" << o << ": ";

		if (fegla) cout << "Fegla Won" << endl;
		else cout << ans << endl;
	}
	return 0;
}

