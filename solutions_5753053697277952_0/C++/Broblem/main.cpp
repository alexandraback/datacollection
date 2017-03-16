#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define deg(a) cout << #a << " = " << a << '\n'

using namespace std;

const int N = 2e6;

int  n, p[60];

bool check() {
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		sum += p[i];
		if (p[i] < 0) return false;
	}
	for (int i = 0; i < n; ++i) {
		if (p[i] > sum / 2) return false;
	}
	return true;
}

void out(int i, int j) {
	if (j != -1)
		cout << char('A' + i) << char('A' + j) << ' ';
	else
		cout << char('A' + i) << ' ';
}

void solve(int test) {
	cout << "Case #" << test << ": ";
	cin >> n;
	int s = 0;
	for (char i = 0; i < n; ++i) {
		cin >> p[i];
		s += p[i];
	}
	while (s) {
		int mx0 = -1, mx1 = -1, id0, id1;
		for (int i = 0; i < n; ++i) {
			if (p[i] > mx0) {
				mx1 = mx0;
				id1 = id0;
				mx0 = p[i];
				id0 = i;
			} else if (p[i] > mx1) {
				mx1 = p[i];
				id1 = i;
			}
		}
		p[id0] -= 2;
		if (check()) {
			out(id0, id0);
			s -= 2;
			continue;
		}
		p[id0] += 2;
		p[id0]--;
		p[id1]--;
		if (check()) {
			out(id0, id1);
			s -= 2;
			continue;
		}
		p[id1]++;
		if (check()) {
			out(id0, -1);
			--s;
			continue;
		}
		assert(false);
	}
	cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
#ifdef KOBRA
	freopen("toster", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
#endif // KOBRA
	int cases;
	cin >> cases;
	for (int i = 1; i <= cases; ++i) {
		solve(i);
	}
	return 0;
}
