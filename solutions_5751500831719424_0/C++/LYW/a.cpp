#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int N;
char S[100][101];
char S_distinct[100][101];
int l[100];
int Count[100][101];

int abs(int a) {
	if (a < 0)
		return -a;
	return a;
}

bool isPossible(void) {
	for (int i = 0; i < N; i++) {
		int len = 0;
		char a = 0;
		for (int j = 0; j < l[i]; j++) {
			if (a != S[i][j]) {
				a = S[i][j];
				S_distinct[i][len] = a;
				len++;
				Count[i][len - 1] = 1;
			} else {
				Count[i][len - 1]++;
			}
		}
		S_distinct[i][len] = 0;
	}

	for (int i = 0; i < N; i++) {
		if (strcmp(S_distinct[i], S_distinct[0]))
			return false;
	}
	return true;
}

int getAns(void) {
	int len = strlen(S_distinct[0]);
	int ret = 0;

	for (int i = 0; i < len; i++) {
		int min_change = 10000;	
		for (int j = 1; j <= 100; j++) {
			int sum = 0;
			for (int k = 0; k < N; k++) {
				sum += abs(Count[k][i] - j);
			}
			min_change = min(min_change, sum);
		}
		ret += min_change;
	}
	return ret;
}

int main(void) {
	int testNum;
	scanf("%d", &testNum);
	for (int testCase = 1; testCase <= testNum; testCase++) {

		scanf("%d", &N);

		for (int i = 0; i < N; i++) {
			scanf("%s", S[i]);
			l[i] = strlen(S[i]);
		}

		if (!isPossible()) {
			printf("Case #%d: Fegla Won\n", testCase);
		} else {
			printf("Case #%d: %d\n", testCase, getAns());
		}

	}

	return 0;
}
