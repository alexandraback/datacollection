#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>
#include <memory>
#include <map>
#include <queue>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include "sstream"

using namespace std;

const int dir[4][2] = {{0,1},{0,-1},{-1,0},{1,0}};

int a[20][20];

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int test;
	cin >> test;
	for (int tt = 1; tt <= test; tt++) {
		int n, m, q;
		cin >> n >> m >> q;
		int ans = 100*n*m;
		

		for (int i = 0; i < (1 << (n * m)); i++) {
			// cout << i  << endl;
			int j = i;
			int r = 0;
			int l = 0;
			int total = 0;
			for (int k = 1; k <= (n * m); k++) {
				a[r][l] = j % 2;
				if (a[r][l] == 1) total++;
				j = j / 2;
				l++;
				if (l >= m) {
					l = 0; r++;
				}
			}	
			if (total != q) continue;
			int cont = 0;
			// cout << i << ' ' << q << endl;
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < m; k++) {
					
					if (a[j][k] == 0) continue;
					for (int s = 0; s < 4; s++) {
						int jj = j + dir[s][0];
						int kk = k + dir[s][1];
						if (jj >= 0 && jj < n && kk >= 0 && kk < m && a[jj][kk] == 1) {
							cont++;
						}
					}
				}
			}
			if (cont / 2 < ans) ans = cont / 2;
		}
		cout << "Case #" << tt << ": " << ans << endl;
	}
}