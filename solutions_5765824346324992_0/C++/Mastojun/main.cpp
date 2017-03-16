#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>

using namespace std;
int T;
int B;
int N;
int M[1000];

int getLcm() {
	int result = 1;
	int MC[1000];
	for(int i = 0; i < B; i++) {
		MC[i] = M[i];
	}
	for(int i = 2; i < 25; i++) {
		bool has = false;
		for(int j = 0; j < B; j++) {
			if(MC[j] % i == 0) {
				has = true;
				MC[j] /= i;
			}
		}
		if(has) {
			result *= i;
			i--;
		}
	}
	return result;
}

int getLoopCount(int lcm) {
	int result = 0;
	for(int i = 0; i < B; i++) {
		result += lcm / M[i];
	}
	return result;
}

int solve(int n) {
	N %= n;
	if(N == 0) N = n;
	int MC[1000] = {0};
	

	int result = 0;
	for(int i = 0; i < N; i++) {
		int mi = 0;
		int mv = MC[0];
		for(int j = 1; j < B; j++) {
			if(mv > MC[j]) {
				mv = MC[j];
				mi = j;
			}
		}
		MC[mi] += M[mi];
		result = mi;
	}
	return result;
}

int main() {
	
	scanf("%d", &T);

	for(int c = 1; c <= T; c++) {
		scanf("%d %d", &B, &N);
		for(int i = 0; i < B; i++) {
			scanf("%d", M+i);
		}

		int lcm = getLcm();
		int loop = getLoopCount(lcm);
		printf("Case #%d: %d\n", c, solve(loop) + 1);

	}

	return 0;
}
