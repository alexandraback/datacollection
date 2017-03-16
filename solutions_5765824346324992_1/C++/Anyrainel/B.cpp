#include <cstdio>
int m[1001],b,n,ans;
int gcd(int a, int b)
{
	int t;
	while(b>0)
	{
		t=b;b=a%b;a=t;
	}
	return a;
}
int main()
{
	int T;
	int g;
	double one=1.0,eva;
	long long tim,cnt,tot;
	bool find;
	freopen("B-large.in","r",stdin);
	freopen("B.out","w",stdout);
	scanf("%d",&T);
	for(int j=1;j<=T;j++)
	{
		scanf("%d%d",&b,&n);
		scanf("%d",&m[0]);
		g=m[0];
		for(int i=1;i<b;i++)
		{
			scanf("%d",m+i);
			g=gcd(g,m[i]);
		}
		if(g>1) for(int i=0;i<b;i++)
		m[i]/=g;
		eva=0.0;find=false;
		for(int i=0;i<b;i++)
			eva+=one/m[i];
		tim=(long long)(n/eva)-1;
		while(!find)
		{
			cnt=0;tot=0;
			for(int i=0;i<b;i++)
			{
				tot+=tim/m[i]+1;
				cnt+=(tim-1)/m[i]+1;
			}
			//printf("%lld %lld %lld\n",tim,tot,cnt);
			if(cnt<n&&tot>=n)
			{
				//printf("**********\n");
				find=true;
				for(int i=0;i<b;i++)
				{
					if(tim%m[i]==0)
						cnt++;
					if(cnt==n)
					{
						ans=i+1;
						break;
					}
				}
			}
			else if(cnt>=n) tim--;
			else if(tot<n) tim++;
		}
		printf("Case #%d: %d\n",j,ans);
	}
	return 0;
}
