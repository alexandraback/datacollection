#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<queue>
#include<time.h>

#define INF 1000000000
#define endl '\n'
#define ll long long

using namespace std;


int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	
	
	srand(time(0));
	
	int t;
	int n,m,k;
	cin >> t;
	for(int time = 1 ; time <= t ; time++)
	{
		cin >> n >> m >> k;
		
		int ans = INF;
		int size = n*m;
		int board[n][m];
		
		int x;
		int y;
		
		for(int i = 0 ; i < n ; i++)
			for(int j = 0 ; j < m ; j++)
				board[i][j] = 0;
		for(int j = 0 ; j < k ; )
		{
			x=rand()%n;
			y=rand()%m;
			if(board[x][y] == 0)
			{
				board[x][y] = 1;
				j++;
			}
		}
		
		int limit = 100000;
		for(int r = 0 ; r < limit ; r++)
		{
			
			int sum = 0;
			for(int i = 0 ; i < 50 ; i++)
				swap(board[rand()%n][rand()%m], board[rand()%n][rand()%m]);
			
			for(int i = 0 ; i < n ; i++)
				for(int j = 1 ; j < m ; j++)
				{
					if(board[i][j]==1 && board[i][j-1]==1)
						sum++;
				}
			for(int i = 1 ; i < n ; i++)
				for(int j = 0 ; j < m ; j++)
				{
					if(board[i][j]==1 && board[i-1][j]==1)
						sum++;
				}
				
			if(sum < ans)
				ans = sum;
		}
		
		cout << "Case #" << time << ": " << ans << "\n";
	}
	
	
	
	return 0;
}

