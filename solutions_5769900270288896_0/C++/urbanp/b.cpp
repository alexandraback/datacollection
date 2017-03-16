#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
#include <string.h>
#include <queue>
#include <limits>
#include <map>
#include <math.h> 
#include <iostream>
#include <set>

typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int R, C, N, board[20][20], best, used;

void solve();
void iter(int r, int c);
int count();

int main(){
	int N;
	scanf("%d", &N);

	for(int i=0; i<N; i++){
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}

void solve(){
	scanf("%d %d %d", &R, &C, &N);
	best = 10000, used = 0;
	memset(board, 0, sizeof(board));
	iter(-1, 0);
	printf("%d\n", best);
}

void iter(int r, int c){
	r++;
	if(r==R){
		r=0;
		c++;
	}
	if(c==C){
		if(used!=N)
			return;
		int tmp = count();
		if(tmp<best){
			best = tmp;
		}
		return;
	}

	board[r][c]=1;
	used++;
	iter(r, c);

	board[r][c]=0;
	used--;
	iter(r, c);
}

int count(){
	int ret = 0;
	for(int i=0; i<R-1; i++){
		for(int j=0; j<C; j++){
			if(board[i][j]==1 && board[i+1][j]==1)
				ret++;
		}
	}
	for(int i=0; i<R; i++){
		for(int j=0; j<C-1; j++){
			if(board[i][j]==1 && board[i][j+1]==1)
				ret++;
		}
	}
	return ret;
}