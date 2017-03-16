#include <cstdio>
#include <algorithm>

using namespace std;

int m[20][20];
int min_unhappy;

int unhappy(int r, int c)
{
	int ans = 0;
	for (int i = 0; i < r - 1; i++) {
		for (int j = 0; j < c; j++) {
			ans += (m[i][j] & m[i + 1][j]);
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c - 1; j++) {
			ans += (m[i][j] & m[i][j + 1]);
		}
	}

	return ans;
}

void brute_force(int r, int c, int rr, int cc, int n) {
	if (n < 0) return;
	if (min_unhappy == 0) return;
	if (r == rr) { // stop
		// printf("n = %d\n", n);
		if (n == 0) {
			min_unhappy = min(min_unhappy, unhappy(rr, cc));
		}
	} else if (c == cc) { // next row
		brute_force(r + 1, 0, rr, cc, n);
	} else {
		for (int x = 0; x <= 1; x++) {
			m[r][c] = x;
			brute_force(r, c + 1, rr, cc, n - x);
		}
	}
}

int solve(int r, int c, int n) // r >= c
{
	if (r < c) return solve(c, r, n);
	
	// for (int i = 0; i < 20; i++)
	// 	for (int j = 0; j < 20; j++)
	// 		m[i][j] = 0;
	// min_unhappy = 10000;
	// brute_force(0, 0, r, c, n);
	// return min_unhappy;

	int walls = (r - 1) * c + (c - 1) * r;
	int empty = r * c - n;

	if (n <= 1) return 0;
	if (r * c == n) return walls;
	if (n <= (1 + r * c) / 2) return 0;
	
	if (c == 1) return walls - 2 * empty;

	int ans = walls;

	// try the center core
	int center_blocks = (c - 2) * (r - 2);

	if (r & c & 1) { // all odd
		int c_center = (center_blocks + 1) / 2;
		int c_side = (r * c + 1) / 2 - c_center - 4;
		int c_max = min(c_center, empty) * 4 + max(min(c_side, empty - c_center), 0) * 3 + max(0, empty - c_center - c_side) * 2;

		int oc_center = c_center - 1;
		int oc_side = (r * c - 1) / 2 - oc_center;
		int oc_max = min(oc_center, empty) * 4 + max(min(oc_side, empty - oc_center), 0) * 3;

		return walls - max(c_max, oc_max);
	} else { // has even
		if (empty <= (center_blocks + 1) / 2) {
			return ans - empty * 4;
		} else {
			empty -= ((center_blocks + 1) / 2);
			ans -= ((center_blocks + 1) / 2) * 4;
		}

		int side_blocks = (r - 2) + (c - 2);
		if (empty <= side_blocks) {
			return ans - empty * 3;
		} else {
			empty -= side_blocks;
			ans -= side_blocks * 3;
		}
	}

	ans -= empty * 2;
	return ans;
}

int main()
{
	int t_max;
	scanf("%d", &t_max);
	for (int t = 1; t <= t_max; t++) {
		int r, c, n;
		scanf("%d %d %d", &r, &c, &n);
		printf("Case #%d: %d\n", t, solve(r, c, n));
	}
}