#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

typedef long long LL;
const int MAX = 1000000010;

int res[19][19][19];
int R, C, N;

int mp[16][16];
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};

int best;
void solve()
{
	int cnt = 0;
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(mp[i][j])
			{
				for(int k = 0; k < 4; k++)
				{
					int x = i + dir[k][0];
               	 	int y = j + dir[k][1];
					if(x < 0 || y < 0 || x >= R || y >= C)
						continue;
					if(mp[x][y])
						cnt++;
				}
			}
		}
	}
	best = min(best, cnt/2);
}

void dfs(int iden, int cnt)
{
    if(iden == R * C)
    {
        if(cnt == N)
			solve();
        return;
    }
    if(R * C - iden < N - cnt || cnt > N)
        return;
    int x = iden / C;
    int y = iden % C;
    mp[x][y] = 1;
    dfs(iden + 1, cnt + 1);
    mp[x][y] = 0;
    dfs(iden + 1, cnt);
}

int main()
{
    memset(res, 0, sizeof(res));
    for(R = 1; R <= 16; R++)
    {
        for(C = 1; R * C <= 16; C++)
        {
            for(N = (R * C + 1) / 2 + 1; N <= R * C; N++)
            {
                best = MAX;
                dfs(0,0);
                res[R][C][N] = best;
            }
        }
    }
    freopen("B-small-attempt0.in","r",stdin);
    freopen("bsout.out","w",stdout);
    int T;
    while(cin >> T)
    {
    	for(int j = 1; j <= T; )
    	{
        	cin >> R >> C >> N;
       	 	cout << "Case #" << j++ << ": " << res[R][C][N] << endl;
    	}
    }
    return 0;
}