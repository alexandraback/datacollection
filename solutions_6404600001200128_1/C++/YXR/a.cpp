#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int a[2000];
int main(){
	freopen("a.in","r",stdin);
	freopen("ans.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++){
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++){
			scanf("%d", &a[i]);
		}
		int ans1 = 0;
		int ans2 = 0;
		int rate = 0;
		for (int i = 2; i <= n; i++){
			if (a[i] <= a[i - 1]){
				ans1 += a[i - 1] - a[i];
				rate = max(rate, (a[i-1]-a[i]));
			}
		}
		printf("Case #%d: ", t);
		int cur = a[1];
		for (int i = 2; i <= n; i++){
			ans2 += min(rate, cur);
			cur = a[i];
		}
		printf("%d %d\n",ans1, ans2);
	}
	return 0;
}
