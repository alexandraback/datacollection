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
		long long l,r,mid,sum;
        int i,n,m;
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)scanf("%d",&a[i]);
		l=0;r=1e16;
		while(l<r)
		{
			mid=(l+r)/2;
			sum=0;
            for(i=0;i<n;i++)sum+=mid/a[i]+1;
            if(sum<m)l=mid+1;
            else r=mid;
		}
		for(i=0;i<n;i++)m-=(l+a[i]-1)/a[i];
		for(i=0;i<n&&m;i++)if(l%a[i]==0)m--;
		printf("Case #%d: %d\n",tc,i);
	}
}
