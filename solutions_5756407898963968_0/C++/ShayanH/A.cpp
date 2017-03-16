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

const int MAXN = 1 * 1000 + 10;

int a[10][10], b[10][10];

int main ()
{
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;
	for (int o = 1; o <= tc; o ++)
	{
		int x, y;
		cin >> x; x --;
		FOR(i, 4) FOR(j, 4) cin >> a[i][j];

		cin >> y; y --;
		FOR(i, 4) FOR(j, 4) cin >> b[i][j];

		vector<int> ans;
		FOR(i, 4) FOR(j, 4) if (a[x][i] == b[y][j]) ans.pb(a[x][i]);

		cout << "Case #" << o << ": ";
		if (SZ(ans) == 1) cout << ans[0] << endl;
		else if (!SZ(ans)) cout << "Volunteer cheated!\n";
		else cout << "Bad magician!\n";
	}
	return 0;
}

