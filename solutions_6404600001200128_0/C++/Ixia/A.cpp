#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;
typedef long long ll;
int mm[1010];
int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int _;
	scanf("%d", &_);
	for(int cs = 1; cs <= _; ++cs) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; ++i) {
			scanf("%d", &mm[i]);
		}

		int sta = mm[0];
		//method 1.
		int ans1 = 0;
		for(int i = 1; i < n; ++i) {
			if(mm[i] < sta) {
				ans1 += sta - mm[i];
				sta = mm[i];
			}
			else {
				sta = mm[i];
			}
		}
		//method 2.
		int ans2 = 0, r = 0;
		for(int i = 1; i < n; ++i) {
			r = max(r, mm[i - 1] - mm[i]);
		}
		for(int i = 0; i < n - 1; ++i) {
			ans2 += min(mm[i], r);
		}

		printf("Case #%d: %d %d\n", cs, ans1, ans2);
	}
	return 0;
}