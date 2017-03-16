#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);
const int MAXN = 3200;
int n;
int x[MAXN], y[MAXN];
double a[MAXN * 2];

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d%d", &x[i], &y[i]);
}

int solve(int k)
{
	int m = 0;
	for (int i = 0; i < n; ++i) {
		if (i != k) a[m++] = atan2(x[i] - x[k], y[i] - y[k]);
	}
	sort(a, a + m);
	int ans = n - 1;
	for (int i = 0; i < m; ++i) a[i + m] = a[i] + 2 * pi;
	for (int i = 0; i < m; ++i) {
		int j = upper_bound(a + i, a + i + m, a[i]) - a;
		int k = lower_bound(a + i, a + i + m, a[i] + pi) - a;
		ans = min(ans, k - j);
	}
	for (int i = 0; i < m * 2; ++i) a[i] = -a[i];
	reverse(a, a + m * 2);
	for (int i = 0; i < m; ++i) {
		int j = upper_bound(a + i, a + i + m, a[i]) - a;
		int k = lower_bound(a + i, a + i + m, a[i] + pi) - a;
		ans = min(ans, k - j);
	}
	return ans;
}

int main()
{
	int dat;
	scanf("%d", &dat);
	for (int cas = 1; cas <= dat; ++cas) {
		init();
		printf("Case #%d:\n", cas);
		for (int i = 0; i < n; ++i) printf("%d\n", solve(i));
	}
}
