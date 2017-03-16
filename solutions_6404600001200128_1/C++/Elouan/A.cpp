#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int MAXN = 1000;

int N, M[MAXN];

void solve(int tc) {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> M[i];
	int ans0 = 0;
	for (int i = 0; i < N - 1; ++i)
		ans0 += max(0, M[i] - M[i + 1]);
	int ans1 = 0;
	int mag = -1;
	for (int i = 0; i < N - 1; ++i)
		mag = max(mag, max(0, M[i] - M[i + 1]));
	for (int i = 0; i < N - 1; ++i)
		ans1 += min(M[i], mag);
	cout << "Case #" << tc << ": " << ans0 << ' ' << ans1 << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	#ifdef ACMTUYO
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
		clock_t start = clock();
	#endif
	
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; ++tc)
		solve(tc);
	
	#ifdef ACMTUYO
		fprintf(stderr, "\ntime=%.3lfsec\n", 1. * (clock() - start) / CLOCKS_PER_SEC);
	#endif
	return 0;
}

