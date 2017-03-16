#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int solve(int r, int c, int n) {
	if (r * c == 1 || n == 0) {
		return 0;
	}

	if (n <= (r * c + 1) / 2) {
		return 0;
	}

	int big = max(r, c);
	int small = min(r, c);

	int max_wall = (big - 1) * small + (small - 1) * big;
	int rest = r * c - n;

	if (small == 1) {
		return max_wall - rest * 2;
	}

	bool isEven = (r * c % 2 == 0);

	int area2[2], area3[2], area4[2];
	area2[0] = isEven ? 2 : 4;
	area2[1] = 4 - area2[0];

	int area_2_3 = (big - 2 + small - 2) * 2 + 4;
	area3[0] = area_2_3 / 2 - area2[0];
	area3[1] = area_2_3 - 4 - area3[0];

	int area4_tot = (big - 2) * (small - 2);
	area4[0] = (area4_tot + 1) / 2;
	area4[1] = area4_tot - area4[0];

// printf("4 %d %d\n", area4[0], area4[1]);
// printf("3 %d %d\n", area3[0], area3[1]);
// printf("2 %d %d\n", area2[0], area2[1]);

	int max_del_wall = 0;
	for (int i = 0; i < 2; i++) {
		int tmp = rest;
		int del_wall = 0;
// printf("tmp %d, del_wall %d\n", tmp, del_wall);

		int del = min(tmp, area4[i]);
		del_wall += del * 4;
		tmp -= del;
// printf("tmp %d, del_wall %d\n", tmp, del_wall);

		del = min(tmp, area3[i]);
		del_wall += del * 3;
		tmp -= del;
// printf("tmp %d, del_wall %d\n", tmp, del_wall);

		del = min(tmp, area2[i]);
		del_wall += del * 2;
		tmp -= del;
// printf("tmp %d, del_wall %d\n", tmp, del_wall);

// printf("%d %d\n", i, del_wall);

		max_del_wall = max(max_del_wall, del_wall);
	}

	return max_wall - max_del_wall;
}

int main() {
	int t, r, c, n;

	cin >> t;
	vector<int> ans(t);

	for (int i = 0; i < t; i++) {
		cin >> r >> c >> n;
		ans[i] = solve(r, c, n);
	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %d\n", i + 1, ans[i]);
	}
	return 0;
}
