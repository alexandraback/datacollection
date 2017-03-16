#include<iostream>
using namespace std;
bool T[100][100];

int check(int r,int c)
{
	int cnt = 0;
	for(int i= 0; i < r; i++)
		for(int j = 0; j < c-1; j++)
		{
			if(T[i][j] && T[i][j+1]) cnt++;
		}
	for(int i= 0; i < r-1; i++)
		for(int j = 0; j < c; j++)
		{
			if(T[i][j] && T[i+1][j]) cnt++;
		}
	return cnt;
}


void solve(int test)
{
	int R,C,N;
	scanf("%d%d%d",&R,&C,&N);
	int K =R*C;
	int answer = 2*1000*1000;
	for(int i = 0; i < (1<<K); i++)
	{
		int col = 0;
		for(int j = 0; j < K; j++)
		{
			int x = j/C;
			int y = j%C;
			if(i&(1<<j))
			{
				T[x][y]=true;
				col++;
			}
			else
			{
				T[x][y]= false;
			}
		}
		if(col == N)
		{
			int a = check(R,C);
			answer = min(answer, a);
		}
	}
	printf("Case #%d: %d\n",test, answer);
}


int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i = 1; i <= T; i++) solve(i);
	return 0;
}