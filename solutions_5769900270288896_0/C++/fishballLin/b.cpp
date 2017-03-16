#include <bits/stdc++.h>
using namespace std;
int m, n, p, ans, b[32][32];
int d[4][2] = {1,0,-1,0,0,1,0,-1};
void check()
{
	int sum = 0;
	for(int i = 0; i < m; i++)
		for(int j = 0; j < n; j++)
			for(int k = 0; b[i][j] && k < 4; k++)
			{
				int nx = i + d[k][0], ny = j + d[k][1];
				//cout << i << ' ' << j << ' ' << nx << ' ' << ny << endl;
				if(nx >= 0 && nx < m && ny >= 0 && ny < n)
				{
					if(b[nx][ny])
						sum++;
				}
			}
	ans = min(ans, sum / 2);
}
void DFS(int x, int sum)
{
	if(sum == p)
	{
		check();
		return;
	}
	if(x >= m * n)
		return;
	//cout << x << " " << sum << endl;
	b[x/n][x%n] = 1;
	DFS(x + 1, sum + 1);
	b[x/n][x%n] = 0;
	DFS(x + 1, sum);
}

int main()
{
	int t, cnt = 1;
	cin >> t;
	while(t--)
	{
		cin >> m >> n >> p;
		ans = 1024;
		if(p <= (m * n + 1) / 2 )
			ans = 0;
		else
		{
			for(int i = 0; i < 32; i++)
				fill(b[i], b[i] + 32, 0);
			DFS(0, 0);
		}
		cout << "Case #" << cnt++ << ": "<< ans << endl;
	}

}