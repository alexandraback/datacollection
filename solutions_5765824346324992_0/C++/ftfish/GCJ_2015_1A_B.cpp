#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int mb = 1010;
const LL MAXTIME = 100000000000000LL;

int B, N;
int M[mb];
int rest[mb];

LL gcd(LL a, LL b) {
	return !b ? a: gcd(b, a % b);
}
LL lcm(LL a, LL b) {
	return a * b / gcd(a, b);
}

int main() {
	int Tc;
	scanf("%d", &Tc);
	for (int Tn = 1; Tn <= Tc; ++Tn) {
		scanf("%d%d", &B, &N);
		for (int i = 0; i < B; ++i) {
			scanf("%d", M + i);
		}
		int ans = 1;
		if (N <= B)
			ans = N;
		else {
			LL X = 1;
			for (int i = 0; i < B; ++i)
				X = lcm(X, M[i]);
//			cout << "lcm = " << X << endl;
			LL roundn = 0;
			for (int i = 0; i < B; ++i)
				roundn += X / M[i];
//			cout << "roundn = " << roundn << endl;
			if (N > roundn) {
				N = roundn + N % roundn;
			}
//			cout << "newn = " << N << endl;
			for (int i = 0; i < B; ++i)
				rest[i] = 0;
			for (int i = 0; i < N; ++i) {
				int mp = 0;
				for (int j = 0; j < B; ++j)
					if (rest[j] < rest[mp]) {
						mp = j;
					}
				rest[mp] += M[mp];
				if (i == N - 1) ans = mp + 1;
			}

		}
		printf("Case #%d: ", Tn);
		printf("%d\n", ans);
	}
	return 0;
}
