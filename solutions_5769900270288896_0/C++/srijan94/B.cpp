#include <cstdio>
#include <cstring>

using namespace std;

int R, C, N;
int a[17][17];

int min(int p, int q) {
	return (p < q ? p : q);
}

int countBits(int x) {
	int ret = 0;
	while(x > 0) {
		if(x % 2 == 1) ret++;
		x = x / 2;
	}
	return ret;
}

void setGrid(int place) {
	int i, j, curr = 0;
	for(i = 0; i < R; i++) {
		for(j = 0; j < C; j++) {
			if(place == curr) {
				a[i][j] = 1;
				return;
			}
			curr++;
		}
	}
}

int evaluate(int x) {
	memset(a, 0, sizeof(a));
	int ret = 0, i, j, place = 0;
	while(x > 0) {
		if(x % 2 == 1) {
			setGrid(place);
		}
		x = x / 2;
		place++;
	}
	for(i = 0; i < R; i++) {
		for(j = 0; j < C - 1; j++)
			if((a[i][j] + a[i][j + 1]) == 2)
				ret++;
	}
	for(i = 0; i < R - 1; i++) {
		for(j = 0; j < C; j++)
			if((a[i][j] + a[i + 1][j]) == 2)
				ret++;
	}
	return ret;
}

int main(int argc, char const *argv[])
{
	freopen("iSB.in", "r", stdin);
	freopen("oSB.txt", "w", stdout);
	int i, tc, T, ans, pow2[18];
	pow2[0] = 1; pow2[1] = 2;
	for(i = 2; i <= 17; i++)
		pow2[i] = pow2[i - 1] * 2;

	scanf("%d", &T);
	for(tc = 1; tc <= T; tc++) {
		scanf("%d%d%d", &R, &C, &N);
		ans = 100000000;
		for(i = 0; i < pow2[R * C]; i++) {
			if(countBits(i) != N) continue;
			ans = min(ans, evaluate(i));
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}