#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cstring>
#include <queue>
using namespace std;

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
typedef long long ll;

#define BB 1010

int t, B;
ll N;
int M[BB];

ll calc(ll tm) {
	ll count = 0;
	for (int i = 0; i < B; ++i) {
		count += tm / M[i] + 1;
	}
	//fprintf(stderr, "out calc(%lld) -> %lld\n", tm, count);
	return count;
}

int main() {
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%d%lld", &B, &N);
		ll mx = 0;
		for (int i = 0; i < B; ++i) {
			scanf("%d", &M[i]);
			if (mx < M[i]) mx = M[i];
		}
		//fprintf(stderr, "ti=%d, mx=%lld\n", ti+1, mx);
		ll left = -1;
		ll right = N * ll(mx);
		while (left+1 != right) {
			ll mid = (left + right)/2;
			//fprintf(stderr, "left=%lld, right=%lld, mid=%lld, calc=%lld\n", left, right, mid, calc(mid));
			if (calc(mid) >= N) {
				right = mid;
			} else {
				left = mid;
			}
		}
		priority_queue<int> freeQ;
		ll count = 0;
		for (int i = 0; i < B; ++i) {
			count += right / M[i];
			if (right % M[i] == 0) freeQ.push(-i);
			else ++count;
		}
		//fprintf(stderr, "count=%lld, Q.size=%zu\n", count, freeQ.size());
		int cur = 0;
		while (count != N) {
			cur = -freeQ.top();
			freeQ.pop();
			++count;
			//fprintf(stderr, "count=%lld, N=%lld, cur=%d, freeQ.size()=%zu\n", count, N, cur, freeQ.size());
		}
		//fprintf(stderr, "Case #%d: %d\n", ti+1, cur+1);
		printf("Case #%d: %d\n", ti+1, cur+1);
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
