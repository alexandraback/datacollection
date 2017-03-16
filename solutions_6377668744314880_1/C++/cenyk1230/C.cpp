#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long LL;
typedef pair<int, int> PII;

void readInt(int &x) {
	x = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + c - '0';
}

void readSignedInt(int &x) {
	x = 0;
	bool minus = false;
	char c = getchar();
	for (; c != '-' && (c < '0' || c > '9'); c = getchar());
	if (c == '-')
		minus = true, c = getchar();
	for (; c >= '0' && c <= '9'; c = getchar())
		x = (x << 3) + (x << 1) + c - '0';
	if (minus)
		x = -x;
}

int n;
int x[3010], y[3010];

inline LL cross(int i, int j, int k) {
	LL x1 = x[j] - x[i], x2 = x[k] - x[i];
	LL y1 = y[j] - y[i], y2 = y[k] - y[i];
	return x1 * y2 - x2 * y1;
}

void work() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d %d", &x[i], &y[i]);
	if (n == 1) {
		printf("%d\n", 0);
		return;
	}
	for (int i = 1; i <= n; ++i) {
		int cur = n;
		for (int j = 1; j <= n; ++j) {
			if (j == i)
				continue;
			int s1 = 0, s2 = 0;
			for (int k = 1; k <= n; ++k) {
				if (cross(i, j, k) < 0)
					++s1;
				if (cross(i, j, k) > 0)
					++s2;
				if (min(s1, s2) >= cur)
					break;
			}
			cur = min(cur, min(s1, s2));
		}
		printf("%d\n", cur);
	}
}

int main() {
	#ifdef LOCAL_JUDGE
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	#endif // LOCAL_JUDGE

	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		cerr << i << endl;
		printf("Case #%d:\n", i);
		work();
	}
 	
	return 0;
}
