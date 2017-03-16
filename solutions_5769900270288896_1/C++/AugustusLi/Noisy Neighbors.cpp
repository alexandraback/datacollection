#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		int r, c, n;
		scanf("%d%d%d", &r, &c, &n);
		if (r > c) swap(r, c);
		int hfL = (r*c+1)/2;
		if (n <= hfL) {
			printf("Case #%d: 0\n", cas);
			continue;
		}
		
		int maxUnhappy = r*(c-1)+c*(r-1);		
		int rest = r*c-n;
		if (r >= 3) {
			int ans = 0;
			int inner = (r-2)*(c-2);
			int hfInnerL = (inner+1)/2;
			int edge = ((r-2)/2+(c-2)/2)*2;
			if (rest <= hfInnerL) {
				ans = maxUnhappy-rest*4;
			}
			else if (rest <= hfInnerL+edge) {
				int egRest = rest-hfInnerL;
				ans = maxUnhappy-hfInnerL*4-egRest*3;
			}
			else {
				//int cnRest = rest-hfInnerL-edge;
				//ans = maxUnhappy-hfInnerL*4-edge*3-cnRest*2;
				int more = n-hfL;
				if (r*c%2 == 1) {
					ans = more*3;
				}
				else {
					ans = more*2;
				}
			}
			printf("Case #%d: %d\n", cas, ans);
		}
		else if (r == 1) {
			int ans = maxUnhappy-rest*2;
			printf("Case #%d: %d\n", cas, ans);
		}
		else if (r == 2) {
			int ans = 0;
			int edge = c-2;
			if (rest <= edge) {
				ans = maxUnhappy-rest*3;
			}
			else {
				int cnRest = rest-edge;
				ans = maxUnhappy-edge*3-cnRest*2;
			}
			printf("Case #%d: %d\n", cas, ans);
		}
	}
	return 0;
}