#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;


int T;
int N;
char in[100][101];
char un[100][101];
int c[101][101];
int len[100];

int solve() {
	for (int i = 0; i < N; ++i) {
		char* s = in[i]+1;
		char cur = in[i][0];
		int j = 0;
		char* o = un[i];
		int t = 1;
		while (*s) {
			if (*s == cur) {
				++ t;
			} else {
				o[j] = cur;
				c[j][i] = t;
				cur = *s;
				t = 1;
				++j;
			}
			++s;
		}
		o[j] = cur;
		c[j][i] = t;
		len[i] = j+1;
	}
	for (int i = 1; i < N; ++i) {
		if (len[i] != len[i-1]) {
			return -1;
		}
	}
	int l = len[0];
	for (int i = 0; i < l; ++i) {
		for (int j = 1; j < N; ++j) {
			if (un[j][i] != un[j-1][i]) {
				return -1;
			}
		}
	}
	int r = 0;
	for (int i = 0; i < l; ++i) {
		sort(c[i], c[i] + N);
		int count = 0;
		for (int j = 0; j < N; ++j) {
			count += abs(c[i][j] - c[i][N/2]);
		}
		r += count;
	}
	return r;
}


int main() {
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		scanf("%d", &N);
		for (int j = 0; j < N; ++j) {
			scanf("%s", in[j]);
		}
		int p = solve();
		if (p >= 0) {
			printf("Case #%d: %d\n", i+1, p);
		} else {
			printf("Case #%d: %s\n", i+1, "Fegla Won");
		}
	}
	return 0;
}