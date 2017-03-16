
#include <iostream>

#include <algorithm>

using namespace std;


struct party {
	char letter;
	int size;
};

bool cmp(const party &a, const party &b) {
	return a.size > b.size;
}

void evac(party *P, int N, int p) {
	static int space = 2;

	if (p < 0) {
		if (space != 2) {
			cout << ' ';
			space = 2;
		}
	} else {
		cout << P[p].letter;
		P[p].size--;
		space--;
		if (space == 0) {
			cout << ' ';
			space = 2;
		}
	}
}

void solve() {
	int N;

	cin >> N;

	party P[N];
	for (int i = 0; i < N; i++) {
		P[i].letter = 'A' + i;
		cin >> P[i].size;
	}

	sort(P, P+N, cmp);

	while (P[0].size > P[1].size) {
		evac(P, N, 0);
	}

	for (int i = N-1; i >= 2; i--) {
		while (P[i].size > 0) {
			evac(P, N, i);
		}
	}

	evac(P, N, -1);

	for (int i = 0; i < P[0].size; i++) {
		cout << P[0].letter << P[1].letter;
		if (i != P[0].size-1) cout << ' ';
	}
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cout << "Case #" << t << ": ";
		solve();
		cout << endl;
	}
}

