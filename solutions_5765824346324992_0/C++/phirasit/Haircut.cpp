#include <stdio.h>
#include <iostream>

#define N 1010

using namespace std;

long long arr[N];

int main() {
	
	freopen("Bsmall.in", "r", stdin);
	freopen("Bsmall.out", "w", stdout);
	
	int t;
	cin >> t;
	for(int C = 1;C <= t;C++) {
		int b;
		long long n;
		cin >> b;
		cin >> n;
		long long mn;
		for(int i = 1;i <= b;i++) {
			cin >> arr[i];
			if(i == 1 || arr[i] < mn) {
				mn = arr[i];
			}
		}
		long long A = 0ll, B = mn * n;
		while(A < B) {
			long long mid = (A + B) / 2ll; 
			long long cnt = 0ll;
			for(int i = 1;i <= b;i++) {
				cnt += mid / arr[i] + 1ll;
			}
			if(cnt >= n) {
				B = mid;
			}else {
				A = mid + 1ll;
			}
		}
		long long ans = A, cnt = n;
		if(ans > 0ll) {
			for(int i = 1;i <= b;i++) {
				cnt -= (ans - 1) / arr[i] + 1ll;
			}
		}
		printf("Case #%d: ", C);
		for(int i = 1;i <= b;i++) {
			cnt -= (ans % arr[i] == 0ll);
			if(cnt == 0ll) {
				printf("%d\n", i);
				break;
			}
		}
	}
	return 0;
}
