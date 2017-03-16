#define _HAS_CPP0X 0
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


void Go() {
	int R, C, N;
	cin >> R >> C >> N;
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
	cout << res;
}

int main() {
	const string task = "B";
	const string folder = "gcj/2015/1B";
	const int attempt = 0;
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
		Go();
		printf("\n");
	}
	return 0;
}