#include <bits/stdc++.h>
#define ALL(x) x.begin(), x.end()
#define SIZE(x) (int)(x.size())
#define FOR(i, s, e) for (int i = int(s); i < int(e); ++i)
#define FORIT(i, c) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
const int MOD = 1000000007;
const int INF = 0x3F3F3F3F;
const int MAX = 1010;

int n, T;
char str_template[] = "Case #%d: %d";
char str_answer[sizeof(str_template)];
int m[MAX];

int main() {
	freopen("output.txt", "w", stdout);
	int t;
	int n;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int ans1 = 0, ans2 = 0, max_diff = 0;
		scanf("%d", &n);
		for (int j = 0; j < n; j++)
			scanf("%d", m + j);
		for (int j = 1; j < n; j++) {
			if (m[j] < m[j - 1]) {
				ans1 += (m[j - 1] - m[j]);
				max_diff = max(max_diff, (m[j - 1] - m[j]));
			}
		}
		for (int j = 0; j < n - 1; j++) {
			if (m[j] > max_diff)
				ans2 += max_diff;
			else
				ans2 += m[j];
		}
		printf("Case #%d: %d %d\n", i, ans1, ans2);
	}
	return 0;
}
