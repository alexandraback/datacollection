#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>

using namespace std;

int a[10000];

int main() {
	int cases;
	scanf("%d", &cases);
	for (int o = 0; o < cases; ++o) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
		}
		int ans1 = 0, ans2 = 0, rate = 0;
		for (int i = 1; i < n; ++i) {
			ans1 += max(0, a[i - 1] - a[i]);
			rate = max(rate, a[i - 1] - a[i]);
		}
		for (int i = 1; i < n; ++i) {
			ans2 += min(a[i - 1], rate);
		}
		printf("Case #%d: %d %d\n", o + 1, ans1, ans2);
	}
	return 0;
}