#include <stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		int r,c,n;
		scanf("%d%d%d",&r,&c,&n);
		int flg[r][c],ans=r*c*4;
		for(int j=0; j<(1<<r*c); j++){
			int sum = 0;
			for(int y=0; y<r; y++)
				for(int x=0; x<c; x++){
					flg[y][x] = (j>>y*c+x)%2;
					sum += flg[y][x];
				}
			if(sum != n)
				continue;
			int cnt=0;
			for(int y=0; y<r; y++)
				for(int x=0; x<c-1; x++){
					if(flg[y][x] && flg[y][x+1])
						cnt++;
				}
			for(int y=0; y<r-1; y++)
				for(int x=0; x<c; x++){
					if(flg[y][x] && flg[y+1][x])
						cnt++;
				}
			if(cnt < ans)
				ans = cnt;
		}
		printf("Case #%d: %d\n",i+1,ans);
	}
	return 0;
}
