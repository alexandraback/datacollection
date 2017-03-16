#include<cstdio>

int a[1111];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int tc,tcn;
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++)
	{
		int r1=0,r2=0;
		int i,n,m=0;
		scanf("%d",&n);
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		for(i=1;i<n;i++)if(a[i-1]-a[i]>m)m=a[i-1]-a[i];
		for(i=1;i<n;i++)if(a[i-1]>a[i])r1+=a[i-1]-a[i];
        for(i=1;i<n;i++)
		{
			if(a[i-1]<m)r2+=a[i-1];
			else r2+=m;
		}
		printf("Case #%d: %d %d\n",tc,r1,r2);
	}
}
