#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int TestCase, n, l[200], p[200], cnt[200];
char s[200][200];

int work()
{
	int ans = 0;
	memset(p, 0, sizeof(p));
	while (p[0] < l[0]) {
		char c = s[0][p[0]];
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i ++) {
			while (s[i][p[i]] == c) {
				p[i] ++;
				cnt[i] ++;
			}
		}
		sort(cnt, cnt + n);
		if (cnt[0] == 0) {
			return -1;
		}
		for (int i = 0; i < n; i ++) {
			ans += abs(cnt[i] - cnt[n / 2]);
		}
	}
	for (int i = 0; i < n; i ++)
	if (p[i] != l[i]) {
		return -1;
	}
	return ans;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &TestCase);
	for (int Case = 1; Case <= TestCase; Case ++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) {
			scanf("%s", s[i]);
			l[i] = strlen(s[i]);
		}
		int ret = work();
		printf("Case #%d: ", Case);
		if (ret == -1) {
			printf("Fegla Won\n");
		} else {
			printf("%d\n", ret);
		}
	}
	return 0;
}
