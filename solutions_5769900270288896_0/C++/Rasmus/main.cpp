#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <iterator>

using namespace std;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORE(i,n) for (int i=0; i<=n; ++i)
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define REPE(i,a,b) for (int i=a; i<=b; ++i)
#define mp make_pair
#define pb push_back

typedef long double dbl;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;
const dbl pi = 3.14159265358979323846;
const int inf = (int) 1e9;
const dbl eps = 1e-9;

int r,c,n;
int res = inf;

bool used[20][20];

bool check(int x, int y) {
	return x >= 0 && y >= 0 && x < r && y < c;
}

int dx[2] = {0, 1};
int dy[2] = {1, 0};

void go() {
	res = inf;
	int rc = r * c;	
	FOR(mask,1 << rc) {		
		int kol = 0;
		FOR(i,rc) {
			if (mask & (1 << i)) {
				++kol;
			}
		}
		if (kol != n) {
			continue;
		}
		memset(used, false, sizeof(used));
		FOR(i,rc) {
			if (mask & (1 << i)) {
				int x = i / c;
				int y = i % c;
				used[x][y] = true;
			}
		}
		int now = 0;
		FOR(i,r) {
			FOR(j,c) {
				if (!used[i][j]) {
					continue;
				}
				FOR(k,2) {
					int x = i + dx[k];
					int y = j + dy[k];
					if (check(x, y) && used[x][y]) {
						++now;
					}
				}
			}
		}
		res = min(res, now);
	}
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    //freopen("rotate-this.in","r",stdin);
    //freopen("rotate-this.out","w",stdout);
#endif
	int T;
	cin >> T;	
	FOR(TT,T) {		
		cin >> r >> c >> n;
		go();
		cout << "Case #" << TT + 1 << ": " << res << "\n";

	}
	return 0;
}