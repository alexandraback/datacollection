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

void runCase()
{
	scanf("%d %d %d", &R, &C, &N);
	int set[16];

	int mval = comb(set, 0, R * C, N, 0);
	printf("%d\n", mval);
}
