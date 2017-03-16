#include <iostream>
#include <iomanip>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <functional>
#include <string>
#include <cstring>
#include <complex>
#include <random>
#include <math.h>
#include <unordered_map>

#define INF 2000000000
#define LLINF 9000000000000000000LL
#define LDINF 1e200

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef long long ll;
typedef long double ld;

int checkerboard1(int R, int C, int N) {
	int v1 = R * C - (R * C) / 2;
	N -= v1;

	if (N <= 0) return 0;

	int Rtop = R / 2, Ctop = C / 2, Rbot, Cbot;
	Rbot = (C % 2 == 0) ? (R - Rtop) : Rtop;
	Cbot = (R % 2 == 0) ? (C - Ctop) : Ctop;
	int threes = Rtop + Ctop + Rbot + Cbot, twos = 0;

	
	if ((R % 2 == 0) || (C % 2 == 0))
		twos = 2;
	threes -= 2 * twos;

	int cost = 0;
	cost += min(twos, N) * 2;
	N -= twos;
	if (N <= 0) return cost;

	cost += min(N, threes) * 3;
	N -= threes;
	if (N <= 0) return cost;

	return (cost + N * 4);
}

int checkerboard2(int R, int C, int N) {
	int v1 = (R * C) / 2;
	N -= v1;

	if (N <= 0) return 0;
	
	int Rtop = R - R / 2, Ctop = C - C / 2, Rbot, Cbot;
	Rbot = (C % 2 == 0) ? (R - Rtop) : Rtop;
	Cbot = (R % 2 == 0) ? (C - Ctop) : Ctop;
	int threes = Rtop + Ctop + Rbot + Cbot, twos = 4;

	if ((R % 2 == 0) || (C % 2 == 0))
		twos = 2;
	threes -= 2 * twos;

	int cost = 0;
	cost += min(twos, N) * 2;
	N -= twos;
	if (N <= 0) return cost;

	cost += min(N, threes) * 3;
	N -= threes;
	if (N <= 0) return cost;

	return (cost + N * 4);
}

int main() {

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {

		int R, C, N;
		cin >> R >> C >> N;
		int ans = 0;
		if (R > C) swap(R, C);

		if (R == 1) {

			N -= C - C / 2;
			if (N <= 0) ans = 0;
			else {
				if (C % 2 == 0) {
					ans++;
					N -= 1;
				}
				if (N > 0) {
					ans += 2 * N;
				}
			}
		}
		else {
			int c1 = checkerboard1(R, C, N), c2 = checkerboard2(R, C, N);
			ans = min(c1, c2);
		}
		
		cout << "Case #" << t << ": " << ans << endl;
		
	}

	return 0;
}