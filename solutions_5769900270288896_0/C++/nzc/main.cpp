#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <climits>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)
#define MOD 1234567

int caseNo = 1, T, N, R, C, best;
int grid[20][20];

int inside(int x, int y) {
	return x >= 0 && x < R && y >= 0 && y < C;
}

int count(int loc) {
	int cnt = 0;
	memset(grid, 0, sizeof grid);
	for(int j = 0; j < R * C; j++)
		if(loc & (1 << j)) grid[j / C][j % C] = 1;
	for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++) {
			if(grid[i][j] != 1) continue;
			int x = i;
			int y = j + 1;
			if(inside(x, y) && grid[x][y] == 1) cnt++;
			x = i + 1;
			y = j;
			if(inside(x, y) && grid[x][y] == 1) cnt++;
		}
	return cnt;
}

int bitCnt(int loc) {
	int bit = 0;
	for(int j = 0; j < R * C; j++)
		if(loc & (1 << j)) bit++;
	return bit;
}

int main() {		
	// open files
	//freopen("homework.txt","r",stdin);
    //freopen("output.txt","w",stdout);	

	ofstream fout ("B_out.txt");
    ifstream fin ("B-small-attempt1 (1).in");
	fin >> T;
	while(T--) {
		fin >> R >> C >> N;
		best = INF;
		for(int i = 0; i < (1 << R * C); i++)
			if(bitCnt(i) == N)			
				best = min(best, count(i));
		fout << "Case #" << (caseNo++) << ": " << best << endl;
	}
	system ("pause");
	return 0;	
}