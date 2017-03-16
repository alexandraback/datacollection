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
int a[1010];

void work() {
	scanf("%d", &n);
	int ans1 = 0, maxRate = 0, ans2 = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		if (i > 1 && a[i] < a[i - 1]) {
			ans1 += a[i - 1] - a[i];
			maxRate = max(maxRate, a[i - 1] - a[i]);
		}
	}
	for (int i = 1; i < n; ++i) {
		ans2 += min(a[i], maxRate);
	}
	printf("%d %d\n", ans1, ans2);
}


int main() {
	#ifdef LOCAL_JUDGE
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	#endif // LOCAL_JUDGE

	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		work();
	}
 	
	return 0;
}
