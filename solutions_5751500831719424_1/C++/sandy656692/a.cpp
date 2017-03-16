#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

const int N = 110;
char s[N][N];
int top[N];
int len[N];
int num[N];
char ch[N];

int main() {
	int T;
	scanf("%d\n", &T);
	for (int test = 1; test <= T; ++test) {
		int n;
		scanf("%d\n", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%s\n", s[i]);
			len[i] = strlen(s[i]);
			top[i] = 0;
		}
		bool flag = true;
		int ans = 0;
		while (flag) {
			bool finish = true;
			for (int i = 0; i < n; ++i) {
				if (top[i] < len[i]) {
					finish = false;
					break;
				}
			}
			if (finish) break;
			int maxn = 0;
			for (int i = 0; i < n; ++i) {
				num[i] = 0;
				ch[i] = s[i][top[i]];
				if (top[i] == len[i]) {
					flag = false;
					break;
				}
				while (top[i] < len[i] && s[i][top[i]] == ch[i]) {
					++top[i];
					++num[i];
				}
				maxn = max(maxn, num[i]);
			}
			for (int i = 1; i < n; ++i) {
				if (ch[i] != ch[0]) {
					flag = false;
					break;
				}
				
			}
			if (!flag) break;
			int minn = maxn * n;
			for (int t = 1; t <= maxn; ++t) {
				int sum = 0;
				for (int i = 0; i < n; ++i) {
					sum += abs(t - num[i]);
				}
				minn = min(minn, sum);
			}
			ans += minn;
		}
		printf("Case #%d: ", test);
		if (!flag) printf("Fegla Won\n");
		else printf("%d\n", ans);
	}
	return 0;
}