#include <cstdio>
#include <cstdlib>
#include <algorithm>
#define INF 999

int i, j, m;
int numOfBlocks, N;
char source[110][110][2], tmpStr[110];
int tmpValue[110];

int solveQuest() {
	int result = 0, k = 0;
	char c = source[0][0][0];
	int a = 0, median = 0;

	for (k = 0; k < 110 ; k++) {
		c = source[0][k][0];
		if (c == 0) {
			for (j = 0; j < N; j++) {
				if (source[j][k][0] != 0)
					return INF;
			}
			break;
		}
		for (j = 0; j < N; j++) {
//			printf("debug j:%d k:%d c:%c t:%c\n", j, k, c, source[j][k][0]);
			if (source[j][k][0] != c)
				return INF;
			tmpValue[j] = source[j][k][1];
		}
		std::sort(tmpValue, tmpValue+N);

		if (N%2 == 0) {
			median = (tmpValue[N/2 - 1] + tmpValue[N/2]) / 2;
		} else {
			median = tmpValue[(N-1)/2];
		}

		for (j = 0; j < N; j++) {
			result += abs(tmpValue[j] - median);
		}

		memset(tmpValue, 0, N);
	}

	return result;
}

void addToSource(int indexF) {
//	printf("debug %d\n", indexF);
	int count = 1, k = 0;
	for (m = 1; m < 100; m++) {
		if (tmpStr[m] == tmpStr[m-1]) {
			count++;
		} else {
			source[indexF][k][0] = tmpStr[m-1];
			source[indexF][k][1] = count;
//			printf("debug 58: m:%d %c %d\n", m, source[indexF][k][0], source[indexF][k][1]);
			count = 1, k++;

			if (tmpStr[m] == '\0') {
				return;
			}
		}
	}
	if (tmpStr[m-1] == tmpStr[m-count]) {
		source[indexF][k][0] = tmpStr[m-1];
		source[indexF][k][1] = count;		
//		printf("debug 69: m:%d %c %d\n", m, source[indexF][k][0], source[indexF][k][1]);
	}
}

void clearSource() {
	for (m = 0; m < 110; m++) {
		for (int k = 0; k < 110; k++) {
			source[m][k][0] = 0, source[m][k][1] = 0;
		}
	}
}

int main() {
	scanf("%d", &numOfBlocks);
	for (i = 0; i < numOfBlocks; i++) {
		scanf("%d", &N);
		for (j = 0 ; j < N; j++) {
			scanf("%s", tmpStr);
//			printf("debug: %s\n", tmpStr);

			addToSource(j);
			memset(tmpStr, 0, 110);
		}

		// algorithm
		int result = solveQuest();
		if (result == INF) {
			printf("Case #%d: Fegla Won\n", i+1);
		} else {
			printf("Case #%d: %d\n", i+1, result);		
		}
		clearSource();
	}
	return 0;
}