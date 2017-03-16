#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,r,c,ans;
int s[20][20];

int f(){
	int u=0;
	for(int i=0;i<r;i++)
		for(int j=0;j<c;j++){
			if(s[i][j]==0) continue;
			if(s[i+1][j]==1) u++;
			if(s[i][j+1]==1) u++;
		}
		
	// for(int i=0;i<r;i++,puts(""))
	// 	for(int j=0;j<c;j++){
	// 		printf("%d ",s[i][j]);
	// 	}
	// 	printf("A: %d\n", u);
		
	return u;
}

void dfs(int man, int pos){
	
	if(pos>=r*c){
		if(man>0) return;
		ans = min(ans,f());
		return;
	}
	
	dfs(man, pos+1);
	
	if(man > 0){
		int row=pos/c;
		int col=pos%c;
		s[row][col]=1;
		dfs(man-1, pos+1);
		s[row][col]=0;
	}
}

int main(void){
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
		scanf("%d%d%d",&r,&c,&n);
		ans = (r-1)*c+(c-1)*r;
		dfs(n,0);
        
        printf("Case #%d: %d\n", tt, ans);
    }
    return 0;
}

