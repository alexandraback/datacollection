#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
#define MP(a, b) make_pair(a, b)
#define FOREACH(e,x) for(__typeof(x.begin()) e=x.begin();e!=x.end();++e)

const int maxn = 1000 + 5;
int n, mush[maxn];

int main() {
//freopen("in", "r", stdin);
//freopen("A-small-attempt0.in", "r", stdin);
//freopen("A-small-attempt0.out", "w", stdout);
//freopen("A-large.in", "r", stdin);
//freopen("A-large.out", "w", stdout);
	int test;	scanf("%d", &test);
	for (int ti = 1; ti <= test; ti++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", mush + i);

		int res1 = 0, res2 = 0, v2 = 0;
		for (int i = 0; i < n - 1; i++) {
			res1 += max(0, mush[i] - mush[i + 1]);
			v2 = max(v2, mush[i] - mush[i + 1]);
		}

		for (int i = 0; i < n - 1; i++) {
			int tmp = min(mush[i], v2);
			res2 += tmp;
		}
		printf("Case #%d: %d %d\n", ti, res1, res2);
	}
	return 0;
}
