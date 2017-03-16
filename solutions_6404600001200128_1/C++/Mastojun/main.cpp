#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int isOk(int num, int N, int* m) {
	
	int eaten = min(m[0], num);
	int now = m[0] - eaten;
	int result = eaten;
	for(int i = 1; i < N - 1; i++) {
		if(now > m[i]) return -1;
		eaten = min(m[i], num);
		now = m[i] - eaten;
		result += eaten;
	}
	if(now > m[N-1]) return -1;
	return result;
}

int getSecond(int N, int* m) {
	for(int i = 0; i <= 100000; i++) {
		int ret = isOk(i, N, m);
		if(ret != -1) return ret;
	}
	return -1;
}

int main() {
	int T;
	scanf("%d", &T);

	for(int c = 1; c <= T; c++) {
		int N;
		scanf("%d", &N);

		int m[1000];
		for(int i = 0; i < N; i++) {
			scanf("%d", m + i);
		}

		int first = 0;
		for(int i = 1; i < N; i++) {
			if(m[i] < m[i-1]) first += m[i-1] - m[i];
		}
		
		printf("Case #%d: %d %d\n", c, first, getSecond(N, m));
	}

	return 0;
}
