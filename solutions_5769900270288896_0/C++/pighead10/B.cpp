#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int
gcd(int a, int b)
{
	int c;
	while (a != 0) {
		c = a; a = b%a;  b = c;
	}
	return b;
}

int calculateUnhappiness(vector<vector<bool>> grid){
	int v = 0;
	for (int i = 0; i < grid.size(); i++){
		for (int j = 0; j < grid[i].size(); j++){
			if (j < grid[i].size()-1 && grid[i][j] && grid[i][j + 1]){
				v++;
			}
			if (i < grid.size() - 1 && grid[i][j] && grid[i + 1][j]){
				v++;
			}
		}
	}
	return v;
}

int main(){
	ifstream fin("B-small-attempt0.in");
	ofstream fout("output.txt");

	int T;
	fin >> T;
	
	for (int t = 1; t <= T; t++){
		int min = 100000000;
		int r, c, n;
		fin >> r >> c >> n;
		for (unsigned v = 0; v < pow(2, r*c); v++){
			vector<vector<bool>> grid(r, vector<bool>(c, false));
			int count = 0;
			unsigned t = v;
			while (t != 0){
				if (t & 0x1){
					count++;
				}
				t >>= 1;
			}
			if (count == n){
				t = v;
				for (int i = 0; i < r; i++){
					for (int j = 0; j < c; j++){
						if (t & 0x1){
							grid[i][j] = true;
						}
						t >>= 1;
					}
				}
				int un = calculateUnhappiness(grid);
				if (un < min) min = un;
			}
		}
		fout << "Case #" << t << ": " << min << endl;	
	}
	fout.close();
	return 0;
}