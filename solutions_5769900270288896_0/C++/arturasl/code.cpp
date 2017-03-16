#include      <algorithm>
#include      <cmath>
#include      <cstdarg>
#include      <cstdio>
#include      <cstdlib>
#include      <iomanip>
#include      <iostream>
#include      <iterator>
#include      <limits>
#include      <list>
#include      <map>
#include      <set>
#include      <queue>
#include      <vector>
#define endl '\n'
#define each(c, e) for (typeof(c.begin()) e = c.begin(); e != c.end(); ++e)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

bool M[100][100];
const int oo = numeric_limits<int>::max();

int calc(bool M[100][100], int R, int C) {
	int r = 0;
	for (int i = 0; i < R; i += 1) {
		for (int j = 0; j < C; j += 1) {
			r += j + 1 < C && M[i][j] && M[i][j + 1];
			r += i + 1 < R && M[i][j] && M[i + 1][j];
		}
	}
	return r;
}

int solve() {
	int R, C, N;
	cin >> R >> C >> N;
	const int S = R * C;

	int rez = +oo;

	for (int i = 0; i < (1 << S); i += 1) if (__builtin_popcount(i) == N) {

		for (int k = 0; k < R; k += 1) {
			for (int l = 0; l < C; l += 1) M[k][l] = false;
		}

		for (int j = 0; j < S; j += 1) if ((1 << j) & i) M[j / C][j % C] = true;

		rez = min(rez, calc(M, R, C));
	}

	return rez;
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1) {
		cout << "Case #" << t << ": " << solve() << endl;
	}
	return 0;
}
