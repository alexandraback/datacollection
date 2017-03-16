#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <queue>
#include <cassert>
#include <sstream>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
template<class T> T Abs(T x) { return x < 0 ? -x : x; }
#define FOR(i, n) for(int i = 0; i < (int)(n); ++i)


void Go1(int tt) {
	int R, C, N;
	cin >> R >> C >> N;
	//R = 4; C = 5; N = tt;
	int n = R * C;
	int res = -1;
	for (int mask = 0; mask < 1 << n; mask++) {
		int occupied = 0;
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				occupied++;
			}
		}
		if (occupied != N) {
			continue;
		}
		int unhappiness = 0;
		for (int x = 0; x < R; x++) {
			for (int y = 0; y < C; y++) {
				if (!(mask & (1 << (x * C + y)))) {
					continue;
				}

				if (x > 0 && mask & (1 << ((x - 1) * C + y))) {
					unhappiness++;
				}
				if (y > 0 && mask & (1 << (x * C + y - 1))) {
					unhappiness++;
				}

			}
		}
		if (res == -1 || unhappiness < res) {
			res = unhappiness;
		}
	}
	cout << res << endl;
	for (int mask = 0; mask < 1 << n; mask++) {
		int occupied = 0;
		for (int i = 0; i < n; i++) {
			if (mask & (1 << i)) {
				occupied++;
			}
		}
		if (occupied != N) {
			continue;
		}
		int unhappiness = 0;
		for (int x = 0; x < R; x++) {
			for (int y = 0; y < C; y++) {
				if (!(mask & (1 << (x * C + y)))) {
					continue;
				}

				if (x > 0 && mask & (1 << ((x - 1) * C + y))) {
					unhappiness++;
				}
				if (y > 0 && mask & (1 << (x * C + y - 1))) {
					unhappiness++;
				}

			}
		}
		if (unhappiness == res) {
			for (int x = 0; x < R; x++) {
				for (int y = 0; y < C; y++) {
					cout << ((mask & (1 << (x * C + y))) ? '*' : '.');
				}
				cout << endl;
			}			
			cout << endl;
		}
	}		
}

void Go(int tt) {
	int R, C, N;
	cin >> R >> C >> N;
	auto go = [](int R, int C, int N, int qq)  {
		int unhappiness = 0;
		auto B = vector<vector<int>>(R, vector<int>(C, 0));
		for (int x = 0; x < R; x++) {
			for (int y = 0; y < C; y++) {
				if ((x + y) % 2 == qq) {
					if (N == 0) {
						break;
					}
					B[x][y] = 1;
					N--;
				}
			}
		}
		while (N > 0) {
			int best_d = 5;
			int best_x = -1, best_y = -1;
			for (int x = 0; x < R; x++) {
				for (int y = 0; y < C; y++) {
					if (B[x][y]) {
						continue;
					}
					int d = 0;
					if (x > 0 && B[x - 1][y]) {
						d++;
					}
					if (y > 0 && B[x][y - 1]) {
						d++;
					}
					if (x + 1 < R && B[x + 1][y]) {
						d++;
					}
					if (y + 1 < C && B[x][y + 1]) {
						d++;
					}
					if (d < best_d) {
						best_d = d;
						best_x = x;
						best_y = y;
					}
				}
			}
			B[best_x][best_y] = 1;
			N--;
			unhappiness += best_d;
		}
		return unhappiness;
	};
	cout << min(go(R, C, N, 0), go(R, C, N, 1));
}

int main() {
	const string task = "B";
	const string folder = "gcj/2015/1B";
	const int attempt = -1;
	const bool dbg = false;


	if (dbg) {
		freopen("inp.txt", "r", stdin);
	}
	else {
		stringstream ss;
		if (attempt < 0)
			ss << folder << '/' << task << "-large";
		else
			ss << folder << '/' << task << "-small-attempt" << attempt;
		freopen((ss.str() + ".in").c_str(), "r", stdin);
		freopen((ss.str() + ".out").c_str(), "w", stdout);
	}


	static char tt[128];
	gets(tt);
	int t;
	sscanf(tt, "%d", &t);
	FOR(i, t) {
		printf("Case #%d: ", i + 1);
		Go(i);
		printf("\n");
	}
	return 0;
}