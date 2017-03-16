#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 3005;
const int MOD = 100007;
int x[N],y[N];
int main()
{
	freopen("C-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T,ca=1;
	scanf("%d",&T);
	while(T--)
	{
		printf("Case #%d:\n",ca++);
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		for(int i=0;i<n;i++)
		{
			int ret=N;
			if(n==1)ret=0;
			for(int j=0;j<n;j++)if(j!=i)
			{
				int t1=0,t2=0;
				ll x1=x[i]-x[j],y1=y[i]-y[j];
				for(int k=0;k<n;k++)if(k!=j&&k!=i)
				{
					ll x2=x[k]-x[i],y2=y[k]-y[i];
					if(x1*y2-x2*y1>0)t1++;
					else if(x1*y2-x2*y1<0)t2++;
				}
				if(t1>t2)t1=t2;
				if(ret>t1)ret=t1;
			}
			printf("%d\n",ret);
		}
	}
   return 0;
}
