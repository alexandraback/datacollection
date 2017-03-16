#include <bits/stdc++.h>
using namespace std;

int main() {
	int TC, N, m[1000];
	cin >> TC;
	for (int tc=1; tc<=TC; tc++) {
		cin >> N;
		for (int n = 0; n < N; n++) cin >> m[n];
		int a1 = 0, r2 = 0, a2 = 0;
		for (int n = 1; n < N; n++) {
			if (m[n] < m[n-1]) {
				a1 += m[n-1] - m[n];
				r2 = max(r2, m[n-1] - m[n]);
			}
		}
		for (int n = 1; n < N; n++) {
			a2 += min(m[n-1], r2);
		}
		cout << "Case #" << tc << ": " << a1 << " " << a2 << endl;
	}
}
