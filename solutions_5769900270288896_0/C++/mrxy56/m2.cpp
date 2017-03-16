#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
bool vis[20],a[20][20];
int r,c,n,ans;
bool is_valid(int x,int y){
	if(x>=0 && x<r && y>=0 && y<c) return true;
	return false;
}
int cal(int x,int y){
	int ret=0;
	if(is_valid(x-1,y) && a[x-1][y]==true) ret++; 
	if(is_valid(x+1,y) && a[x+1][y]==true) ret++; 
	if(is_valid(x,y-1) && a[x][y-1]==true) ret++; 
	if(is_valid(x,y+1) && a[x][y+1]==true) ret++; 
	return ret;
}
void dfs(int n,int depth,int last){
	if(n==0){
        memset(a,0,sizeof(a));
        for(int i=0;i<r*c;i++){
        	if(!vis[i]) continue;
        	int temp=i;
        	int x=temp/c,y=temp%c;
        	a[x][y]=1;
        }
        int num=0;
        for(int i=0;i<r;i++)
        	for(int j=0;j<c;j++)
        		if(a[i][j]==true) num+=cal(i,j);
        num/=2;
        ans=min(ans,num);
		return;
	}
	for(int i=last+1;i<r*c;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(n-1,depth+1,i);
			vis[i]=false;
		}
	}
	return;
}
int main(){
	freopen("d.in","r",stdin);
	freopen("e.txt","w",stdout);
	int T,kase=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&r,&c,&n);
		memset(vis,0,sizeof(vis));
		ans=100;
		dfs(n,0,-1);
		printf("Case #%d: %d\n",++kase,ans);
	}
	return 0;
}