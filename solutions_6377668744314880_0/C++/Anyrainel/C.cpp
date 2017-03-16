#include <cstdio>
long long x[3001],y[3001];
int n;
long long cross(int a,int b,int p)
{
	return (x[p]-x[a])*(y[p]-y[b])-(x[p]-x[b])*(y[p]-y[a]);
}
inline int min(int a,int b)
{
	return a<b?a:b;
}
int main()
{
	int T,cntu,cntd,ans;
	long long res;
	freopen("C-small-attempt1.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&T);
	for(int j=1;j<=T;j++)
	{
		printf("Case #%d:\n",j);
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%lld%lld",x+i,y+i);
		for(int i=0;i<n;i++)
		{
			ans=100000;
			for(int k=0;k<n;k++) if(k!=i)
			{
				cntu=cntd=0;
				for(int c=0;c<n;c++) if(c!=k&&c!=i)
				{
					res=cross(i,k,c);
					if(res>0) cntu++;
					else if(res<0) cntd++;
				}
				ans=min(ans,min(cntu,cntd));
			}
			if(ans!=100000)
			printf("%d\n",ans);
			else
			printf("0\n");
		}
	}
	return 0;
}
