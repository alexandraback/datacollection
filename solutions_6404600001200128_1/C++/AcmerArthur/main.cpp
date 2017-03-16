#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include<string>
using namespace std;
#define LL long long
#define mods 100007
int n;
int a[1005];
int main(){
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int t; scanf("%d", &t);
	int kase = 0;
	while (t--){
		scanf("%d", &n);
		int maxs = 0;
		for (int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			if (i)maxs = max(maxs, a[i - 1] - a[i]);
		}
		int ans1 = 0, ans2 = 0;
		for (int i = 0; i <n-1; i++){
			if(a[i]>a[i+1])ans1 += a[i] - a[i + 1];
			ans2 += min(a[i], maxs);
		}
		printf("Case #%d: %d %d\n", ++kase, ans1, ans2);
	}
	return 0;
}