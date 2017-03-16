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
int t,n,pos;
LL a[1050];
LL judge(LL ti){
	LL ans = 0;
	for (int i = 1; i <= n; i++){
		ans += 1+ti/a[i];
	}
	return ans;
}
int main(){
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int t; scanf("%d", &t);
	int kase = 0;
	while (t--){
		scanf("%d %d", &n, &pos);
		for (int i = 1; i <= n; i++){
			scanf("%lld", &a[i]);
		}
		LL l = 0, r = 1e16;
		while (l != r){
			LL mid = (l + r) >> 1;
			if (judge(mid) >=pos)r = mid;
			else l = mid+1;
		}
		int ans = -1;
		LL st[1050]; int tops = 0;
		for (int i = 1; i <= n; i++)
		if((r)%a[i]==0){
			st[tops++] = i;
		}
		LL now = judge(r);
		ans = st[pos - (now - tops)-1];
		printf("Case #%d: %d\n", ++kase, ans);
	}
	return 0;
}