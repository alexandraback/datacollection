#include <cstdio>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <vector>
using namespace std;

#define FOR(i,a,b) for(int i=int(a);i<=int(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
typedef long long int64;

int r, c, k;

int fill(int o) {
	int score = 0;
	vector<vector<int> > board(r, vector<int>(c, 0));
	board[0][o] = 1;
	FOR(i, 2, k) {
		int mi = 5, x, y;
		REP(i, r)
		REP(j, c) if (board[i][j] == 0) {
			int noise = 0;
			if (i > 0 && board[i-1][j]) ++noise;
			if (i < r-1 && board[i+1][j]) ++noise;
			if (j > 0 && board[i][j-1]) ++noise;
			if (j < c-1 && board[i][j+1]) ++noise;
			if (noise < mi) {
				mi = noise;
				x = i;
				y = j;
			}
		}
		board[x][y] = 1;
		score += mi;
	}
	/*
	REP(i, r) {
		REP(j, c) {
			if (board[i][j]) putchar('#');
			else putchar('.');
		}
		puts("");
	}
	*/
	return score;
}

int main() {
	int tN;
	scanf("%d", &tN);
	FOR(cN, 1, tN) {
		scanf("%d%d%d", &r, &c, &k);
		if (cN <= 800) continue;
		if (r > c) swap(r, c);
		int ans = 0;
		if (k > r*c/2) ans = fill(0);
		if (ans && r > 1) ans = min(ans, fill(1));
		printf("Case #%d: %d\n", cN, ans);
	}
}
