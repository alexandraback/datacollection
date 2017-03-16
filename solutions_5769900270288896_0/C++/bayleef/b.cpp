#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int T,ts,i,j,k,l,m,n,o,p,dj[]={1,0,-1,0},dk[]={0,1,0,-1},cur,ans,a[16][16],jj,kk;

int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&p);
		ans=1000;
		for(i=0;i<1<<n*m;i++)
		{
			o=0;
			for(j=0;j<n*m;j++)
			{
				a[j/m][j%m]=i>>j&1;
				o+=a[j/m][j%m];
			}
			if(o!=p)continue;
			cur=0;
			for(j=0;j<n;j++)
				for(k=0;k<m;k++)
					if(a[j][k])
						for(l=0;l<4;l++)
						{
							jj=j+dj[l];
							kk=k+dk[l];
							if(jj>=0 && kk>=0 && jj<n && kk<m && a[jj][kk])
								cur++;
						}
			ans=min(ans,cur);
		}
		printf("Case #%d: %d\n",++ts,ans/2);
	}
	return 0;
}