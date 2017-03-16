#include <bits/stdc++.h>

using namespace std;

#define MAXT 100010000000000LL

long long n, b;
vector<long long> v;

long long check(long long x) {
	long long ret = 0;
	for(int i = 0; i<b; i++) {
		
		ret += x/v[i];
	}
	return ret+b;
}

long long bs() {
	long long ret;
	long long beg = 0, end = MAXT;
	while(end >= beg) {
		long long mid = (beg+end)/2;
		
		if(check(mid) >= n) {
			ret = mid;
			end = mid-1;
		}
		else {
			beg = mid+1;
		}
	}
	return ret;
}

int main() {
	freopen("inputBlarge.txt", "r", stdin);
	freopen("outputBlarge.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int test = 1; test<=t; test++) {
		v.clear();
		vector<int> possible;
		possible.clear();
		scanf("%lld %lld", &b, &n);
		for(int i = 0; i<b; i++) {
			long long x;
			scanf("%lld", &x);
			v.push_back(x);
		}
		long long r = bs();
		//printf("%lld\n", r);
		printf("Case #%d: ", test);
		for(int i = 0; i<b; i++) {
			if(r%v[i] == 0) {
				possible.push_back(i+1);
			}
		}
		long long aux = check(r)-n;
		//if(aux<0) printf("%d\n", possible.size()-1-aux);
		printf("%d\n", possible[possible.size()-1-aux]);
	}
	return 0;
}
