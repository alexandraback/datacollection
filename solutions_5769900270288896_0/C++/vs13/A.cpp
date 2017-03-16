// Copyright @Vipul Verma
// Created on 2/05/2014
#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;
int dp[1000000];
int main() 
{
	int t;
	cin>>t;
	int k=1;
	while(t--)
	{
		int R,C,n;
		cin>>R>>C>>n;
		int ans =INT_MAX;
		int tot=1<<(R*C);
		for (int i = 1; i<tot;i++)
		{
			dp[i]=dp[i-(i&-i)]+1;
			if (dp[i] == n)
			{
				int tmp = 0;
				for (int r = 0; r < R; r++)
				{
					for (int c = 0; c < C; c++)
					{
						if (c > 0 && (i & (1 << (r * C + c))) && (i & (1 << (r * C + c - 1))))
							tmp++;
						if (r > 0 and (i & (1 << (r * C + c))) && (i & (1 << (r * C + c - C))))
							tmp++;
					}
				}
				ans=min(ans,tmp);
			}
		}
		if(n==0)
			ans=0;
		cout<<"Case #"<<k<<": "<<ans<<"\n";
		k++;
	}
}