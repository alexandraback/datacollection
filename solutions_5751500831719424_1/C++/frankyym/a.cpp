#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for (int t=0; t<T; ++t) {
		int N;
		scanf("%d", &N);

		char words[200];
		bool valid = true;
		string base;

		vector<int> all[200];

		for (int i=0; i<N; ++i) {
			scanf("%s", words);
			if (i == 0) {
				base = string(words);
				base.erase(unique(base.begin(), base.end()), base.end());
			}
			else {
				string cur(words);
				cur.erase(unique(cur.begin(), cur.end()), cur.end());
				if (base != cur) valid = false;
			}
			if (!valid) continue;

			int cnt = 1, pos = 0;
			char ch = words[0];
			int m = strlen(words);
			for (int j=1; j<=m; ++j)
				if (ch == words[j]) ++cnt;
				else {
					all[pos].push_back(cnt);
					++pos;
					ch = words[j];
					cnt = 1;
				}
		}

		if (!valid) {
			printf("Case #%d: Fegla Won\n", t+1);
		}
		else {
			int ret = 0, pos = base.size();
			for (int j=0; j<pos; ++j) {
				sort(all[j].begin(), all[j].end());

				int mid = all[j][all[j].size() / 2];
				for (int k=0; k<all[j].size(); ++k) ret += max(all[j][k] - mid, mid - all[j][k]);
			}
			printf("Case #%d: %d\n", t+1, ret);
		}
	}
	return 0;
}
