#include <cstdio>
#include <vector>
#include <algorithm>
#define maxB 1000

using namespace std;

typedef unsigned long long u64;

int M[maxB];
int N, B;

u64 served(u64 t) {
	u64 s = 0;
	for (int i = 0; i < B; ++i) {
		s += 1 + t / (u64)M[i];
	}
	return s;
}

void solve_case(int cn) {
	scanf("%d%d", &B, &N);
	for (int i = 0; i < B; ++i) {
		scanf("%d", &M[i]);
	}

	int min_m = *min_element(M, M+B);

	u64 l = 0;
	u64 r = (u64)N * (u64)min_m + (u64)1;

	while (l < r) {
		u64 m = (l+r)/2;
		u64 s = served(m);

		//printf("%llu %llu %llu \n", l, r, s);

		if (s >= N) {
			r = m;
		} else {
			l = m + 1;
		}
	}

	u64 time_served = l;

	int Nprev = 0;
	if (time_served > 0) {
		Nprev = served(time_served-1);
	}

	int b = -1;
	while (Nprev < N) {
		++Nprev;
		for (++b; time_served % M[b]; ++b);
	}

	printf("Case #%d: %d\n", cn, b+1);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		solve_case(t);
	}
	return 0;
}
