#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

const int INF = (1<<29);

int solve(int N, string *s) {
	int j[110] = {};
	int ans = 0;
	while (j[0] < (int)s[0].size()) {
		int c[110] = {};
		int f = s[0][j[0]];
		//printf("f=%d\n", f);
		for (int i = 0; i < N; i++) {
			int d = 0;
			while (j[i] < (int)s[i].size() && s[i][j[i]] == f) {
				d++;
				j[i]++;
			}
			if (d == 0)
				return -1;
			c[i] = d;
		}
		int r = INF;
		for (int k = 0; k <= 100; k++) {
			int d = 0;
			for (int i = 0; i < N; i++) {
				d += abs(c[i]-k);
			}
			r = min(r, d);
		}
		ans += r;
	}
	for (int i = 0; i < N; i++) {
		if (j[i] != (int)s[i].size())
			return -1;
	}
	return ans;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		string s[110];
		for (int i = 0; i < N; i++)
			cin >> s[i];
		int ans = solve(N, s);
		printf("Case #%d: ", i+1);
		if (ans < 0) {
			printf("Fegla Won\n");
		} else {
			printf("%d\n", ans);
		}
	}
}
