#include <cstdio>

int row, col;
int table[16][16] = {};

int f(int r, int c, int left) {
	if (left == 0) return 0;
	if (c == col) return 0;
	if (r == row) return f(0, c+1, left);

	// Place here
	table[r][c] = 1;
	int ans = 0;
	if (r > 0 && table[r-1][c] == 1) ans++;
	if (c > 0 && table[r][c-1] == 1) ans++;
	ans += f(r + 1, c, left - 1);
	table[r][c] = 0;

	// Don't place here
	int ans2;
	if (row * col - c * row - r > left) {
		ans2 = f(r + 1, c, left);
		if (ans2 < ans) ans = ans2;
	}

	return ans;
}

void calc() {
	int n;

	scanf("%d %d %d", &row, &col, &n);

	printf("%d\n", f(0, 0, n));
}

int main() {
	int testcase, t;

	scanf("%d", &testcase);
	for (t = 1; t <= testcase; t++) {
		printf("Case #%d: ", t);

		calc();
	}

	return 0;
}
