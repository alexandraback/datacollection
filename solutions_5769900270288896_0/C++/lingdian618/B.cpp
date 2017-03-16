#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 20;
const int oo = 0x3f3f3f3f;
int n, row, col;
int m[N][N];
int dx[] = {0, 1};
int dy[] = {1, 0};
int bits(int x){
	int ans = 0;
	while(x){
		ans += x&1;
		x >>= 1;
	}
	return ans;
}
int cal(){
	int ans = 0;
	for(int i=0; i<row; i++){
		for(int j=0; j<col; j++){
			for(int k=0; k<2; k++){
				int x = i + dx[k];
				int y = j + dy[k];
				if(i>=row || j>=col)	continue;
				if(m[i][j] && m[x][y])	ans++;
			}
		}
	}
	return ans;
}
int main()
{
	// freopen("B-small-attempt0.in", "r", stdin);
	// freopen("ou.txt", "w", stdout);
	int t, kase=0;
	scanf("%d", &t);
	// printf("%d\n", t);
	while(t--){
		scanf("%d%d%d", &row, &col, &n);
		int ans = oo;
		for(int i=0; i<(1<<row*col); i++){
			if(bits(i)!=n)	continue;
			memset(m, 0, sizeof(m));
			for(int j=0; j<row*col; j++){
				// printf("%d\n", j);
				int k = 1<<j;
				if(i&k){
					int x = j/col;
					int y = j%col;
					// if(x>=N || y>=N)	puts("fuck");
					m[x][y] = 1;
				}
			}
			ans = min(ans, cal());
		}
		printf("Case #%d: %d\n", ++kase, ans);
	}
	return 0;
}