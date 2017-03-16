#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int a, b;
int x[4][4];
int y[4][4];

int main () {
	int tt;
	cin >> tt;
	for (int it = 1; it <= tt; it++) {
		cin >> a; a--;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> x[i][j];
		cin >> b; b--;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				cin >> y[i][j];
		vi res;
		for (int i = 0; i < 4; i++)
			for (int j = 0; j < 4; j++)
				if (x[a][i] == y[b][j])
					res.pb (x[a][i]);
		cout << "Case #" << it << ": ";
		if (res.empty ()) cout << "Volunteer cheated!"; else
		if (sz (res) > 1) cout << "Bad magician!"; else cout << res[0];
		cout << endl;
		fprintf (stderr, "%d / %d = %.2f | %.2f\n", it, tt, (double)clock () / CLOCKS_PER_SEC, ((double)clock () / it * tt) / CLOCKS_PER_SEC);
	}
	return 0;
}