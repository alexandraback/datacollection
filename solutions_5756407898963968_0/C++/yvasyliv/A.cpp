#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <ctime>
#include <cmath>
#include <stdio.h>
#include <cassert>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
#include <iomanip>

#define SZ(x) (int((x).size()))
#define FOR(i, a, b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i, a, b) for(int (i) = (a); (i) >= (b); --(i))
#define REP(i, n) for (int (i) = 0; (i) < (n); ++(i))
#define REPD(i, n) for (int (i) = (n); (i)--; )
#define FE(i, a) for (int (i) = 0; (i) < (int((a).size())); ++(i))
#define MEM(a, val) memset((a), val, sizeof(a))
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define PB push_back
#define PPB pop_back
#define ALL(c) (c).begin(), (c).end()
#define SQR(a) ((a)*(a))
#define MP(a,b) make_pair((a), (b))
#define XX first
#define YY second

using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef long double dbl;
typedef pair<int, int> pii;
typedef vector<int> vint;
typedef vector<LL> vLL;

int row[2][17];
int r[2];

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	REP(test, T) {
		REP(i, 2) {
			cin >> r[i];
			REP(j, 4) {
				REP(k, 4) {
					int t;
					cin >> t;
					row[i][t] = j + 1;
				}
			}
		}
		vint ans;
		FOR(i, 1, 16)  {
			if (row[0][i] == r[0] && row[1][i] == r[1])
				ans.push_back(i);
		}
		cout << "Case #" << test + 1 << ": ";
		switch (SZ(ans))
		{
		case 0:
			cout << "Volunteer cheated!";
			break;
		case 1:
			cout << ans[0];
			break;
		default:
			cout << "Bad magician!";
			break;
		}
		cout << endl;
	}
	return 0;
}

