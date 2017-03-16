#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
#include<vector>

#define f first
#define s second
#define pb push_back

using namespace std;

typedef pair<int,int> pr;
typedef long long ll;
int r,c,n;
int mark[16][16];
vector<pr> V,Sol;
int func(vector<pr> Sol)
{
	int i,j,ans;

	ans = 0;
	int sz = Sol.size();
	for(i = 0;i  < sz;i++)
	{
		mark[Sol[i].f][Sol[i].s] = 1;
	}
	

	for(i = 1;i <= r;i++)
	{
		for(j  = 1;j <= c;j++)
		{
			if(((i-1) >= 1) && (mark[i-1][j] == 1) && (mark[i][j] == 1))
			{
				ans += 1;
			}
			if(((j-1) >= 1) && (mark[i][j-1] == 1) && (mark[i][j] == 1))
			{
				ans += 1;
			}
	
		}
			
	} 
	memset(mark,0,sizeof(mark));

	return ans;
}


int main()
{
	int t,a,y,ans,res,i,j,x,cnt,ind;

	scanf("%d",&t);
	ind = 1;
	while(t--)
	{
		ans = 1000000000;

		scanf("%d %d %d",&r,&c,&n);

		a = r*c;
		if(n == 0)
		{
			printf("Case #%d: %d\n",ind,0);
			ind++;
			continue;	
		}
		for(i  = 1;i <= r;i++)
		{
			for(j  = 1;j <= c;j++)
			{
				V.pb(pr(i,j));
			}

		}
		y = 1;
		for(i = 1;i <= a;i++)
		{
			y = y*2;
		}
		for(i = 1;i < y;i++)
		{

			x = 1;
			cnt = 0;
			for(j = 1;j <=  a;j++)
			{
				if(i&x)
				{
					cnt++;					
					Sol.pb(V[j-1]);
					
				}
				x = x*2;
			}
			if(cnt == n)
			{
				res = func(Sol);
				ans = min(ans,res);
				Sol.clear();
			}
			else
				Sol.clear();		
		}
		printf("Case #%d: %d\n",ind,ans);
		V.clear();
		ind++;
	}
	return 0;
}
		
