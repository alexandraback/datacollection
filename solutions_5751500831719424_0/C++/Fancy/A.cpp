#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[105];
char s[110];
int main() {
	int testnum, n, l;
	string os, ns;
	scanf("%d", &testnum);
	for (int test = 1; test <= testnum; test++) {
		scanf("%d", &n);
		os = "";
		bool fail = false;
		for (int i = 0;i < n;i++) {
			scanf("%s", s);
			if (fail) continue;
			v[i].clear();
			ns = "";
			l = 1;
			for (int j = 1;s[j];j++) {
				if (s[j] != s[j - 1]) {
					v[i].push_back(l);
					ns += s[j - 1];
					l = 1;
				} else {
					l++;
				}
			}
			v[i].push_back(l);
			ns += s[strlen(s) - 1];
			if (os != "" && ns != os) {
				fail = true;
				continue;
			}
			if (os == "")
				os = ns;
		}
		int ans = 0;
		if (!fail) {
			for (int i = v[0].size() - 1;i >= 0;i--) {
				vector<int> t;
				for (int j = 0;j < n;j++) {
					t.push_back(v[j][i]);
				}
				sort(t.begin(), t.end());
				int mid = t[n / 2];
				for (int j = 0;j < n;j++) {
					ans += (t[j] > mid) ? t[j] - mid : mid - t[j];
				}
			}
		}
		printf("Case #%d: ", test);
		if (fail)
			puts("Fegla Won");
		else
			printf("%d\n", ans);
	}
	return 0;
}
