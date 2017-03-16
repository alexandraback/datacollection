#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

typedef long long LL;

const int maxn = 2333;

int a[maxn];

int main(){
	int T;
	scanf("%d", &T);
	for (int TI = 1; TI <= T; ++TI){
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		printf("Case #%d: ", TI);
		int ans = 0;
		a[0] = 0;
		for (int i = 1; i <= n; ++i)
			ans += max(a[i - 1] - a[i], 0);
		printf("%d ", ans);
		int rate = 0;
		for (int i = 1; i <= n; ++i)
			rate = max(rate, (a[i - 1] - a[i]));
		ans = 0;
		for (int i = 1; i < n; ++i)
			ans += min(a[i], rate);
		printf("%d\n", ans);
	}
	return 0;
}
