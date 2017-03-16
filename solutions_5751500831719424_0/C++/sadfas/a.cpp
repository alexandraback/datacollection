#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

char a[200][200];
char *p[200];
int n, tn;

int main() {
	freopen("a.in", "r", stdin);

	scanf("%d", &tn);
	for (int ti = 0; ti < tn; ti ++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i ++) {
			scanf("%s", a[i]);
			p[i] = a[i];
		}

		bool bad = false;
		int ans = 0;
		while (true) {
			int nul = 0;
			char ch = 0;
			vector <int> v;
			for (int i = 0; i < n; i ++) {
//				printf("%s\n", p[i]);
				char c = *p[i];
//				printf("%c %c\n", ch, c);
				if (ch == 0) ch = c;
				if (c == 0) { nul ++; }
				else {
					if (ch != c) { bad = true; }
					int nn = 0;
					while (*p[i] == c) { nn ++; p[i] ++; }
					v.push_back(nn);
				}
			}
			if (nul == n) break;
			if (nul != 0) bad = true;
			if (bad) break;
			int m = 1000000;
			for (int j = 1; j <= 100; j ++) {
				int s = 0;
				for (int k = 0; k < v.size(); k ++) {
					s += abs(v[k] - j);
				}
				m = min(s, m);
			}
			ans += m;
		}
		printf("Case #%d: ", ti + 1);
		if (bad) printf("Fegla Won\n");
		else printf("%d\n", ans);
	}
	return 0;
}
