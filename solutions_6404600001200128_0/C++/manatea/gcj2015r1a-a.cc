#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>
#include <climits>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef map<int, int> mii;

int T;
int N;
const int MAX_N = 1000;
int m[MAX_N];

void solve()
{
	int res1 = 0;
	for (int i = 0; i < N-1; ++i) {
		if (m[i] > m[i+1]) {
			res1 += m[i] - m[i+1];
		}
	}

	int rate = 0;
	for (int i = 0; i < N-1; ++i) {
		if (m[i] > m[i+1]) {
			rate = max(rate, m[i] - m[i+1]);
		}
	}
		// if (rate % 10 != 0) {
		// 	rate = (rate / 10 + 1) * 10;
		// }

	int res2 = 0;
	for (int i = 0; i < N-1; ++i) {
		res2 += min(rate, m[i]);
	}

	cout << res1 << " " << res2;
}

int main()
{
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &m[i]);
		}
		printf("Case #%d: ", t);
		solve();
		printf("\n");
	}
	return 0;
}
