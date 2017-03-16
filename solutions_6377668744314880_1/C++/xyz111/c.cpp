#include <cstdio>
#include <algorithm>
using namespace std;

int T, n, x[3100], y[3100], tx[3100];

long long xj(int a, int b) {
	return 1LL * x[a] * y[b] - 1LL * y[a] * x[b];
}

bool cmp(int a, int b) {
	int x1, y1, x2, y2;
	if (y[a] < 0) x1 = -x[a], y1 = -y[a];
	else x1 = x[a], y1 = y[a];
	if (y[a] == 0) x1 = abs(x1);
	if (y[b] < 0) x2 = -x[b], y2 = -y[b];
	else x2 = x[b], y2 = y[b];
	if (y[b] == 0) x2 = abs(x2);
	return 1LL * x1 * y2 - 1LL * x2 * y1 > 0;
}

int solve(int k) {
	int len = 0;
	for (int i = 1; i <= n - 1; i++) {
		for (len++; len == k; len++);
		tx[i] = len;
	}
	sort(tx + 1, tx + n, cmp);
	int tmp = 0;
	int ans = 1000000000, h;
	for (int i = 1; i <= n; i++)
		if (y[i] < 0) tmp++;

	ans = min(ans, tmp);
	for (int i = 1; i <= n; i++)
		if (y[i] == 0 && x[i] > 0)
			tmp++;
	for (int q = 1; q < n; q = h) if (y[tx[q]] != 0) {
		for (h = q; h < n && xj(tx[q], tx[h]) == 0; h++);

		for (int i = q; i < h; i++) {
			if (y[tx[i]] < 0) tmp--;
		}
		ans = min(ans, tmp);
		for (int i = q; i < h; i++) {
			if (y[tx[i]] > 0) tmp++;
		}
	}else h = q + 1;

	for (int i = 1; i <= n; i++)
		x[i] = - x[i], y[i] = - y[i];
	sort(tx + 1, tx + n, cmp);
	tmp = 0;
	for (int i = 1; i <= n; i++)
		if (y[i] < 0) tmp++;

	ans = min(ans, tmp);
	for (int i = 1; i <= n; i++)
		if (y[i] == 0 && x[i] > 0)
			tmp++;
	for (int q = 1; q < n; q = h) if (y[tx[q]] != 0) {
		for (h = q; h < n && xj(tx[q], tx[h]) == 0; h++);
		for (int i = q; i < h; i++) {
			if (y[tx[i]] < 0) tmp--;
		}
		ans = min(ans, tmp);
		for (int i = q; i < h; i++) {
			if (y[tx[i]] > 0) tmp++;
		}
	}else h = q + 1;
	return ans;
}

int main() {
	scanf("%d", &T);
	for (int xx = 1; xx <= T; xx++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d%d", &x[i], &y[i]);
		printf("Case #%d:\n", xx);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++)
				if (i != j) x[j] -= x[i], y[j] -= y[i];
			x[i] = y[i] = 0;
			printf("%d\n", solve(i));
		}
	}
}
