#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using std::min;

const int MaxN = 111;

int n;
char words[MaxN][MaxN];
int count[MaxN][MaxN];

int solve() {
	char key[MaxN], p = '\0';
	int key_len = 0;
	memset(count, 0, sizeof(count));
	for (char *s = words[0]; *s != '\0'; ++ s) {
		if (*s != p) key[key_len++] = *s;
		p = *s;
	}
	key[key_len] = '\0';
	for (int i = 0; i < n; ++ i) {
		int k = -1;
		char p = '\0';
		for (char *s = words[i]; *s != '\0'; ++ s) {
			if (*s != p) ++ k;
			p = *s;
			if (p != key[k]) return -1;
			++ count[i][k];
		}
		if (k + 1 != key_len) return -1;
	}
	int result = 0;
	for (int i = 0; i < key_len; ++ i) {
		int mt = 0xFFFF;
		for (int k = 1; k <= 100; ++ k) {
			int sum = 0;
			for (int j = 0; j < n; ++ j) {
				sum += abs(count[j][i] - k);
			}
			mt = min(sum, mt);
		}
		result += mt;
	}
	return result;
}

int main() {
	int tests_count;
	scanf("%d", &tests_count);
	for (int test = 1; test <= tests_count; ++ test) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++ i) {
			scanf("%s", words[i]);
		}
		int result = solve();
		if (result < 0) {
			printf("Case #%d: Fegla Won\n", test);
		} else {
			printf("Case #%d: %d\n", test, result);
		}
	}
	return 0;
}
