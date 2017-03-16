#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int main(){
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++cas) {
		printf("Case #%d:", cas);
		int n;
		scanf("%d", &n);
		char strings[100][101];
		for(int i = 0;i < n; ++i) {
			scanf("%s", strings[i]);
		}
		int ptr[100];
		for (int i = 0; i < n; ++i) {
			ptr[i] = 0;
		}
		int len[100];
		bool flag = true;
		int ans = 0;
		while (flag) {
			char cur = strings[0][ptr[0]];
			if (!cur) {
				bool chk = true;
				for (int i = 0; i < n; ++i) {
					if (strings[i][ptr[i]]) chk = false;
				}
				flag = flag && chk;
				break;
			}
			for (int i = 0; i < n; ++i) {
				len[i] = ptr[i];
				while(strings[i][ptr[i]] == cur) ++ptr[i];
				len[i] = ptr[i] - len[i];
			}
			sort(len, len + n);
			if (len[0] == 0) flag = false;
			int mid = len[n / 2];
			for (int i = 0; i < n; ++i) {
				ans += abs(len[i] - mid);
			}
		}

		if (flag) {
			printf(" %d\n", ans);
		}
		else {
			printf(" Fegla Won\n");
		}
	}
	return 0;
}
