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
		int B, N;
		scanf("%d %d", &B ,&N);
		long long max = 0;
		for (int i = 1; i <= B; i++){
			scanf("%d", &a[i]);
			if (a[i] > max) max = a[i];
		}
		long long l = 0;
		long long r = max * N;
		do{
			long long cc = 0;
			long long ww = 0;
			long long mid = (l + r) / 2;
			for (int i = 1; i <= B; i++){
				cc += mid / a[i];
				if (mid % a[i] == 0) ww++; 
				else cc++;
			}
			if (cc + ww >= N){
				r = mid;
			}else {
				l = mid + 1;
			}
		}while (l < r);
		//cout << l << endl;
		long long cc = 0;
		long long ww = 0;
		long long mid = (l + r) / 2;
		for (int i = 1; i <= B; i++){
			cc += mid / a[i];
			if (mid % a[i] == 0) ww++; 
			else cc++;
		}
		N = N - cc;
		int ans;
		for (int i = 1; i <= B; i++){
			if (mid % a[i] == 0){
				N--;
				if (N == 0){
					ans = i;
					break;
				}
			}
		}
		printf("Case #%d: ", t);
		printf("%d\n", ans);
	}
	return 0;
}
