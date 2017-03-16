#ifdef _MSC_VER
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <fstream>
#include <cassert>
#include <ctime>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <list>
#include <string>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <stack>
#include <functional>
#include <limits>
#include <cstring>
using namespace std;

typedef long long li;
typedef unsigned long long uint64;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;
typedef long double ld;
typedef pair<int,int> pt;


#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n - 1); i >= 0; i--)
#define pb push_back
#define mp make_pair
#define matrix(T,n,m,v) vector<vector<T> >(n, vector<T>(m, v))
#define ft first
#define sc second
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()

template<class T> T sqr(const T& x) { return x * x; }
template<class T> T abs(const T& x) { return x < 0 ? -x : x; }

template<class T, class P>
ostream& operator << (ostream& out, std::pair<T, P> p) {
	return (out << '(' << p.first << ' ' << p.second << ')');
}

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-8;
const ld PI = 3.1415926535897932384626433832795;

int r[2];
int a[2][4][4];

bool read() {
	forn (k, 2) {
    	scanf("%d", &r[k]);
    	r[k]--;
    	forn (i, 4) {
    		forn (j, 4) {
    			scanf("%d", &a[k][i][j]);
    		}
    	}
    }
	return true;
}

void solve(int test) {
	int ans = -1;
	forn (i, 4) {
		int f = -1;
		forn (j, 4) {
			if (a[0][r[0]][i] == a[1][r[1]][j]) {
				f = j;
				break;
			}
		}
		if (f != -1) {
			if (ans != -1) {
				printf("Case #%d: Bad magician!\n", test);
				return;
			}
			ans = a[0][r[0]][i];
		}
	}
	cerr << ans << endl;
	if (ans == -1) {
		printf("Case #%d: Volunteer cheated!\n", test);
	} else {
		printf("Case #%d: %d\n", test, ans);
	}
}

int main() {
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int testCnt;
	scanf("%d", &testCnt);
	forn (test, testCnt) {
		read();
		solve(test + 1);
	}
	
    return 0;
}