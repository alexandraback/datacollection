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

typedef long long lint;

const int MAXN = 1000;
const lint INF = 1000000000000000;

lint N, M[MAXN];
int B;

lint get_sum(lint X) {
	lint sum = 0;
	for (int i = 0; i < B; ++i)
		sum += X / M[i] + (X % M[i] != 0);
	return sum;
}

void solve(int tc) {
	cin >> B >> N;
	for (int i = 0; i < B; ++i)
		cin >> M[i];
	lint lo = 1, hi = INF;
	while (hi - lo > 1) {
		lint mid = (lo + hi) / 2;
		if (get_sum(mid) >= N)
			hi = mid;
		else
			lo = mid;
	}
	lint minute = hi;
	if (get_sum(lo) >= N)
		minute = lo;
	--minute;
	lint dif = N - get_sum(minute);
	int ans = -1, cnt = 0;
	for (int i = 0; i < B; ++i)
		if (minute % M[i] == 0) {
			++cnt;
			if (cnt == dif) {
				ans = i + 1;
				break;
			}
		}
	cout << "Case #" << tc << ": " << ans << '\n';
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

