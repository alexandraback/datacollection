#include <cstdio>
#include <cstdlib>
#include <cctype>

int B, m[1000];
long long N;

long long getcnt(long long ttt) {
	long long cnt = 0;
	for (int i = 0; i < B; ++i) {
		cnt += ttt / m[i];
		if (ttt % m[i]) ++cnt;
	}
	return cnt;
}

long long work() {
	long long begin = 0, end = N * m[0];
	while (begin < end - 1) {
		long long mid = (begin + end) / 2;
		long long cnt = getcnt(mid);
		if (cnt <= N - 1) begin = mid;
		if (cnt >= N) end = mid;
	}
	return begin;
}

int main() {
	FILE *fp = fopen("B-small-attempt0.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T;
	fscanf(fp, "%d", &T);
	for (int i = 0; i < T; ++i) {
		fscanf(fp, "%d %lld", &B, &N);
		for (int j = 0; j < B; ++j)
			fscanf(fp, "%d", &m[j]);
		long long ttt = work();
		long long cnt = getcnt(ttt);
		int x = N - cnt;
		for (int j = 0; j < B; ++j) {
			if (ttt % m[j] == 0) {
				--x;
				if (x == 0) {
					fprintf(fout, "Case #%d: %d\n", i + 1, j + 1);
					break;
				}
			}
		}
	}
	fclose(fp);
	fclose(fout);
	return 0;
}