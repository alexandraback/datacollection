// Problem A. Mushroom Monster
#include <cstdio>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	scanf("%d\n", &T);
	for (int ti = 1; ti <= T; ti++) {
		static int a[1024];
		int n, ans1 = 0, ans2 = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);

		int r = 0;
		for (int i = 1; i < n; i++)
			if (a[i - 1] > a[i]) {
				int d = a[i - 1] - a[i];
				ans1 += d;
				if (d > r) r = d;
			}
		for (int i = 0; i < n - 1; i++)
			ans2 += (a[i] > r) ? r : a[i];

		printf("Case #%d: %d %d\n", ti, ans1, ans2);
	}
	return 0;
}
