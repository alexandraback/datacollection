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
const int N = 100;
int t, n, m, k, a[N][N];

int main() {
//	assert(freopen(taskname".in", "r", stdin));
//	assert(freopen(taskname".out", "w", stdout));
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d%d%d", &n, &m, &k);
		int best = n * m * 4;
		for (int mask = 0; mask < (1 << (n * m)); ++mask) {
			int sum = 0;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j)
					a[i][j] = ((mask >> (i * m + j)) & 1), sum += a[i][j];
			if (sum != k) continue;
			int bad = 0;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < m; ++j) {
					if ((i + 1 < n) && a[i][j] && a[i + 1][j]) bad++;
					if ((j + 1 < m) && a[i][j] && a[i][j + 1]) bad++;
				}
			best = min(best, bad);
		}
		printf("Case #%d: %d\n", it + 1, best);
	}	
	return 0;
}
