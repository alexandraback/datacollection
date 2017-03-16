#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

static void debug(int B, int N, long int *C)
{
	fprintf(stderr, "N = %d\n", N);
	for (int i = 1; i <= B; i++)
		fprintf(stderr, "%ld ", C[i]);
	fprintf(stderr, "\n");
}

static int solve(int B, int N, int *M, long int *C)
{
	int *t;
	t = malloc((size_t)B * sizeof(*t));
	while (1) {
		long int m;
		int j = 1;
		debug(B, N, C);
		m = C[1] * M[1];
		t[0] = 1;
		for (int i = 2; i <= B; i++) {
			long int a = C[i] * M[i];
			if (a < m) {
				m = a;
				j = 1;
				t[0] = i;
			} else if (a == m) {
				t[j++] = i;
			}
		}
		for (int i = 0; i < j; i++) {
			int y = t[i];
			if (--N == 0) {
				free(t);
				return y;
			}
			C[y]++;
		}
	}
}

int main(void) {
	int T;
	assert(scanf("%d", &T) == 1);
	for (int t = 1; t <= T; t++) {
		int B, N, *M, y;
		double R = 0;
		long int *C;
		fprintf(stderr, "Case #%d:\n", t);
		assert(scanf("%d", &B) == 1);
		assert(scanf("%d", &N) == 1);
		M = malloc((size_t)(B + 1) * sizeof(*M));
		C = malloc((size_t)(B + 1) * sizeof(*C));
		for (int i = 1; i <= B; i++) {
			assert(scanf("%d", &M[i]) == 1);
			R += 1. / (double)M[i];
		}
		R = (double)(N - 1) / R;
		fprintf(stderr, "R=%f\n", R);
		for (int i = 1; i <= B; i++) {
			C[i] = (long int)(R / (double)M[i]);
			N -= C[i];
		}
		assert(N > 0);
		y = solve(B, N, M, C);
		free(C);
		free(M);
		printf("Case #%d: %d\n", t, y);
	}
	return 0;
}
