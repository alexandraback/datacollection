#include <bits/stdc++.h>

using namespace std;

const int B = 1000 + 10;

long long m[B];

long long C(long long mid, int b) {
	long long sum = 0;
	for(int i = 0; i < b; i++) {
		sum += (mid-1LL)/m[i]+1LL;
	}
	return sum;
}

int main() {
	int t;
	scanf("%d", &t);
	for(int kase = 1; kase <= t; kase++) {
		int b, n;
		scanf("%d%d", &b, &n);
		for(int i = 0; i < b; i++)	scanf("%lld", m+i);

		long long lb = 0, ub = n*100010LL;
		while(ub-lb > 1) {
			long long mid = (ub+lb)/2;
			if(C(mid, b) >= n)	ub = mid;
			else	lb = mid;
		}
		long long x = n - C(ub-1, b);
		int ans = 0;
		for(int i = 0; i < b && x; i++) {
			if((ub-1)%m[i]==0)	x--;
			if(!x)	ans = i+1;
		}
		printf("Case #%d: %d\n", kase, ans);
	}

	return 0;
}
