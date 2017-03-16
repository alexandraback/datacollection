#include <cstdio>
#include <cstring>

#include <algorithm>

const int maxl = 1000;
const int maxn = 1000;

char str[maxn][maxl];
int num[maxn][maxl];
int values[maxn];
int N, commonLen;

void Squeeze(char *str, int *num) {
	int len = strlen(str);
	int _len = 1;
	num[0] = 1;
	for (int i = 1; i < len; i++)
		if (str[i] != str[_len - 1]) {
			num[_len] = 1;
			str[_len++] = str[i];
		} else num[_len - 1]++;
	str[_len] = 0;
}

void NoSolution() {
	printf("Fegla Won\n");
}

void Solve() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%s", str[i]);

	char base[maxl], newStr[maxl];
	strcpy(base, str[0]);
	Squeeze(base, num[0]);
	
	for (int i = 1; i < N; i++) {
		strcpy(newStr, str[i]);
		Squeeze(newStr, num[i]);
		if (strcmp(base, newStr)) {
			NoSolution();
			return;
		}
	}

	//printf("base = %s\n", base);

	commonLen = strlen(base);

	int ans = 0;
	for (int dig = 0; dig < commonLen; dig++) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			values[i] = num[i][dig];
			sum += values[i];
		}
		std::sort(values, values + N);
		int minSum = 0x7fffffff;
		int prefix = 0;
		for (int i = 0; i < N; i++) {
			int leftSum = i * values[i] - prefix;
			int rightSum = (sum - prefix - values[i]) - (N - 1 - i) * values[i];
			if (leftSum + rightSum < minSum)
				minSum = leftSum + rightSum;
			prefix += values[i];
		}
		ans += minSum;
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}