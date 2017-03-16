#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>

using namespace std;

const int INF=0x3FFFFFFF;

int ans;

void dfs(vector<vector<bool> > x, int r, int c, int d, int score)
{
	if(d==0)
	{
		ans=min(ans,score);
	}
	else if(r==x.size()) return;
	else
	{
		int next_r=r, next_c=c+1;
		if(next_c==x[0].size()) next_r++, next_c=0;
		dfs(x,next_r,next_c,d,score);
		int new_score=score;
		x[r][c]=true;
		if(r>0 && x[r-1][c]) new_score++;
		if(c>0 && x[r][c-1]) new_score++;
		dfs(x,next_r,next_c,d-1,new_score);
		x[r][c]=false;
	}
}

int solve()
{
	int n, m, k;
	scanf("%d%d%d",&n,&m,&k);
	vector<vector<bool> > x(n,vector<bool>(m));
	ans=INF;
	dfs(x,0,0,k,0);
	return ans;
}

int main()
{
	int ncases;
	scanf("%d",&ncases);
	for(int i = 1; i <= ncases; i++)
	{
		printf("Case #%d: %d\n",i,solve());
	}
}
