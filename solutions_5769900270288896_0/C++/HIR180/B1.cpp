#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int main()
{
	int t; cin >> t;
	for(int ss=1;ss<=t;ss++)
	{
		printf("Case #%d: ",ss);
		int r,c,n; cin >> r >> c >> n;
		if(r>c) swap(r,c);
		int dp[20][20][20]; //pos,mask,number
		for(int i=0;i<20;i++) for(int j=0;j<20;j++) for(int k=0;k<20;k++) dp[i][j][k] = INF;
		dp[0][0][0] = 0;
		for(int i=0;i<c;i++)
		{
			for(int j=0;j<(1<<r);j++)
			{
				for(int k=0;k<=n;k++)
				{
					if(dp[i][j][k] == INF) continue;
					for(int nx=0;nx<(1<<r);nx++)
					{
						int mv = k+__builtin_popcount(nx),ad=0;
						for(int a=0;a<r-1;a++)
						{
							if( ((nx>>a)&1) + ((nx>>(a+1))&1) == 2)
							{
								ad++;
							}
						}
						for(int a=0;a<r;a++)
						{
							if( ((nx>>a)&1) + ((j>>a)&1) == 2)
							{
								ad++;
							}
						}
						if(mv>n) continue;
						dp[i+1][nx][mv] = min(dp[i+1][nx][mv],dp[i][j][k]+ad);
					}
				}
			}
		}
		int res = INF;
		for(int j=0;j<(1<<r);j++) res = min(res,dp[c][j][n]);
		cout << res << endl;
	}
}