#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
using namespace std;

void openFiles() {
#ifndef ONLINE_JUDGE
	freopen("A-small-attempt0.in", "rt", stdin);
	//freopen("test.out", "wt", stdout);
#endif
}

void solve() {
	int r1, r2, g1[4][4], g2[4][4];
	scanf("%d ", &r1); r1--;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d ", &g1[i][j]);
		}
	}
	scanf("%d ", &r2); r2--;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			scanf("%d ", &g2[i][j]);
		}
	}
	set<int> s1, s2;
	for (int j = 0; j < 4; j++) {
		s1.insert(g1[r1][j]);
	}
	for (int j = 0; j < 4; j++) {
		s2.insert(g2[r2][j]);
	}
	vector<int> r(10);
	vector<int>::iterator ii = set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), r.begin());
	r.resize(ii - r.begin());

	static int ntest = 0;
	if (r.size() == 1) {
		printf("Case #%d: %d\n", ++ntest, r[0]);
	} else if (r.size() == 0) {
		printf("Case #%d: Volunteer cheated!\n", ++ntest);
	} else {
		printf("Case #%d: Bad magician!\n", ++ntest);
	}
}


int main() {
	openFiles();
	int n; scanf("%d ", &n);
	for (int i = 0; i < n; i++) solve();

	return 0;
}
