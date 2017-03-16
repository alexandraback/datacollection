#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;
int solve() {
	int N;
	char str[100][128];
	int p[100];
	scanf("%d", &N);
	gets(str[0]);
	vector<string> s;
	for (int i = 0; i < N; i++) {
		gets(str[i]);
		p[i] = 0;
	}
	int res = 0;
	char c;
	do {
		c = str[0][p[0]];
		vector<int> count;
		for (int i = 0; i < N; i++) {
			int cnt = 0;
			while (str[i][p[i]] == c) {
				p[i]++;
				cnt++;
			}
			if (cnt == 0) return -1;
			count.push_back(cnt);
		}
		nth_element(count.begin(), count.begin() + N / 2, count.end());
		int t = count[N / 2];
		for (int i = 0; i < count.size(); i++) {
			res += abs(t - count[i]);
		}
	} while (c != 0);
	return res;
}

int main() {
	int T;
	scanf("%d", &T);
	for (int c = 1; c <= T; c++) {
		printf("Case #%d: ", c);
		int r = solve();
		if (r == -1) {
			puts("Fegla Won");
		}
		else {
			printf("%d\n", r);
		}
	}
}