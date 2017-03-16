#include <bits/stdc++.h>

using namespace std;

int vett[10000];
int a, b;

void solve() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> vett[i];
	a = 0, b = 0;
	int x = 0;
	for (int i = 1; i < N; i++)
		if (vett[i] < vett[i-1]) {
			a += vett[i-1] - vett[i];
			x = max(x, vett[i-1]-vett[i]);
		}
	for (int i = 0; i < N-1; i++) {
		b += min(x, vett[i]);
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cerr << "Caso " << t << "/" << T << endl;
		solve();
		cout << "Case #" << t << ": " << a << " " << b << endl;
	}
}
