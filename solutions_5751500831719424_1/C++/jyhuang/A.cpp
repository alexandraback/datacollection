#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	int T;
	static char s[128][128], t[128];

	scanf("%d", &T);
	for (int ti = 1; ti <= T; ti++) {
		int n;
		scanf("%d", &n);
		vector<string> a;
		for (int i = 0; i < n; i++) {
			scanf("%s", s[i]);
			t[0] = s[i][0];
			int k = 1;
			for (int j = 1; s[i][j]; j++)
				if (s[i][j] != s[i][j - 1]) t[k++] = s[i][j];
			t[k] = 0;
			a.push_back(t);
		}

		int ans = 0;
		for (int i = 1; i < a.size(); i++)
			if (a[i] != a[0]) {
				ans = -1;
				break;
			}

		if (ans < 0) {
			printf("Case #%d: Fegla Won\n", ti);
		} else {
			int len = a[0].size();
			vector<vector<int> > c(n, vector<int>(len));
			for (int i = 0; i < n; i++) {
				int m = 0;
				for (int j = 0, k = 0; s[i][j]; j++) {
					if (j > 0 && s[i][j] != s[i][j - 1]) k++;
					c[i][k]++;
					if (c[i][k] > m) m = c[i][k];
				}
			}

			for (int j = 0; j < len; j++) {
				int k = 0;
				for (int i = 0; i < n; i++)
					if (c[i][j] > k) k = c[i][j];
				int best = 1000000000;
				for ( ; k >= 0; k--) {
					int x = 0;
					for (int i = 0; i < n; i++)
						x += abs(c[i][j] - k);
					if (x < best) best = x;
				}
				ans += best;
			}
			printf("Case #%d: %d\n", ti, ans);
		}
	}

	return 0;
}
