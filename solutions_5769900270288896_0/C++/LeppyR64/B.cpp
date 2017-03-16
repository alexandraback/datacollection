#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cassert>
using namespace std;
	
int N, R,C;
bool G[18][18];
	
int bf(int n, int r, int c) {
	if(c > C) {
		c = 1;
		r++;
	}
	if(r > R) {
		if(n != 0)
			return R * C * 5;
		else {
			int result = 0;
			for(int r = 1; r <= R; r++)
				for(int c = 1; c <= C; c++) {
					if(G[r][c] && G[r+1][c])
						result++;
					if(G[r][c] && G[r][c+1])
						result++;
				}
			return result;
		}
	}
	int result = bf(n, r, c + 1);
	if(n > 0) {
		G[r][c] = true;
		result = min(result, bf(n - 1, r, c + 1));
		G[r][c] = false;
	}
	return result;
}

int main() {
	int T; 
	cin >> T;
	for(int Z = 1; Z <= T; Z++) {
		cin >> R >> C >> N;
		cout << "Case #" << Z << ": " << bf(N,1,1) << endl;
	}
}