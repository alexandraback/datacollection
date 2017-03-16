#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
using namespace std;


int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tt;
	scanf("%d", &tt);
	for(int ii = 1; ii <= tt; ii++)
	{
		int n, l, c;	
		scanf("%d\n", &n);
		char str[150][150]={{0}};
		char a[150][150]={{0}};
		int ms[150][150]={{0}};
		
		bool fl = 1;
		for(int i = 1; i <= n; i++)
		{
			gets(str[i]);
			a[i][0] = str[i][0];
			ms[i][0] = 1;
			c = 0;
			l = strlen(str[i]);
			if(fl)
			{
				for(int j = 1; j < l; j++)
					if(str[i][j] != a[i][c])
					{
						c++;
						a[i][c] = str[i][j];
						ms[i][c] = 1;
					}
					else ms[i][c] ++;
				for(int j = 1; j < i; j++)
					if(strcmp(a[i], a[j])!=0)
					{
						if(fl)
							printf("Case #%d: Fegla Won\n", ii);
						fl = 0;
					}
				//if(!fl)
				//	break;
			}
		}
		if(!fl)
				continue;
		else
		{
			int ans = 0, mn, mx, cmn, cmx;
			l = strlen(a[1]);
			for(int i = 0; i < l; i++)
			{
				mx = 0;
				mn = 150;
				for(int j = 1; j <= n; j++)
				{
					if(ms[j][i] < mn)
						mn = ms[j][i];
					if(ms[j][i] > mx)
						mx = ms[j][i];
				}
				//if(mn == mx)
				//	continue;
				cmn = 1000010;
				for(int j = mn; j <= mx; j++)
				{
					cmx = 0;
					for(int k = 1; k <= n; k++)
						cmx += max(j, ms[k][i]) - min(j, ms[k][i]);
					if(cmx < cmn)
						cmn  = cmx;
					if(cmn == 0)
						break;
				}
				ans += cmn;
			}
			printf("Case #%d: %d\n", ii, ans);
		}
	}
	return 0;
}