#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

char a[110][110];
vector<int> b[110];

string gao(string s) {
	s = s + '0';
	string ret;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] != s[i+1]) {
			ret = ret + s[i];
		}
	}
	return ret;
}

vector<int> gao2(string s) {
	s = s + '0';
	int t = 1;
	vector<int> ret;
	for (int i = 0; i < s.size() - 1; i++) {
		if (s[i] != s[i+1]) {
			ret.push_back(t);
			t = 1;
		} else {
			t++;
		}
	}
	return ret;
}

int main() {
	int T;
	freopen("x.txt", "r", stdin); freopen("w.txt", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", a[i]);
		}
		string r;
		r = gao(a[0]);
		int flag = 1;
		for (int i = 1; i < n; i++) {
			if (gao(a[i]) != r) {
				flag = 0;
				break;
			}
		}
		if (!flag) {
			printf("Case #%d: Fegla Won\n", cas);
			continue;
		}
		for (int i = 0; i < n; i++) {
			b[i] = gao2(a[i]);
		}
		int ans = 0;
		for (int i = 0; i < b[0].size(); i++) {
			int t = 1000000;
			for (int k = 1; k <= 100; k++) {
				int sum = 0;
				for (int j = 0; j < n; j++) {
					sum += abs(b[j][i] - k);
				}
				if (sum < t) t = sum;
			}
			ans += t;
		}
		printf("Case #%d: %d\n", cas, ans);
	}
}
