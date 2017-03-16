#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

#define NN 3030
typedef long long ll;

int t, N;
ll X[NN], Y[NN];

int main() {
	scanf("%d", &t);
	for (int ti = 0; ti < t; ++ti) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%lld%lld", &X[i], &Y[i]);
		}
		fprintf(stderr, "#%d: %d\n", ti+1, N);
		printf("Case #%d:\n", ti+1);
		if (N < 4) {
			for (int i = 0; i < N; ++i) {
				printf("0\n");
			}
			continue;
		}
		for (int i = 0; i < N; ++i) {
			int mn = N-1;
			for (int j = 0; j < N; ++j) {
				if (j == i) continue;
				ll dy1 = Y[j]-Y[i];
				ll dx1 = X[j]-X[i];
				int pos = 0;
				int neg = 0;
				for (int k = 0; k < N; ++k) {
					ll dy2 = Y[k]-Y[i];
					ll dx2 = X[k]-X[i];
					ll prod = dx1*dy2 - dx2*dy1;
					if (prod > 0) ++pos;
					if (prod < 0) ++neg;
				}
				if (mn > pos) mn = pos;
				if (mn > neg) mn = neg;
				//fprintf(stderr, "i=%d, j=%d, pos=%d, neg=%d, mn=%d\n", i, j, pos, neg, mn);
			}
			printf("%d\n", mn);
		}
	}
	return 0;
}

/* vim: set ts=4 sw=4 noet: */
