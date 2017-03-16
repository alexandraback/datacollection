#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
ifstream in("B.in");
ofstream out("B.out");

int ans, n, r, c, m;
int dp[17][17][4][(1<<4)-1];

int sum(int n)
{
	int ans =0;
	while (n>0)
	{
		ans += n & 1;
		n>>=1;
	}
	return ans;
}


int main()
{
	int T, n, headNum;
	in>>T;
	for (int i=1; i<=T; i++)
	{
		in>>r>>c>>n;
		if (r<c) swap(r,c);
		m = (1<<c)-1;
		for (int ii=0; ii<=n; ii++)
		for (int j=0; j<=r; j++)
			for (int k=0; k<=c; k++)
				for (int bit=0; bit <=m; bit++)
					dp[ii][j][k][bit] = 10000000;
		dp[0][0][c-1][0]=0;
		for (int ii=0; ii<=n; ii++)
		for (int j=0; j<=r; j++)
			for (int k=0; k<=c; k++)
				for (int bit=0; bit <=m; bit++)
					if (dp[ii][j][k][bit]<10000000)
					{
						int cnt = 0 ; 
						int x = k+1, y=j;
						if (x==c) {x= 0;y=j+1;}
						else
							cnt += ((bit  & (1<<k))>0);
						int tmp = bit - (bit & (1<<x));
						dp[ii][y][x][tmp] = min(dp[ii][y][x][tmp], dp[ii][j][k][bit]);
						if (ii<n)
						{
							tmp = bit  | (1<<x);
							cnt += ((bit  & (1<<x))>0);
							dp[ii+1][y][x][tmp] = min(dp[ii+1][y][x][tmp], dp[ii][j][k][bit]+cnt);
						}
					}
		ans =  10000000;
			for (int bit=0; bit <=m; bit++)
				ans = min(ans, dp[n][r][c-1][bit]);
		out<<"Case #"<<i <<": "<<ans<<endl;
	}
}