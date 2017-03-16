#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define sz size()
typedef long long ll;
typedef vector<int> vi;
const int oo = (int)1e9;

const int MAXN = 1010;
int t, n, m[MAXN];

int main() {
	scanf("%d", &t);
	int xx = 1;
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &m[i]);
		int ans1, ans2, mini;

		ans1 = mini = ans2 = 0;
		for (int i = 0; i + 1 < n; i++) {
			if (m[i + 1] < m[i]) ans1 += m[i] - m[i + 1];
			mini = min(mini, m[i + 1] - m[i]);
		}
		mini = -mini;
		for (int i = 0; i + 1 < n; i++) {
			ans2 += min(m[i], mini);
		}
		printf("Case #%d: %d %d\n", xx++, ans1, ans2);
	}
	return 0;
}
