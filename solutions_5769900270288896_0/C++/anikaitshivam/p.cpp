#include<bits/stdc++.h>
using namespace std;

int DP[20][20];

void _update(int R, int C, int& ans)
{
    int cnt=0;
    for(int i=0;i<R;i++)
    {
	for(int j=0;j<C;j++)
	{
	    cnt+=(DP[i][j]==1 && i-1>=0 && DP[i-1][j]==1 ? 1 : 0);
	    cnt+=(DP[i][j]==1 && j+1<C && DP[i][j+1]==1 ? 1 : 0);
	    cnt+=(DP[i][j]==1 && i+1<R && DP[i+1][j]==1 ? 1 : 0);
	    cnt+=(DP[i][j]==1 && j-1>=0 && DP[i][j-1]==1 ? 1 : 0);
	}
    }
    if(cnt<ans)
	ans=cnt;
}

void recur(int N, int r, int c, int R, int C, int cnt, int& ans)
{
    if(cnt==N)
    {
	_update(R,C,ans);
	return;
    }
    if(c==C)
    {
	c=0;
	r++;
    }
    if(r==R)
	return;

    recur(N,r,c+1,R,C,cnt,ans);
    DP[r][c]=1;
    recur(N,r,c+1,R,C,cnt+1,ans);
    DP[r][c]=0;
    return;
}

int solve(int N, int R, int C)
{
    int ans=INT_MAX;
    for(int i=0;i<R;i++)
	for(int j=0;j<C;j++)
	    DP[i][j]=0;

    recur(N,0,0,R,C,0,ans);
    return ans/2;
}

int main()
{
    int T;cin>>T;for(int t=0;t<T;t++)
    {
	int R, C, N;
	cin>>R>>C>>N;
	cout<<"Case #"<<t+1<<": "<<solve(N,R,C)<<endl;
    }
    return 0;
}
