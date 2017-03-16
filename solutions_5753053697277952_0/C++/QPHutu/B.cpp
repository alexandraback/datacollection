#include <bits/stdc++.h>

using namespace std;

const int N = 30;

int a[N], n;

int get_max() {
	int p1 = -1, m1 = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] > m1) {
			m1 = a[i];
			p1 = i;
		}
	}
	return p1;
}

void solve() {
	scanf("%d", &n);
	int sum = 0;
	for(int i = 0; i < n; i++) {
		scanf("%d", a + i);
		sum += a[i];
	}
	while(sum > 0) {
		int p1 = get_max();
		sum --; a[p1] --;
		int p2 = get_max();
		if(p2 == -1 || sum >= a[p2] * 2) {
			printf(" %c", 'A' + p1);
		} else {
			sum --; a[p2] --;
			printf(" %c%c ", 'A' + p1, 'A' + p2);
		}
	}
	puts("");
}

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		printf("Case #%d:", i);
		solve();
	}
	return 0;
}