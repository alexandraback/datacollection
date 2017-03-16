#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

#define INF 100000000
int R, C, N;

int f[16][17][17];

void stat(int state, int &none, int &nnoise);
int solve(int state, int width, int num);

int 
statTwoCol(int lhs, int rhs) {
	int res = 0;
	int val = lhs & rhs;
	for (int i = 0; i < R; i++) {
		res += (val & (1 << i)) != 0;
	}
	return res;
}

void calcLargeWidth(int state, int width, int num) {
	int newstate;
	int res = INF;
	int none, nnoise;
	stat(state, none, nnoise);

	if (none > num) {
		f[state][width][num] = INF;
		return;
	}

	for (newstate = 0; newstate < (1 << R); newstate++) {
		int sub = solve(newstate, width - 1, num - none);
		int val = sub + nnoise + statTwoCol(state, newstate);
		res = min(res, val);
	}
	f[state][width][num] = res;
}

void stat(int state, int &none, int &nnoise) {
	int last = 0;
	int cur;
	none = 0;
	nnoise = 0;
	for (int i = 0; i < R; i++, last = cur) {
		cur = (state & (1 << i)) != 0;	
		if (cur == 1) {
			none++;
			if (last == 1) {
				nnoise++;
			}
		}
	}
}

void calc(int state, int width, int num) {
	if (width == 1) {
		int none, nnoise;
		stat(state, none, nnoise);
		// printf("state width num %d %d %d, none nnoise %d %d\n", state, width, num, none, nnoise); // TODO
		f[state][width][num] =
			none == num ? 
			nnoise :
			INF;
		return;
	}

	// width > 1
	calcLargeWidth(state, width, num);
}

int solve(int state, int width, int num) {
	if (f[state][width][num] == -1) {
		calc(state, width, num);
	}
	return f[state][width][num];
}

int
main(void) {
	int T;
	scanf("%d", &T);
	for (int seqno = 1; seqno <= T; seqno++) {
		scanf("%d%d%d", &R, &C, &N);
		if (R > C) {
			int tmp = R;
			R = C;
			C = tmp;
		}

		// f[state][W][N]
		int res = INF;
		memset(f, -1, sizeof(f));
		for (int state = 0; state < (1 << R); state++) {
			res = min(res, solve(state, C, N));
		}
		printf("Case #%d: %d\n", seqno, res);
	}
	return 0;
}
