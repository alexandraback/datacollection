#include <bits/stdc++.h>
using namespace std;
int nTest;
int n, a[1111];
long long k;
long long min_time[1111];
long long already(long long tg){
	long long sum = 0;
	for (int i = 1; i <= n; i++){
		sum += tg / a[i] + 1;
	}
	return sum;
}
int main(){
	freopen("B.inp", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &nTest);
	for (int test = 1; test <= nTest; test++){
		scanf("%d %lld", &n, &k);
		for (int i = 1; i <= n; i++){
			scanf("%d", a + i);
		}


		long long L = 0;
		long long R = 1000000000000000000LL;
		long long res = 0;
		while (L <= R){
			long long M = (L + R) / 2;
			if (already(M) >= k) {
				res = M;
				R = M - 1;
			} else L = M + 1;
		}
		long long sum = 0;
		long long cnt = 0;
		for (int i = 1; i <= n; i++){
			if (res % a[i] == 0) {
				sum += res / a[i];
				cnt ++;
			} else sum += res / a[i] + 1;
		}
		
		k -= sum;
		for (int i = 1; i <= n; i++){
			if (res % a[i] == 0) k--;
			if (k == 0) {
				printf("Case #%d: %d\n", test, i);		
				break;
			}
		}

	}
	return 0;
}