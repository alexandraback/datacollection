#include <iostream>
#include <cassert>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long LL;

const int MAXN = 3000;

int N;
LL X[MAXN], Y[MAXN];

// res[i] := min number of points to remove s.t. point 'i' is on hull
int res[MAXN];

int nPointsToLeft(LL x1, LL y1, LL x2, LL y2) {
	int sum = 0;
	for (int k = 0; k < N; k++) {
		// cross product of (P2-P1) x (P3-P1) positive?
		LL a = x2 - x1;
		LL b = y2 - y1;
		LL c = X[k] - x1;
		LL d = Y[k] - y1;
		if (a*d - b*c > 0)
			sum++;
	}
	return sum;
}

int nPointsToRight(LL x1, LL y1, LL x2, LL y2) {
	int sum = 0;
	for (int k = 0; k < N; k++) {
		// cross product of (P2-P1) x (P3-P1) negative?
		LL a = x2 - x1;
		LL b = y2 - y1;
		LL c = X[k] - x1;
		LL d = Y[k] - y1;
		if (a*d - b*c < 0)
			sum++;
	}
	return sum;
}

void solve() {
	for (int i = 0; i < N; i++) {
		// solve for res[i]
		res[i] = N;
		if (N == 1)
			res[i] = 0;
		// potential hull segments
		for (int j = 0; j < N; j++) if (i != j) {
			int a = nPointsToLeft(X[i], Y[i], X[j], Y[j]);
			int b = nPointsToRight(X[i], Y[i], X[j], Y[j]);
			res[i] = min(res[i], min(a, b));
		}
	}
}

int main() {
	int ncases;
	cin >> ncases;
	for (int icase = 1; icase <= ncases; icase++) {
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> X[i] >> Y[i];
			
		solve();
		
		cout << "Case #" << icase << ":" << endl;
		// print result array
		for (int i = 0; i < N; i++)
			cout << res[i] << endl;
	}
	return 0;
}
