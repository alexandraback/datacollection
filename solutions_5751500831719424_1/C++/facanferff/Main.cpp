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

#define NMAX 105

string strs[NMAX];
int pos[NMAX];
int n;

bool canadvance() {
	for (int z = 0; z < n; z++) {
		if (pos[z] < strs[z].size()) return true;
	}

	return false;
}

int main() {
	int t;
	scanf("%d", &t);
	int test = 1;
	while (t--) {
		scanf("%d", &n);
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

		memset(pos, 0, sizeof pos);

		while (canadvance()) {
			for (int z = 0; z < n; z++) {
				if (pos[z] == strs[z].size()) {
					possible = false;
					break;
				}
			}

			if (!possible) break;

			char c = strs[0][pos[0]];

			for (int z = 0; z < n; z++) {
				if (strs[z][pos[z]] != c) {
					possible = false;
					break;
				}
			}

			if (!possible) break;

			int cnt[n];
			for (int z = 0; z < n; z++) {
				cnt[z] = 1;
				int i1;
				for (i1 = pos[z] + 1; i1 < strs[z].size() && c == strs[z][i1]; cnt[z]++, i1++);
				pos[z] = i1;
			}

			int best = 1e9;
			for (int k = 1; k <= 100; k++) {
				int temp = 0;
				for (int z = 0; z < n; z++) {
					temp += abs(k - cnt[z]);
				}

				best = min(best, temp);
			}

			res += best;
		}

		printf("Case #%d: ", test);
		if (!possible) printf("Fegla Won");
		else printf("%d", res);
		printf("\n");
		test++;
	}
	return 0;
}
