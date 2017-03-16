#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;

const int lim = 1e3 + 10;

int a[lim];

int main() {
	freopen("a.out", "w", stdout);
	int TT;
	scanf("%d", &TT);
	for (int s = 1; s <= TT; s++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) scanf("%d", &a[i]);
		int ans1 = 0;
		for (int i = 1; i < n; i++) if (a[i] < a[i - 1]) ans1 += a[i - 1] - a[i];
		int ans2 = 0, Max = 0;
		for (int i = 1; i < n; i++) Max = max(Max, a[i - 1] - a[i]);
		for (int i = 0; i < n - 1; i++) {
			if (a[i] >= Max) {
				ans2 += Max;
			}
			else {
				ans2 += a[i];
			}
		}
		printf("Case #%d: %d %d\n", s, ans1, ans2);
	}
	return 0;
}

