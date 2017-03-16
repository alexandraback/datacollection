#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int B, N;
int t[2000];

bool after(long long time) {
	if (time == 0) return true;
	
	long long cnt = 0;
	for (int i = 0; i < B; ++i) {
		cnt += (time - 1ll) / (long long)t[i] + 1ll;
	}
	if (cnt >= N) return false;
	return true;
	/*
	++time;
	cnt = 0;
	for (int i = 0; i < B; ++i) {
		cnt += (time - 1ll) / (long long)t[i] + 1ll;
	}
	if (cnt < N) 
	*/
}

void work() {
	scanf("%d%d", &B, &N);
	int longest = 0;
	for (int i = 0; i < B; ++i) {
		scanf("%d", &t[i]);
		longest = max(longest, t[i]);
	}
	
	long long l = (long long)0, r = (long long)longest * (long long)(N / B + 3);
	while (l < r) {
		long long mid = (l + r + 1ll) >> 1;
		if (after(mid)) l = mid; else r = mid - 1;
	}
	
	int cnt = 0;
	for (int i = 0; i < B; ++i) {
		cnt += (l - 1ll) / (long long)t[i] + 1ll;
	}
	int rest = N - cnt;
	for (int i = 0; i < B; ++i) {
		if (l % (long long)t[i] == 0) {
			--rest;
			if (rest == 0) {
				printf("%d\n", i + 1);
				return;
			}
		}
	}
	printf("Somewhere Wrong!\n");
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
