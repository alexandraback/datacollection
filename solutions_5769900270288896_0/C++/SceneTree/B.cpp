#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <string.h>

using namespace std;

const double pi = acos(-1.0);
const double eps = 1E-7;

typedef long long int64;
typedef unsigned long long uint64;
#define two(X) (1<<(X))
#define twoL(X) (((int64)(1))<<(X))
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sqr(x) ((x)*(x))
#define Abs(x) ((x) < 0 ? (-(x)) : (x))
typedef pair<int,int> ipair;
#define SIZE(A) ((int)A.size())
#define MP(A,B) make_pair(A,B)
#define PB(X) push_back(X)
#define ME(a) memset((a), 0, sizeof((a)))
#define MM(a, b) memcpy((a), (b), sizeof((a)))
#define FOR(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define REP(i,a,b) for (int (i) = (a); (i) < (b); ++(i))

int n, m, p;
int a[1000][1000];
int Tests;

int main()
{
	int tts = 0;
	for (scanf("%d", &Tests); Tests--; ) {
		scanf("%d%d%d", &n, &m, &p);
		int ans = 2 * n * m;
		for (int s = 0; s < two(n * m); ++s) {
			int k = 0;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					if (contain(s, i * m + j)) {
						a[i][j] = 1; 
						++k;
					} else a[i][j] = 0;
			if (k == p) {
				int tmp = 0;
				for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j) {
					if (i < n - 1 && a[i][j] == 1 && a[i + 1][j] == 1) {
						++tmp;
					} 
					if (j < m - 1 && a[i][j] == 1 && a[i][j + 1] == 1) {
						++tmp;
					}
				}
				ans = min(ans, tmp);
			}
		}
		printf("Case #%d: %d\n", ++tts, ans);
	}
	return 0;
}