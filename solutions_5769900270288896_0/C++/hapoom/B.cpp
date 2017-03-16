#include<stdio.h>
#include<windows.h>
#include<queue>
#include<vector>
using namespace std;

int getBit(int x)
{
	int c = 0;
	while(x){
		x &= (x-1);
		c++;
	}
	return c;
}

int main()
{
	freopen("B-small-attempt1.in","r",stdin);
	freopen("B-output.txt","w",stdout);
	int T;
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++){
		int R,C,N,ans=987654321,cnt=0;
		scanf("%d%d%d", &R, &C, &N);
		int maxi = 1<<R*C;
		for(int i = 0; i < maxi; i++){
			if( getBit(i) != N) continue;
			int j = i;
			int cell[20][20] = {0,};
			while(j){
				int kk = (j & -j), k = 0;
				while(kk){
					kk/=2;
					k++;
				}
				j &= (j-1);
				k--;
				cell[k/C][k%C] = 1;
			}
			cnt=0;
			for(int ii = 0; ii < R; ii++){
				for(int jj = 0; jj < C; jj++){
					if(cell[ii][jj] == 1 && cell[ii][jj+1] == 1) cnt++;
					if(cell[ii][jj] == 1 && cell[ii+1][jj] == 1) cnt++;
				}
			}
			if(ans>cnt)ans=cnt;
		}
		printf("Case #%d: %d\n", tc, ans);
	}
	return 0;
}