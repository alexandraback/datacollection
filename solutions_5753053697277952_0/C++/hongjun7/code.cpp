#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int n;
pair <int, int> a[33];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, runs; for (scanf("%d", &T), runs = 1; T--; runs++) {
		printf("Case #%d:", runs);
		scanf("%d", &n);
		int m = 0, s = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i].first); a[i].second = i;
			if (m < a[i].first) m = a[i].first;
			s += a[i].first;
		}
		bool oo = 0;
		while (s) {
			sort(a, a + n);
			reverse(a, a + n);
			string ss = "";
			for (int i = 0; i < n; i++) {
				if (a[i].first) {
					a[i].first--; s--;
					ss += 'A' + a[i].second;
					break;
				}
			}
			for (int i = 0; i < n; i++) {
				if (a[i].first > s / 2) {
					oo = 1;
					a[i].first--;
					ss += 'A' + a[i].second;
					s--;
					break;
				}
			}
			printf(" %s", ss.c_str());
		}
		puts("");
	}
}