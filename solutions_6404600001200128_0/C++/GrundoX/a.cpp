#include <bits/stdc++.h>
using namespace std;

int z, n, a[1005];

int main(){
	scanf("%d", &z);
	for(int x = 1; x <= z; x++){
		printf("Case #%d: ", x);
		scanf("%d", &n);
		int ans1 = 0, ans2 = 0, diff = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &a[i]);
			if(i > 0){
			   	ans1 += max(0, a[i-1]-a[i]);
				diff = max(diff, a[i-1]-a[i]);
			}
		}
		for(int i = 0; i < n-1; i++) ans2 += min(diff, a[i]);
		printf("%d %d\n", ans1, ans2);
	}
	return 0;
}
