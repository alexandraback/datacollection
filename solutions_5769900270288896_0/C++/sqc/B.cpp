#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <limits>
using namespace std;


void combine(vector< vector<bool> > &board, int curNum, int curR, int curC, int n, int &res, int curScore) {
	int r = board.size();
	int c = board[0].size();
	if (curNum == n) {
		res = min(res, curScore);
		return ;
	}
	int tmpScore = 0;
	int i = curR;
	int j = curC;
	for (; i < r; i++) {
		for (; j < c; j++) {
			board[i][j] = true;
			tmpScore = 0;
			if (i >= 1 && board[i - 1][j] == true) {
				tmpScore += 1;
			}
			if (j >= 1 && board[i][j - 1] == true) {
				tmpScore += 1;
			}
			combine(board, curNum + 1, i, j + 1, n, res, curScore + tmpScore);
			board[i][j] = false;
			
		}
		j = 0;
	}
}


int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	//freopen("B-large.in", "r", stdin);
	//freopen("B-large.out", "w", stdout);
	int t;
	int r, c, n;
	int l0, l1, l2, l3;
	int res = INT_MAX;
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		res = INT_MAX;
		scanf("%d %d %d", &r, &c, &n);
		vector< vector<bool> > board(r, vector<bool>(c, false));
		combine(board, 0, 0, 0, n, res, 0);
		printf("Case #%d: %d\n", tt, res);
	}
	return 0;
}