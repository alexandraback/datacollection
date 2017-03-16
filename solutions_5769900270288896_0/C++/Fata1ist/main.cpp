#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define forab(i, k, n) for (int i = (int)(k); i < (int)(n); i++)
#define forba(i, n, k) for (int i = (int)(n) - 1; i >= (int)(k); i--)

#define vi vector<int>
#define pii pair<int, int>
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x)*(x))
#define X first
#define Y second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld; 

const ld pi = acos(-1.0);
const ld eps = 1e-8;
const int INF = 1E9;		
const int MAXN = 20;
const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

int t;
int n, m, k, maxmask, ans, cur;
bool a[MAXN][MAXN];

int main() {

	cin >> t;
	forn(ttt, t) {
		cin >> n >> m >> k;
		maxmask = 1 << (n * m);

		ans = INF;
		memset(a, 0, sizeof(a));
			
		for (int mask = 0; mask < maxmask; mask++) {
			int cnt = 0;
			forn(i, n * m)
				if ((mask >> i) & 1)
					cnt++;
			if (cnt != k)
				continue;

			forn(i, n * m)
				a[i / m + 1][i % m + 1] = (mask >> i) & 1;
			cur = 0;
			forn(i, n)
				forn(j, m) {
					forn(d, 2)
						if (a[i + 1][j + 1] && a[i + 1 + dx[d]][j + 1 + dy[d]])
							cur++;
				}
			ans = min(ans, cur);
		}
		
		printf("Case #%d: ", ttt + 1);
		cout << ans << '\n';    		
	}
		    
	return 0;
}