#include <cstdio>
//#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
/*
int unhappy(vector<vector<bool> > &APTs) {
    int i, j;
    int uh = 0;
    int row = APTs.size();
    int col = APTs[0].size();
    for (i = 0; i < row; i++) {
    	for (j = 0; j < col; j++) {
    		if (APTs[i][j] == true) {
    			if (i + 1 < row) {
    				uh += APTs[i+1][j];
    			}
    			if (j + 1 < col) {
    				uh += APTs[i][j+1];
    			}
    		}
    	}
    }
    return uh;
}
*/
int getScore(vector<vector<bool> > &APTs, int r, int c, int score) {
	int row = APTs.size();
	int col = APTs[0].size();
	if (r - 1 >= 0) {
		score += APTs[r - 1][c];
	}
	if (c - 1 >= 0) {
		score += APTs[r][c - 1];
	}
	if (r + 1 < row) {
		score += APTs[r + 1][c];
	}
	if (c + 1 < col) {
		score += APTs[r][c + 1];
	}
	return score;
}

void helper(vector<vector<bool> >& APTs, int n, int &uh, int N, int score, vector<vector<bool> > visited) {
	//if (unhappy(APTs) >= uh)
	//printf("%d\n", n);
	if (score >= uh)
		return;
	if (n == N) {
		//uh = min(uh, unhappy(APTs));
		uh = min(uh, score);
		return;
	}
	int i, j;
	int R = APTs.size();
	int C = APTs[0].size();
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (APTs[i][j] || visited[i][j])
				continue;
			APTs[i][j] = true;
			visited[i][j] = true;
			helper(APTs, n + 1, uh, N, getScore(APTs, i, j, score), visited);
			APTs[i][j] = false;
		}
	}
}

int sol(int R, int C, int N) {
	if (N == 1)
		return 0;
	if (N == R * C)
		return 2 * R * C - C - R;
	vector<vector<bool> > visited(R, vector<bool>(C, false));
	vector<vector<bool> > APTs(R, vector<bool>(C, false));
	int uh = INT_MAX;
	helper(APTs, 0, uh, N, 0, visited);
	return uh;
}

int main() {
	int T, R, C, N;
	int i;
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		scanf("%d%d%d", &R, &C, &N);
		printf("Case #%d: %d\n", i, sol(R, C, N));
	}
}