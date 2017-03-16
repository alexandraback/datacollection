#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<ctime>
#include<algorithm>
#include<iomanip>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<cassert>
#include<bitset>

using namespace std;

const int B = 1e3 + 10, lim = 1e5 + 10;

int b, n;
int m[B];

bool check(long long mid) {
	long long now = 0;
	for (int i = 0; i < b; i++) {
		now += mid / m[i] + 1;
	}
	return now >= n;
}

int main() {
	freopen("b.out", "w", stdout);
	int TT;
	scanf("%d", &TT);
	for (int s = 1; s <= TT; s++) {
		scanf("%d%d", &b, &n);
		int Min = lim;
		for (int i = 0; i < b; i++) {
			scanf("%d", &m[i]);
			Min = min(Min, m[i]);
		}
		long long l = 0, r = (long long) n * Min;
		while (l < r) {
			long long mid = (l + r) >> 1;
			if (check(mid)) r = mid; else l = mid + 1;
		}
		int ans = -1;
		long long sum = 0;
		for (int i = 0; i < b; i++) {
			sum += l / m[i];
			if(l % m[i]) ++sum;
		}
		for (int i = 0; i < b; i++) if (l % m[i] == 0) {
			sum++;
			if (sum >= n) {
				ans = i;
				break;
			}
		}
		printf("Case #%d: %d\n", s, ans + 1);
	}
	return 0;
}

