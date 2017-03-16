#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <map>
#include <vector>
#include <set>

#define mk make_pair
#define pb push_back
typedef  long long  LL;

using namespace std;
int N,R,C;
int ans ;
int g[16][16];
int dx[4]={0,1,-1,0};
int dy[4]={1,0,0,-1};
void dfs(int x,int y,int pl,int tmp){
	if(pl==0){
		ans = ans>tmp? tmp:ans;
		return ;
	}
	if(x>R)	return ;
	int nx,ny;
	if(y<C)
		nx=x,ny=y+1;
	else
		nx=x+1,ny=1;
	dfs(nx,ny,pl,tmp);
	//place
	g[x][y]=1;
	int px,py;
	for(int i=0;i<4;i++){
		px=x+dx[i];
		py=y+dy[i];
		if(px>0 && px<=R && py>0 && py<=C){
			if(g[px][py])	tmp++;
		}
	}
	dfs(nx,ny,pl-1,tmp);
	g[x][y]=0;
	return ;
}

int main(){
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++){
		printf("Case #%d: ",cas);
		scanf("%d%d%d",&R,&C,&N);
		ans = 1048576;
		dfs(1,1,N,0);
		printf("%d\n",ans);
	}
	return 0;
}