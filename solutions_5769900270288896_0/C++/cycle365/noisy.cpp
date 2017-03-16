#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int testCases, n, r, c;
int dr[2] = {0, -1};
int dc[2] = {-1, 0};
bool oc[16][16];

int getUnhap(int row, int col){
	int ans = 0;
	for(int i = 0; i < 2; i++){
		if(row+dr[i] < r && row+dr[i] >= 0 && col+dc[i] < c && col+dc[i] >= 0){
			if(oc[row+dr[i]][col+dc[i]]){
				ans++;
			}
		}
	}
	return ans;
}

int recurse(int row, int col, int pop, int unhap){
	/*
	printf("row = %d, col = %d, pop = %d, unhap = %d\n", row, col, pop, unhap);
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			printf("%d ", oc[r][c]);
		}printf("\n");
	}//*/
	if(col == c){
		return (pop == n) ? unhap : 2000000000;
	}
	int ans = 2000000000;
	int nr = row+1;
	int nc = col;
	if(nr == r){
		nr = 0;
		nc++;
	}
	ans = recurse(nr, nc, pop, unhap);
	oc[row][col] = true;
	ans = min(ans, recurse(nr, nc, pop+1, unhap + getUnhap(row, col)));
	oc[row][col] = false;
	return ans;
}

int main(){
	scanf("%d", &testCases);
	
	for(int t = 1; t <= testCases; t++){
		memset(oc, false, sizeof(oc));
		scanf("%d %d %d", &r, &c, &n);
		printf("Case #%d: %d\n", t, recurse(0, 0, 0, 0));
	}
}
