#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; ++i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) (C).begin(), (C).end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	forn(it, t) {
		int can1 = 0;
		int row;
		scanf("%d", &row);
		--row;
		forn(i, 4)
			forn(j, 4) {
				int a;
				scanf("%d", &a);
				--a;
				if  (i == row)
					can1 |= 1 << a;
			}

		int can2 = 0;
		scanf("%d", &row);
		--row;
		forn(i, 4)
			forn(j, 4) {
				int a;
				scanf("%d", &a);
				--a;
				if  (i == row)
					can2 |= 1 << a;
			}	

		int cnt = __builtin_popcount(can1 & can2);
		if  (cnt <= 0) {
			printf("Case #%d: Volunteer cheated!\n", it + 1);
		}
		if  (cnt == 1) {
			printf("Case #%d: %d\n", it + 1, __builtin_ctz(can1 & can2) + 1);
		}
		if  (cnt > 1) {
			printf("Case #%d: Bad magician!\n", it + 1);
		}
	}
		
	return 0;
}
