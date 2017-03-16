#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>

int a[111][111];
int b[111][111];
int na[111];
char s[111][111]; //maxlen
char ch[111][111];

void no() {
	printf("Fegla Won\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int qwe;
	scanf("%d\n", &qwe);
	for (int xxx = 1; xxx <= qwe; xxx++) {
		printf("Case #%d: ", xxx);
		int n;
		scanf("%d\n", &n);
		for (int i = 0; i < n; i++)
			na[i] = 0;
		for (int t = 0; t < n; t++) {
			scanf("%s\n", s[t]);
			int x = strlen(s[t]);
			// printf(">>!! %d\n", x);
			for (int i = 0; i < x;) {
				int cnt = 0, j;
				for (j = i; j < x && s[t][j] == s[t][i]; j++, cnt++);
				ch[t][na[t]] = s[t][i];
				a[t][na[t]++] = cnt;
				i = j;
			}
		}

		// for (int i = 0; i < n; i++) {
		// 	printf("^^ %d\n", na[i]);
		// 	for (int j = 0; j < na[i]; j++)
		// 		printf("%d%c", a[i][j], j == na[i] - 1 ? '\n' : ' ');
		// 	ch[i][na[i]] = 0;
		// 	printf("s:: %s\n", ch[i]);
		// }
		// return 0;

		bool t = true;
		for (int i = 1; i < n; i++)
			if (na[i] != na[i - 1]) {
				t = false;
				break;
			}
		if (!t) {
			no();
			continue;
		}
		for (int i = 1; t && i < n; i++)
			for (int j = 0; t && j < na[i]; j++) {
				if (ch[i][j] != ch[i - 1][j])
				 t = false;
			}
		if (!t) {
			no();
			continue;
		}
		// solution
		for (int i = 0; i < n; i++)
			for (int j = 0; j < na[i]; j++)
				b[j][i] = a[i][j];
		for (int i = 0; i < na[0]; i++)
			for (int j = 0; j < n; j++)
				a[i][j] = b[i][j];
		// for (int i = 0; i < na[0]; i++, printf("\n"))
		// 	for (int j = 0; j < n; j++)
		// 		printf("%d ", a[i][j]);

		for (int i = 0; i < na[0]; i++)
			std::sort(a[i], a[i] + n);

		int ans = 0;
		if (n % 2 == 1) {
			int mid = n / 2;
			for (int i = 0; i < na[0]; i++)
				for (int j = 0; j < n; j++)
					ans += abs(a[i][j] - a[i][mid]);
		}
		else {
			int mid = n / 2;
			for (int i = 0; i < na[0]; i++) {
				int s1 = 0, s2 = 0;
				for (int j = 0; j < n; j++)
					s1 += abs(a[i][j] - a[i][mid]);
				for (int j = 0; j < n; j++)
					s2 += abs(a[i][j] - a[i][mid + 1]);
				if (s1 < s2)
					ans += s1;
				else
					ans += s2;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
