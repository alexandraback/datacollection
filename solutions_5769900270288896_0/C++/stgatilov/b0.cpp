#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#ifdef HOME
	#define E(c) cerr<<#c
	#define Eo(x) cerr<<#x<<" = "<<(x)<<endl
	#define Ef(...) fprintf(stderr, __VA_ARGS__)
#else
	#define E(c) ((void)0)
	#define Eo(x) ((void)0)
	#define Ef(...) ((void)0)
#endif

const int SIZE = 16;

int r, c, n;
char matr[SIZE][SIZE];

int ans[SIZE*SIZE];
char bestMatr[SIZE*SIZE][SIZE][SIZE];

void SolveRec(int i, int j, int s) {
	if (j == c) return SolveRec(i+1, 0, s);
	if (i == r) {
		int tres = 0;
		for (int u = 0; u < r; u++)
			for (int v = 0; v+1 < c; v++)
				tres += (matr[u][v] == 'X' && matr[u][v+1] == 'X');
		for (int u = 0; u+1 < r; u++)
			for (int v = 0; v < c; v++)
				tres += (matr[u][v] == 'X' && matr[u+1][v] == 'X');
		if (ans[s] > tres) {
			ans[s] = tres;
			memcpy(bestMatr[s], matr, sizeof(matr));
		}
		return;
	}

	SolveRec(i, j+1, s);
	matr[i][j] = 'X';
	SolveRec(i, j+1, s+1);
	matr[i][j] = '.';
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d%d%d", &r, &c, &n);

		memset(matr, 0, sizeof(matr));
		for (int i = 0; i<r; i++)
			for (int j = 0; j<c; j++)
				matr[i][j] = '.';
		memset(ans, 63, sizeof(ans));
		SolveRec(0, 0, 0);

		printf("Case #%d: %d\n", tt, ans[n]);
//		for (int i = 0; i<r; i++) printf("%s\n", bestMatr[n][i]);

/*		printf("Case #%d: %d x %d\n", tt, r, c);
		for (int k = 0; k <= r*c; k++) {
			printf("%d -> %d\n", k, ans[k]);
			for (int i = 0; i<r; i++) printf("%s\n", bestMatr[k][i]);
		}*/
		fflush(stdout);
	}
	return 0;
}
