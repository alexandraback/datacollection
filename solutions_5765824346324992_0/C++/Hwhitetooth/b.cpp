/*
 * Problem : 
 * Author : Hwhitetooth
 * Date : 
 * Result :
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

const int N = 1000 + 10;

int a[N];
int n, m;
LL t;
int testCases;

LL check(LL t) {
	LL cnt = 0;
	for (int i = 0; i < n; ++i) {
		cnt += (t + a[i] - 1) / a[i];
		if (cnt >= m) {
			return cnt;
		}
	}
	return cnt;
}

int main() {
	scanf("%d", &testCases);
	for (int _ = 1; _ <= testCases; ++_) {
		scanf("%d%d", &n, &m);
		t = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			t = max(t, 1LL * a[i]);
		}
		t *= 1LL * m;
		LL l = 0, r = t, mid, ret;
		while (l <= r) {
			mid = (l + r) / 2;
			if (check(mid) < m) {
				ret = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		LL cnt = check(ret);
		for (int i = 0; i < n; ++i) {
			if (ret % a[i] == 0) {
				++cnt;
			}
			if (cnt == m) {
				printf("Case #%d: %d\n", _, i + 1);
				break;
			}
		}
	}
	return 0;
}