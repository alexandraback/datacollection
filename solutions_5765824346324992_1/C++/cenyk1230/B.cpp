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

int b, n;
int a[1010];

long long getNum(long long x) {
	long long num = 0;
	for (int i = 1; i <= b; ++i)
		num += (x / a[i]) + 1;
	return num;
}

void work() {
	scanf("%d%d", &b, &n);
	for (int i = 1; i <= b; ++i)
		scanf("%d", &a[i]);
	long long l = -1, r = 100000000000001ll, mid;
	while (l + 1 < r) {
		mid = (l + r) >> 1;
		if (getNum(mid) >= n)
			r = mid;
		else
			l = mid;
	}
	int lastNum = 0;
	if (r > 0)
		lastNum = getNum(r - 1);
	n -= lastNum;
	for (int i = 1; i <= b; ++i) {
		if (r % a[i] == 0) {
			if (--n == 0) {
				printf("%d\n", i);
				return;
			}
		}
	}
}

int main() {
	#ifdef LOCAL_JUDGE
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	#endif // LOCAL_JUDGE

	int T = 1;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		printf("Case #%d: ", i);
		work();
	}
 	
	return 0;
}
