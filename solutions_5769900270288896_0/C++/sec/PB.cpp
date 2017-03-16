#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
int b[17][17], use[11111];
int R, C, N, ans;
int valid(int x, int y){return x>=0&&y>=0;}
int calc(){
	int cnt=0;
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(b[i][j]){
				if(valid(i-1, j) && b[i-1][j]){
				cnt++;
				}
				if(valid(i, j-1) && b[i][j-1]){
					cnt++;
				}	
			}
			
		}		
	}
	// printf("cnt  = %d\n", cnt);
	return cnt;
}
void dfs(int p, int dep){
	int i, j;
	if(dep==N){
		memset(b, 0, sizeof(b));
		for(i=0;i<R*C;i++){
			if(use[i]){
				b[i/C][i%C]=1;
			}
		}
		ans=min(ans, calc());
		return ;
	}
	for(i=p;i<R*C;i++){
		if(!use[i]){
			use[i]=1;
			dfs(i+1, dep+1);
			use[i]=0;
		}
	}
}
int main(){
	int TN, ca=0;
	scanf("%d", &TN);
	
	while(TN--){
		scanf("%d%d%d", &R, &C, &N);
		if(N<=ceil(R*C/2))ans=0;
		else {
			ans=1e9;
			dfs(0, 0);
		}
		printf("Case #%d: %d\n", ++ca, ans);
	}
	return 0;
}