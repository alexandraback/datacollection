#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>
#include<vector>
#include<cstring>
#include<cmath>
#define INF 0x3fffffff
#define pb push_back
#define pn(x) cerr<<x<<endl

using namespace std;
typedef long long ll;
const int maxv=1e6+20;
typedef pair<int,int> P;///num,pos

int T,t=0;
int r,c,n;
bool board[20][20];
int ma;
int dirx[4]={1,-1,0,0};
int diry[4]={0,0,1,-1};
int dfs(int pos,int used,int near){
	if(pos==r*c){
		if(used==n)
			return near;
		else{ 
			return INF;
		}
	}
	if(used==n) return near;
	int x=pos/c,y=pos%c;/////x~r,y~c
//	cout<<x<<" "<<y<<" "<<used<<" "<<near<<endl;
//	cout<<"board"<<endl;
/*	for(int i=0;i<r;i++){
		
		for(int j=0;j<c;j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}*/
	int addn=0;
	for(int i=0;i<4;i++){
		int dx=x+dirx[i],dy=y+diry[i];
		if(dx>=0&&dx<r&&dy>=0&&dy<c){
			if(board[dx][dy])
				addn++;
		}
	}
//	cout<<"add"<<addn<<endl;
	board[x][y]=1;
	int ans=dfs(pos+1,used+1,near+addn);
	board[x][y]=0;
	ans=min(dfs(pos+1,used,near),ans);
	return ans;
}
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin>>T;
	while(T--){
		t++;
		cin>>r>>c>>n;
		if(r>c) swap(r,c);
		memset(board,0,sizeof board);
		printf("Case #%d: %d\n",t,dfs(0,0,0));
	}
	
    return 0;
}