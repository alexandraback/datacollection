#include <iostream>
#include <algorithm>
using namespace std;

int dp[20][20][20];
int const INF = 10000;

int main() {
	for(int i = 0; i < 20; i++) {
		for(int j = 0; j < 20; j++) {
			for(int k = 0; k < 20; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
	for(int i = 0; i < 16; i++) {
		for(int j = i; (i+1) * (j+1) <= 16; j++) {
			for(int k = 0; k < (1 << ((i+1)*(j+1))); k++) {
				int n = 0;
				int tmp = 0;
				int board[18][18] = {0};
				for(int l = 0; l < (i+1)*(j+1); l++) {
					if(k & (1 << l)) {
						n++;
						board[l / (j+1) + 1][l % (j+1) + 1] = 1;
					}
				}
				for(int l = 0; l < (i+1); l++) {
					for(int m = 0; m < (j+1); m++) {
						if(board[l+1][m+1]) {
							const int dxy[] = {0,1,0,-1,0};
							for(int x = 0; x < 4; x++) {
								tmp += board[l+1 + dxy[x]][m+1 + dxy[x+1]];
							}
						}
					}
				}
				dp[i][j][n] = min(dp[i][j][n], tmp);
			}
		}
	}

	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		int R, C;
		int N;
		cin >> R >> C >> N;
		if(R > C)
			swap(R, C);
		cout << "Case #" << t+1 << ": " << dp[R-1][C-1][N] / 2 << endl;
	}
}
