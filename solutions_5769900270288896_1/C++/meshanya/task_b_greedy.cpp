#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define int64 long long
#define ldb long double
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define taskname "task_b"
const ldb pi = acos(-1.0);
const int N = 1e4 + 10;
int t, n, m, k;
char a[N][N];

int mega(int n, int m, int k) {
	int best = n * m * 4;
	for (int color = 0; color < 2; ++color) {
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				a[i][j] = (((i + j) % 2) ^ color);
		int sum = 0;
		vector<int> costs;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (a[i][j])
					costs.pb(0);
				else {
					int tmp = 0;
					if ((i > 0) && a[i - 1][j]) tmp++;
					if ((j > 0) && a[i][j - 1]) tmp++;
					if ((i + 1 < n) && a[i + 1][j]) tmp++;
					if ((j + 1 < m) && a[i][j + 1]) tmp++;
					costs.pb(tmp);
				}
		sort(costs.begin(), costs.end());
		for (int i = 0; i < k; ++i)
			sum += costs[i];
		best = min(best, sum);
	}
	return best;
}

int main() {
//	assert(freopen(taskname".in", "r", stdin));
//	assert(freopen(taskname".out", "w", stdout));
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d%d%d", &n, &m, &k);
		printf("Case #%d: %d\n", it + 1, mega(n, m, k));
		eprintf("%d %d %d: %d\n", n, m, k, mega(n, m, k));
	}	
	return 0;
}
