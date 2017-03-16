#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<bitset>
#include<map>
#include<set>

using namespace std;

int build[20][20];
int n, m, k;

int Check()
{
	int res = 0;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m-1; j++)
			if(build[i][j] == 1 && build[i][j+1] == 1)
				res++;
	}
	for(int j = 0; j < m; j++)
	{
		for(int i = 0; i < n-1; i++)
		{

				if(build[i][j] == 1 && build[i+1][j] == 1)
					res++;
		}
	}

	return res;

}





int  solve()
{
	int res = 10000;
	for(long long i = 0; i < (1 << (m * n)); i++)
	{
		int kk = 0;
		for(long long j = 0; j < (m * n); j++)
		{
			if(i & (1 << j))
				kk++;
		}
		if(kk == k)
		{
			for(int j = 0; j < (m * n); j++)
			{
				if(i & (1 << j))
				{
					build[j/m][j%m] = 1;
				}
				else
				{
					build[j/m][j%m] = 0;
				}
			}
			res = min(res, Check());
		}
	}
	return res;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	int t;
	cin >> t;
	for(int tt = 0; tt < t; tt++)
	{
	//	int n, m, k;
		cin >> n >> m >> k;
		int res = solve();
		printf("Case #%d: %d\n", tt+1, res);
	}


	return 0;

}