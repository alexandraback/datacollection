#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

int n; 
int a[1005];

int main() {
	int T, cases = 0;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) 
			scanf("%d", &a[i]);
		int ans1 = 0;
		int tmp = 0;
		for (int i = 1; i < n; ++i) {
			ans1 += max(a[i - 1] - a[i], 0);
			tmp = max(tmp, a[i - 1] - a[i]);
		}
		int ans2 = 0;
		for (int i = 1; i < n; ++i) {
			ans2 += min(a[i - 1], tmp);
		}
		printf("Case #%d: ", ++cases);
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
