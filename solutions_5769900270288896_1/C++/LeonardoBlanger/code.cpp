#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <stack>
#include <cstring>
#include <cmath>
#include <sstream>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <list>

using namespace std;

#define INF (1 << 30)

vector< vector<int> > grid;

int main(){
	freopen("B-large.in", "r", stdin);
	freopen("output", "w", stdout);
	int tcase = 0;

	int T;
	scanf("%d", &T);

	while(T--){
		int R, C, N;
		scanf("%d%d%d", &R, &C, &N);
		grid.assign(R, vector<int>(C, false));

		int temp = N;

		for(int i=0; i<R and N > 0; i++){
			for(int j=0; j<C and N > 0; j++){
				if(i%2 == j%2){
					grid[i][j] = true;
					N--;
				}
			}
		}

		int unhappy1 = 0;

		for(int i=0; i<R and N > 0; i++){

			if(!grid[i][0]){
				grid[i][0] = true;

				if(i == 0 or i == R-1){
					unhappy1 += 2;
				} else {
					unhappy1 += 3;
				}
				
				N--;
			}

			if(N == 0) break;

			if(!grid[i][C-1]){
				grid[i][C-1] = true;

				if(i == 0 or i == R-1){
					unhappy1 += 2;
				} else {
					unhappy1 += 3;
				}
				
				N--;
			}		
		}

		for(int j=0; j<C and N > 0; j++){

			if(!grid[0][j]){
				grid[0][j] = true;

				if(j == 0 or j == C-1){
					unhappy1 += 2;
				} else {
					unhappy1 += 3;
				}
				
				N--;
			}

			if(N == 0) break;

			if(!grid[R-1][j]){
				grid[R-1][j] = true;

				if(j == 0 or j == C-1){
					unhappy1 += 2;
				} else {
					unhappy1 += 3;
				}
				
				N--;
			}		
		}

		unhappy1 += N * 4;

		//***********************************************
		grid.assign(R, vector<int>(C, false));
		N = temp;

		for(int i=0; i<R and N > 0; i++){
			for(int j=0; j<C and N > 0; j++){
				if(i%2 != j%2){
					grid[i][j] = true;
					N--;
				}
			}
		}

		int unhappy2 = 0;

		for(int i=0; i<R and N > 0; i++){

			if(!grid[i][0]){
				grid[i][0] = true;

				if(i == 0 or i == R-1){
					unhappy2 += 2;
				} else {
					unhappy2 += 3;
				}
				
				N--;
			}

			if(N == 0) break;

			if(!grid[i][C-1]){
				grid[i][C-1] = true;

				if(i == 0 or i == R-1){
					unhappy2 += 2;
				} else {
					unhappy2 += 3;
				}
				
				N--;
			}		
		}

		for(int j=0; j<C and N > 0; j++){

			if(!grid[0][j]){
				grid[0][j] = true;

				if(j == 0 or j == C-1){
					unhappy2 += 2;
				} else {
					unhappy2 += 3;
				}
				
				N--;
			}

			if(N == 0) break;

			if(!grid[R-1][j]){
				grid[R-1][j] = true;

				if(j == 0 or j == C-1){
					unhappy2 += 2;
				} else {
					unhappy2 += 3;
				}
				
				N--;
			}		
		}

		unhappy2 += N * 4;

		printf("Case #%d: %d\n", ++tcase, min(unhappy1, unhappy2));
	}
}