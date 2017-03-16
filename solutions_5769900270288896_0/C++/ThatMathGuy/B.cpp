#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <queue>
#include <string.h>

using namespace std;

typedef long long ll;

ifstream fin("input.txt");
ofstream fout("output.txt");

int tc;
int r,c,n;
int rez=100000;

int dp[20][20];

void rec(int x, int y, int l,int score)
{
	if (x>=c) y++,x=0;
	if (y>=r && l==n)  {rez = min(rez,score); return;}
	else if (y>=r) return;

	rec(x+1,y,l,score);
	int t=0;
	if (x && dp[x-1][y]) t++;
	if (x<c-1 && dp[x+1][y]) t++;
	if (y && dp[x][y-1]) t++;
	if (y<r-1 && dp[x][y+1]) t++;

	dp[x][y] = 1;
	rec(x+1,y,l+1,score+t);
	dp[x][y]=0;
}

int main()
{
	fin>>tc;

	for (int tt=1; tt<=tc; tt++)
	{
		for (int i=0; i<20; i++)
			for (int j=0; j<20; j++)
				dp[i][j]=0;
		fin>>r>>c>>n;
		rez=100000;

		rec(0,0,0,0);

		fout<<"Case #"<<tt<<": ";
		fout<<rez;
		fout<<'\n';
	}

	return 0;
}