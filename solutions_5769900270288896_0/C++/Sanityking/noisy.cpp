#include <iostream>
#include <cstdio>
#include <fstream>
#include <cstring>
using namespace std;

int t, r, c, n, grid[30][30];
int main(){
	ifstream fin("B.in");
	ofstream fout("out.out");
	fin >> t;
	for(int i = 1; i <= t; ++i){
		fin >> r >> c >> n;
		int ans = 100000000;
		//cout << (1 << (r*c)) << endl;
		for(int cur = 0; cur < (1 << (r*c)); ++cur){
			int num = cur;
			int len = 0;
			while(num){
				if(num%2) ++len;
				num /= 2;
			}
			int noof = 0;
			if(len == n){
				//cout << cur << endl;
				//system("PAUSE");
				memset(grid, 0, sizeof grid);
				num = cur;
				for(int a = 1; a <= r; ++a){
					for(int b = 1; b <= c; ++b){
						grid[a][b] = num%2;
						num /= 2;
						if(grid[a][b] == 1){
							if(grid[a-1][b]) ++noof;
							if(grid[a][b-1]) ++noof;
						}
					}
				}
				ans = min(ans, noof);
			}
		}
		fout << "Case #" << i << ": " << ans << endl;
	}
	return 0;
}
