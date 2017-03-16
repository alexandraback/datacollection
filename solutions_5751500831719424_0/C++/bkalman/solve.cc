#include <cstdio>

using std::scanf;
using std::printf;

const int M = 100;
char S[M][M + 1];
char C[M][M + 1];

static int abs(int n) {
	return n < 0 ? -n : n;
}

static void testcase(int tc) {
	int N;
	scanf("%i", &N);
	for(int i = 0; i < N; ++i)
		scanf("%s", S[i]);
	char templat[M + 1];
	char *s = S[0];
	char *t = templat;
	char p = *s;
	*t++ = *s++;
	while(*s) {
		if(*s != p) {
			*t++ = *s;
			p = *s;
		}
		++s;
	}
	*t = '\0';
	//fprintf(stderr, "template: %s\n", templat);
	for(int i = 0; i < N; ++i) {
		char *c = C[i];
		s = S[i];
		t = templat;
		*c = 0;
		while(*s) {
			while(*s == *t) {
				(*c)++;
				++s;
			}
			if(*c == 0) {
				printf("Case #%d: %s\n", tc, "Fegla Won");
				return;
			}
			++t;
			++c;
			*c = 0;
		}
		if(*t != '\0') {
			printf("Case #%d: %s\n", tc, "Fegla Won");
			return;
		}
	}
	// for(int i = 0; i < N; ++i) {
	// 	for(char *c = C[i]; *c; ++c)
	// 		fprintf(stderr, "%d ", *c);
	// 	fprintf(stderr, "\n");
	// }
	int sumsteps = 0;
	for(int j = 0; templat[j]; ++j) {
		int minsteps = M * M;
		for(int s = 1; s <= M; ++s) {
			int steps = 0;
			for(int i = 0; i < N && steps < minsteps; ++i)
				steps += abs(C[i][j] - s);
			if(steps < minsteps)
				minsteps = steps;
		}
		sumsteps += minsteps;
	}
	printf("Case #%d: %d\n", tc, sumsteps);
}

int main() {
	int T;
	scanf("%i", &T);
	for(int t = 1; t <= T; ++t)
		testcase(t);
}
