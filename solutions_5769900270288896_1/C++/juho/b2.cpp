#include <cstdio>
#include <cstdlib>
#include <cstring>	

using namespace std;

void runCase();

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		printf("Case #%d: ", t);
		runCase();
	}
}

// algorithms
int R, C, N;
char map[16];

int check(int set[])
{
	int cnt = 0;
	memset(map, 0, R * C * sizeof(char));
	for (int i = 0; i < N; i++) {
		map[set[i]] = 1;
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			int idx = i * C + j;
			if (map[idx]) {
				if (j != C - 1 && map[idx + 1]) {
					cnt++;
				}
				if (i != R - 1 && map[idx + C]) {
					cnt++;
				}
			}
		}
	}
	return cnt;
}

int comb(int set[], int set_size, int n, int k, int idx)
{
	if (k == 0) {
		return check(set);
	}
	else if (k > n - idx) {
		return 100000;
	}
	//else if (idx == n) {
	//	return;
	//}
	else {
		set[set_size] = idx;
		int v1 = comb(set, set_size + 1, n, k - 1, idx + 1);
		int v2 = comb(set, set_size, n, k, idx + 1);
		return v1 < v2 ? v1 : v2;
	}
}

int getMin()
{
	int r1 = (R + 1) / 2;
	int c1 = (C + 1) / 2;
	int r2 = R / 2;
	int c2 = C / 2;
	int rem = N - (r1 * c1 + r2 * c2);
	if (rem <= 0) {
		return 0;
	}
	int d2 = 2;
	if ((R & 1) && (C & 1)) {
		d2 = 0;
	}
	int d3 = r2 * 2 + c2 * 2 - d2;

	int res = 0;
	if (rem <= d2) {
		return res + rem * 2;
	}
	res += d2 * 2;
	rem -= d2;
	if (rem <= d3) {
		return res + rem * 3;
	}
	res += d3 * 3;
	rem -= d3;
	return res + rem * 4;
}

void runCase()
{
	scanf("%d %d %d", &R, &C, &N);

	int mval = getMin();
	//if (R * C < 17) {
	//	int set[16];
	//	int msval = comb(set, 0, R * C, N, 0);
	//	if (msval == mval) {
	//		fprintf(stderr, "OK\n");
	//	}
	//	else {
	//		fprintf(stderr, "NOK\n");
	//	}
	//}

	printf("%d\n", mval);
}
