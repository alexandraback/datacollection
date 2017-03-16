#include <cstdio>
#include <algorithm>
#include <string>

using namespace std;

int T;
int N;
char str[100][101];

class StrCounter{
private:
	char c[100];
	int cnt[100];
	int idx;

public:
	StrCounter() { idx = -1; }
	void init() { idx = -1; }
	void insert(char ch) {
		if(idx != -1 && c[idx] == ch) {
			cnt[idx]++;
		} else {
			idx += 1;
			c[idx] = ch;
			cnt[idx] = 1;
		} 
	}
	int size() { return idx + 1; }
	char* str() { c[idx + 1] = 0; return c;}
	int counter(int i) { return cnt[i]; }

} strCounter[100];


bool isPossible() {
	for(int i = 1; i < N; i++) {
		if(strcmp(strCounter[i-1].str(), strCounter[i].str()) != 0)
			return false;

	}
	return true;
}

int solve() {
	int result = 0;
	for(int i = 0; i < strCounter[0].size(); i++) {
		int sum = 0;
		int m = 1000, M = 0;
		for(int j = 0; j < N; j++) {
			sum += strCounter[j].counter(i);
			m = min(strCounter[j].counter(i), m);
			M = max(strCounter[j].counter(i), M);
		}
		int idxResult = 987654321;
		for(int j = m; j <= M; j++) {
			int now = 0;
			for(int k = 0; k < N; k++) {
				now += abs(j - strCounter[k].counter(i));
			}
			idxResult = min(idxResult, now);
		}
		result += idxResult;
	}

	return result;
}

int main() {
	scanf("%d", &T);

	for(int c = 1; c <= T; c++) {

		scanf("%d", &N);

		for(int i = 0; i < N; i++) {
			scanf("%s", str[i]);
			strCounter[i].init();
			for(int j = 0; str[i][j]; ++j) {
				strCounter[i].insert(str[i][j]);
			}
		}

		printf("Case #%d: ", c);
		if(isPossible()) {
			printf("%d\n", solve());
		} else {
			puts("Fegla Won");
		}
	}
	return 0;
}
