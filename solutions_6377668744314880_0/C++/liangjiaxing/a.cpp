#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <queue>
using namespace std;

const double eps = 1e-8, PI = atan2(0, -1);

int x[4000], y[4000];


bool check(double x, double y) {
	if (y <= x) {
		y += 2 * PI;
	}
	return y - x >= PI;
}

int main() {
	// your code goes here
	int T;
	freopen("a.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	for (int re = 1; re <= T; re++) {
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d%d", x + i, y + i);
		}
		
		printf("Case #%d:\n", re);
		
		for (int i = 0; i < N; i++) {
			int ans = N;
			vector<double> a;
			if (N > 1) {
				for (int j = 0; j < N; j++) {
					if (i == j) continue;
					a.push_back(atan2(x[j]-x[i], y[j]-y[i]));
				}
				sort(a.begin(), a.end());
				queue<double> q;
				int j;
				for (j = 0; j < a.size(); j++) {
					if (q.empty() || !check(q.front(), a[j])) {
						q.push(a[j]);
					} else {
						break;
					}
				}
				//printf("q = %d\n", q.size());
				for (; j < a.size() * 2; j++) {
					while (!q.empty() && check(q.front(), a[j % a.size()])) {
						q.pop();
					}
					q.push(a[j % a.size()]);
					//printf("q = %d\n", q.size());
					if (q.size() < ans) ans = q.size();
				
				}
				
			}
			printf("%d\n", ans - 1);
		}
		
	}
	return 0;
}