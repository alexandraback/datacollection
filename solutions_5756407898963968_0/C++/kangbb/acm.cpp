#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>

using namespace std;
//-----------------------------------------------------------
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
//-----------------------------------------------------------

#define MAXN 17
#define MAXS 5
#define SIZE 4
int N;
bool b[ 2 ][ MAXN ];

int main() {
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {

		int cnt = 0;
		int ans = 0;
		int tmp = 0;
		memset(b, 0, sizeof(b));

		forn(s, 2) {
			scanf("%d", &N);
			forn(i, SIZE) {
				forn(j, SIZE) {
					scanf("%d", &tmp);
					b[s][tmp] = (i + 1 == N);
				}
			}
		}

		forn(i, MAXN) {
			if( b[0][i] && b[1][i] ) {
				ans = i;
				cnt++;
			}
		}

		if( cnt == 0 ) {
			printf("Case #%d: Volunteer cheated!\n", casenum++);
		}
		else if( cnt == 1 ) {
			printf("Case #%d: %d\n", casenum++, ans);
		}
		else {
			printf("Case #%d: Bad magician!\n", casenum++);
		}
	}
	return 0;
}
