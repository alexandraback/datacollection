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

const int maxn = 233333;

int a[maxn];

int main(){
	int T;
	scanf("%d", &T);
	for (int TI = 1; TI <= T; ++TI){
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; ++i)
			scanf("%d", &a[i]);
		long long L = 0LL, R = (LL)1e15;
		while (L <= R){
			long long mid = (L + R) >> 1;
			long long sum = 0LL;
			for (int i = 1; i <= n; ++i)
				sum += mid / (LL)(a[i]) + 1LL;
			if (sum >= (LL)(m)) R = mid - 1;
			else L = mid + 1;
		}
		long long tot = 0LL;
		for (int i = 1; i <= n; ++i)
			tot += R / (LL)(a[i]) + 1LL;
		int ans;
		for (int i = 1; i <= n; ++i)
			if (L % (LL)(a[i]) == 0LL){
				++tot;
				if (tot == (LL)(m)){
					ans = i;
					break;
				}
			}
		printf("Case #%d: %d\n", TI, ans);
	}
	return 0;
}
