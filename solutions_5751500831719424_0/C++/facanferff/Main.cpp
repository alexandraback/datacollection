#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define FOR(i,s,e) for (int i = int(s); i < int(e); i++)
#define FORIT(i,c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define sz(v) (int)v.size()
#define all(c) (c).begin(), (c).end()

typedef long long int ll;

// %I64d for ll in CF

int main() {
	int t;
	scanf("%d", &t);
	int test = 1;
	while (t--) {
		int n;
		scanf("%d", &n);
		string strs[n];
		char line[105];
		getchar();
		for (int i = 0; i < n; i++) {
			scanf(" %s", line);
			strs[i] = string(line);
			getchar();
		}

		bool possible = true;
		int i = 0, j = 0;
		int len = strs[0].size();
		int res = 0;
		while (i < strs[0].size() || j < strs[1].size()) {
			if (i == strs[0].size() || j == strs[1].size()) {
				possible = false;
				break;
			}

			char ci = strs[0][i];
			char cj = strs[1][j];
			if (ci != cj) {
				possible = false;
				break;
			}

			int cnt1 = 1, cnt2 = 1;
			for (int i1 = i + 1; i1 < strs[0].size(); i1++) {
				if (strs[0][i1] != ci) break;
				cnt1++;
			}
			for (int j1 = j + 1; j1 < strs[1].size(); j1++) {
				if (strs[1][j1] != cj) break;
				cnt2++;
			}

			res += max(cnt1, cnt2) - min(cnt1, cnt2);

			for (; ci == strs[0][i] && i < strs[0].size(); i++);
			for (; cj == strs[1][j] && j < strs[1].size(); j++);
		}

		printf("Case #%d: ", test);
		if (!possible) printf("Fegla Won");
		else printf("%d", res);
		printf("\n");
		test++;
	}
	return 0;
}
