#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2000;
int T, n, ma, a[N], ans1, ans2;
int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (int Ti = 1; Ti <= T; ++Ti){
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
		ma = ans1 = ans2 = 0;
		for (int i = 1; i < n; ++i)
			if (a[i] > a[i + 1]) ans1 += a[i] - a[i + 1], ma = max(ma, a[i] - a[i + 1]);
		for (int i = 1; i < n; ++i){
			if (a[i] < ma) ans2 += a[i];
			else ans2 += ma;
		}
		printf("Case #%d: %d %d\n", Ti, ans1, ans2);
	}
	return 0;
}
