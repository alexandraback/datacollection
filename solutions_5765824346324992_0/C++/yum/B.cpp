#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {
	LL TC, B, N, M[1000];
	cin >> TC;
	for (LL tc=1; tc<=TC; tc++) {
		cin >> B >> N;
		for (LL b = 0; b < B; b++) cin >> M[b];
		LL t0 = 0, t1 = 1000000000000000;
		for (;;) {
			LL t2 = (t0 + t1) / 2, spb = 0;
			for (LL b = 0; b < B; b++) spb += (t2 + M[b] - 1) / M[b];
			if (N <= spb) {
				t1 = t2;
				continue;
			}
			for (LL b = 0; b < B; b++) if (t2 % M[b] == 0) {
				spb++;
				if (spb == N) {
					cout << "Case #" << tc << ": " << b+1 << endl;
					goto done;
				}
			}
			t0 = t2;
		}
		done:;
	}
}
