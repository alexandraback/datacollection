#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <ctime>


using namespace std;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll rdtsc() {
    ll tmp;
    asm("rdtsc" : "=A"(tmp));
    return tmp;
}

inline int myrand() {
	return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
	return myrand() % x;
}

#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define INF ((int)1e9)
#define sqr(x) ((x) * (x))         
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())

bool solve(int testCase) {
	printf("Case #%d: ", testCase);
	const int n = 4;
	int used[n * n];
	for (int i = 0; i < n * n; ++i)
		used[i] = 0;
	for (int it = 0; it < 2; ++it) {
		int res;
		assert(scanf("%d", &res) == 1);
		--res;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				int x;
				scanf("%d", &x);
				--x;
				if (res == i)
					used[x] += 1;
			}
		}
	}

	int cnt = count(used, used + n * n, 2);
	if (!cnt) {
		printf("Volunteer cheated!\n");
		return 1;
	}

	if (cnt > 1) {
		printf("Bad magician!\n");
		return 1;
	}

	printf("%d\n", find(used, used + n * n, 2) - used + 1);
	return 1;
}

int main() {
	srand(rdtsc());
#ifdef DEBUG
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif
	
	int maxt;
	while (scanf("%d", &maxt) == 1) {
		for (int t = 0; t < maxt; ++t)
			assert(solve(t + 1));
		
		#ifdef DEBUG
			eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
		#endif
	}
	return 0;
}
