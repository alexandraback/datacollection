#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cassert>
#include <memory.h>
#include <ctype.h>
  
#include <iostream>
  
#include <string>
#include <complex>
#include <numeric>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <sstream>
  
using namespace std;
  
template<typename TYPE> inline TYPE sqr(const TYPE& a) { return (a) * (a); }
  
#define forn(i, n) for(int i = 0; i < int(n); ++i)
#define for1(i, n) for(int i = 1; i <= int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
  
typedef long long li;
typedef double ld;
typedef pair<int, int> pt;
  
const int INF = 1000 * 1000 * 1000;
const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 100;

int main() {
	int tests;
	scanf("%d", &tests);
	for1(it, tests) {
		int a[2];
		forn(id, 2) {
			a[id] = 0;
			int tip;
			scanf("%d", &tip);
			forn(i, 4) {
				forn(j, 4) {
					int t;
					scanf("%d", &t);
					if (i + 1 == tip)
						a[id] |= 1 << t;
				}
			}
		}
		printf("Case #%d: ", it);
		int ans = a[0] & a[1];
		if (ans == 0)
			puts("Volunteer cheated!");
		else if (ans & (ans - 1))
			puts("Bad magician!");
		else {
			int cnt = 0;
			while (ans > 1) {
				++cnt;
				ans >>= 1;
			}
			printf("%d\n", cnt);
		}
	}
  
    return 0;
}
