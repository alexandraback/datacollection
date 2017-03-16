#define _CRT_SECURE_NO_DEPRICATE
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <bitset>
#include <string>
#include <queue>
#include <stack>
#include <deque>
#include <list>

#define FOR(i, p, n) for(int i = p; i < n; ++i)
#define FORD(i, p, n) for(int i = p; i >= n; --i)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define PII pair<int, int>
#define RE scanf
#define WR printf

using namespace std;

int arr[26];
int c;

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int t, n;
	cin >> t;
	FOR(p, 0, t) {
		RE("%d", &n);
		c = 0;
		FOR(i, 0, n) {
			RE("%d", &arr[i]);
			c += arr[i];
		}
		WR("Case #%d: ", p + 1);
		while (1) {
			int m1 = 0, m2 = 0;
			if (!c) break;
			else if (c == 3) {
				FOR(i, 0, n) if (arr[i] > arr[m1]) m1 = i;
				--arr[m1];
				WR("%c ", 'A' + m1);
				--c;
			}
			else {
				FOR(i, 0, n) if (arr[i] > arr[m1]) m1 = i;
				--arr[m1];
				FOR(i, 0, n) if (arr[i] > arr[m2]) m2 = i;
				--arr[m2];
				WR("%c%c ", 'A' + m1, 'A' + m2);
				c -= 2;
			}
		}
		WR("\n");
	}
	cin >> t;

	return 0;
}