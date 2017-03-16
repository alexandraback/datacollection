#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 10;
int a[maxN][maxN], b[maxN][maxN];

void solve(int test) {
	int n = 4;
	int x, y;
	scanf("%d", &x);
	--x;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d", &y);
	--y;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &b[i][j]);
		}
	}

	map < int, int > M;
	for (int i = 0; i < n; ++i) {
		++M[a[x][i]];
		++M[b[y][i]];
	}

	vector < int > res;
	for (map < int, int > ::iterator it = M.begin(); it != M.end(); ++it) {
		if (it->second == 2) {
			res.push_back(it->first);
		}
	}

	printf("Case #%d: ", test);
	if (res.size() == 1) {
		printf("%d\n", res[0]);
	} else if (res.size() > 1) {
		printf("Bad magician!\n");
	} else {
		printf("Volunteer cheated!\n");
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << (i + 1) << endl;
	}
	cerr << "Time: " << clock() << endl;
	return 0;
}