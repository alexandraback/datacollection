#include <iostream>
#include <utility>
#include <limits.h>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <stack>

typedef long long ll;
using namespace std;

int h, w, n;
ll mmin;
int board[18][18];

int mmove[4][2] = { { 0, 1 }, { 1, 0 }, { -1, 0 }, { 0, -1 } };

ll cal_unhappy(){
	int cnt = 0;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			for (int k = 0; k < 4; k++){
				if (board[i][j] == 0) continue;
				if (i + mmove[k][0] >= h || i + mmove[k][0] < 0 || j + mmove[k][1] >= w || j + mmove[k][1] < 0) continue;
				if (board[i + mmove[k][0]][j + mmove[k][1]] == 1)
					cnt++;
			}
		}
	}
	return cnt;
}


int main(){
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w+", stdout);
#endif
	int t;
	int caseNumber = 0;
	cin >> t;
	while (t--){
		cin >> h >> w >> n;
		mmin = LLONG_MAX;
		ll limit = pow(2, h * w);
		for (int i = 0; i <= limit; i++){
			int cnt = 0;
			for (int j = 1; j <= i; j  *= 2){
				if (j & i)
					cnt++;
			}
			if (cnt == n){
				int digit = 0;
				memset(board, 0, sizeof(board));
				for (int j = 1; j <= i; j *= 2){
					if (j & i){
						board[digit / w][digit % w] = 1;
					}
					digit++;
				}
				//for (int i = 0; i < h; i++){
				//	for (int j = 0; j < w; j++){
				//		cout << board[i][j];
				//	}
				//	cout << endl;
				//}
				//cout << endl;
				mmin = min(cal_unhappy(), mmin);
			}
		}
		if (mmin == LLONG_MAX)
			printf("Case #%d: 0\n", ++caseNumber);
		else 
			printf("Case #%d: %d\n", ++caseNumber, mmin / 2);
	}
}