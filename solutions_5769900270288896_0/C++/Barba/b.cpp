#include <bits/stdc++.h>
using namespace std;

#define rREP(i,n) for(int i = (n)-1; i >= 0; i--)
#define REP(i,n) for(int i = 0; i < (n); i++)
#define rFOR(i,a,b) for(int i = (a); i >= (b); i--)
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define itr iterator

typedef long long lint;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;

// int cap[2*10100][2*10100];

int grid[17][17];

int main(){
	int nc;
	cin >> nc;
	FOR(caso, 1, nc){
		int r, c, n;
		cin >> r >> c >> n;
		int ans = 99999999;
		for(int mask = 0; mask < (1<<r*c); mask++){
			int nbits = 0;
			int temp = mask;
			while(temp > 0){
				temp -= temp &- temp;
				nbits++;
			}
			if(nbits != n)
				continue;
			for(int i = 0; i < r*c; i++){
				grid[i/c][i%c] = !!(mask & (1<<i));
				//printf("grid[%d][%d] = %d\n", i/c, i%c, grid[i/c][i%c]);
			}
			temp = 0;
			REP(row, r)
				REP(col, c){
					if(grid[row][col] == 0)
						continue;
					if(row > 0 && grid[row-1][col] > 0)
						temp++;
					if(row < r-1 && grid[row+1][col] > 0)
						temp++;
					if(col > 0 && grid[row][col-1] > 0)
						temp++;
					if(col < c-1 && grid[row][col+1] > 0)
						temp++;		
				}
			ans = min(ans, temp/2);
		}
		cout << "Case #" << caso << ": " << ans << endl;
	}
	return 0;
}