#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

#define NN 1010

int t, N;
int m[NN];

int main() {
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &m[i]);
		}
		int sum1 = 0;
		int mx = 0;
		for (int i = 1; i < N; ++i) {
			int delta = m[i-1] - m[i];
			if (delta > 0) sum1 += delta;
			if (mx < delta) mx = delta;
		}
		int sum2 = 0;
		for (int i = 1; i < N; ++i) {
			if (m[i-1] < mx) sum2 += m[i-1];
			else sum2 += mx;
		}
		printf("Case #%d: %d %d\n", ti+1, sum1, sum2);
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
