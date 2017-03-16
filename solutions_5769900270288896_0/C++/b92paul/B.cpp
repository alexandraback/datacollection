#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
const int N = 20;
bool board[N][N];

int calc(vector<int> idx,int R, int C){
	int x,y, ans =0;
	memset(board,0,sizeof(board));
	for(int i=0;i<idx.size();i++){
		int x = idx[i] / C;
		int y = idx[i] % C;
		board[x][y] = true;
	}
	for(int i = 0;i<R;i++){
		for(int j=0;j<C;j++){
			if(board[i][j]){
				if(board[i][j+1]) ans++;
				if(board[i+1][j]) ans++;
			}
		}
	}
	return ans;
}
int ans = 0;
void dfs(vector<int> tmp,int R,int C,int N,int now){
	if(tmp.size()==N){
		int tans = calc(tmp,R,C);
		ans = min(tans,ans);
		return;
	}
	if(now==R*C)return;
	dfs(tmp,R,C,N,now+1);
	tmp.push_back(now);
	dfs(tmp,R,C,N,now+1);
	return;
}

int main(){
	int T;
	scanf("%d",&T);
	int count = 0;
	while(count ++ <T){
		int R,C,N;
		scanf("%d %d %d",&R,&C,&N);
		vector<int> tmp;
		ans = 1<<20;
		dfs(tmp,R,C,N,0);
		printf("Case #%d: %d\n",count,ans);
	}
}
