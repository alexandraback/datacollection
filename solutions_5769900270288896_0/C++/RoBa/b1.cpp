#include <cstdio>
#include <cstring>
using namespace std;

int R, C, N;
int tmp[20][20];

int calc(int tmp[20][20]) {
	int s = 0;
	for (int i = 0 ; i < R ; ++i)
		for (int j = 0 ; j < C ; ++j) {
			if (tmp[i][j] && tmp[i+1][j]) ++s;
			if (tmp[i][j] && tmp[i][j+1]) ++s;
		}
	return s;
}

int cnt_dig(int k) {
	int s = 0;
	while (k) {
		if (k & 1) ++s;
		k /= 2;
	}
	return s;
}
int main() {
	int T;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d%d%d",&R,&C,&N);
		memset(tmp, 0, sizeof(tmp));
		int best = 1e9;
		for (int mask = 0 ; mask < (1<<(R*C)) ; ++mask) {
			if (cnt_dig(mask) != N) continue;
			for (int i = 0 ; i < R * C ; ++i) {
				if (mask & (1<<i)) tmp[i/C][i%C] = 1;
				else tmp[i/C][i%C] = 0;
			}
			int cnt = calc(tmp);
			if (cnt < best) best = cnt;
		}
		printf("Case #%d: %d\n", ca, best);
	}
	return 0;
}