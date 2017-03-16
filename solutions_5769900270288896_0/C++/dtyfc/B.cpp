#include <bits/stdc++.h>
using namespace std;
const int maxn = 10005;
int Solve(int r, int c, int n, int black, int flag) {
	n -= black;
	int ans = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0, cnt4 = 0;
	for(int i = 1; i <= r; i++) {
		if(i == 1 || i == r) {
			for(int j = 1; j <= c; j++) {
				if(((i + j) & 1) == flag) {
					if((i == 1 || i == r) && (j == 1 || j == c)) {
						if(r == 1) cnt1++; else cnt2++; 
					} else {
						if(r == 1) cnt2++; else cnt3++;
					}
				}
			}
		}
		if(i > 1 && i < r) {
			if(((i + 1) & 1) == flag) cnt3++;
			if(c != 1 && (((i + c) & 1)) == flag) cnt3++;
		}
	}
	cnt4 = r * c - black - cnt1 - cnt2 - cnt3;
	int t;
	t = min(n, cnt1);
	ans += t * 1;
	n -= t;
	t = min(n, cnt2);
	ans += t * 2;
	n -= t;
	t = min(n, cnt3);
	ans += t * 3;
	n -= t;
	t = min(n, cnt4);
	ans += t * 4;
	n -= t;
	return ans;
}
int main() {
#ifdef youmu
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B.ou", "w", stdout);
#endif
	int T, r, c, n, cases = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d%d", &r, &c, &n);
		if(r > c) swap(r, c);
		int ori_n = n;
		int black = (r * c + 1) / 2;
		int ans = 0;
		if(n <= black) {
			ans = 0;
		} else {
			if((r & 1) && (c & 1)) {	
				ans = min(Solve(r, c, n, black, 1), Solve(r, c, n, black - 1, 0));
			} else {
				ans = min(Solve(r, c, n, black, 0), Solve(r, c, n, black, 1));
			}
		}
		printf("Case #%d: %d\n", ++cases, ans);
	}
	return 0;
}

