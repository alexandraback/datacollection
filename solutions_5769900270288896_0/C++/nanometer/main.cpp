#include <cstdio>
#include <cstring>

const int N = 11111;
int color[N];

int r, c, n;

int num(int x, int y) {
	return x * c + y;
}

int num_color(int x, int y) {
	if (x < 0 || x >= r || y < 0 || y >= c) return 0;
	return color[num(x, y)];
}

void fill(int x, int y) {
	color[num(x, y)] = 1;
}

int calc() {
	int result = 0xFF, rx, ry;
	for (int x = 0; x < r; ++ x) {
		for (int y = 0; y < c; ++ y) {
			if (color[num(x, y)]) continue;
			int t = num_color(x - 1, y)
				+ num_color(x + 1, y)
				+ num_color(x, y - 1)
				+ num_color(x, y + 1);
			if (t < result) {
				result = t;
				rx = x;
				ry = y;
			}
			//printf("%d %d %d\n", x, y, t);
		}
	}
	//printf("%d %d %d\n", rx, ry, result);
	fill(rx, ry);
	return result;
}

int solve() {
	if (n == 0) return 0;

	int result_A = 0;
	memset(color, 0, sizeof(color));
	fill(0, 0);
	for (int i = 1; i < n; ++ i) {
		result_A += calc();
		//printf("\n");
	}
	
	int result_B;
	if (c > 1) {
		result_B = 0;
		memset(color, 0, sizeof(color));
		fill(0, 1);
		for (int i = 1; i < n; ++ i) {
			result_B += calc();
		}
	} else {
		result_B = 0x7FFFFFFF;
	}

	return result_A < result_B ? result_A : result_B;
}

int main(void) {
	int test_count;
	scanf("%d", &test_count);
	for (int test = 1; test <= test_count; ++ test) {
		scanf("%d%d%d", &r, &c, &n);
		printf("Case #%d: %d\n", test, solve());
	}
	return 0;
}
