#include <bits/stdc++.h>
using namespace std;

const int MAXR = 100;
int N, T, R, C;
bool grid[MAXR][MAXR];

int bits(int x){return x ? (x&1) + bits(x>>1) : 0;}

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	cin >> T;
	for(int t=1; t<=T; ++t){
		cin >> R >> C >> N;
		memset(grid, 0, sizeof(grid));
		int best = INT_MAX;
		for(int x=0; x<(1<<(R*C)); ++x) if(N == bits(x)){
			for(int i=0; i<R; ++i) for(int j=0; j<C; ++j){
				if(x & (1 << (i*C + j))) grid[i][j] = true;
				else grid[i][j] = false;
			}
			int walls = 0;
			for(int i=0; i<R; ++i) for(int j=0; j<C; ++j){
				if(grid[i][j] && grid[i][j+1]) ++walls;
				if(grid[i][j] && grid[i+1][j]) ++walls;
			}
			best = min(best, walls);
		}
		cout << "Case #" << t << ": " << best << '\n';
	}
}
