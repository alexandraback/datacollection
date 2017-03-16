#pragma comment(linker, "/STACK:500000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <assert.h>
#include <bitset>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <math.h>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <time.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

#define y0 y0ChloeGraceMoretz
#define y1 y1ChloeGraceMoretz
#define ll long long
int nextInt() { int n; scanf("%d", &n); return n; }
ll nextLong() { ll n; scanf("%lld", &n); return n; }
const double PI = acos(-1.0);
const double EPS = 1e-9;
const int INF = (int)1e9;
const int MOD = (int)1e9 + 7;

int cnt[26];

int main() {
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("out.txt", "wt", stdout);
	int t;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; ++tt) {
		int n;
		scanf("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &cnt[i]);
			sum += cnt[i];
		}
		printf("Case #%d:", tt);
		vector<string> ans;
		while (sum > 0) {
			int x = 0;
			for (int i = 1; i < n; ++i) {
				if (cnt[i] > cnt[x]) {
					x = i;
				}
			}
			--cnt[x];
			--sum;
			int y = -1;
			for (int i = 0; i < n; ++i) {
				if (cnt[i] * 2 > sum) {
					y = i;
				}
			}
			string tmp = "";
			tmp += (char) ('A' + x);
			if (y != -1) {
				tmp += (char) ('A' + y);
				--cnt[y];
				--sum;
			}
			ans.push_back(tmp);
		}
		for (int i = 0; i < ans.size(); ++i) {
			printf(" %s", ans[i].c_str());
		}
		printf("\n");
	}
	return 0;
}