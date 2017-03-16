#include <stdio.h>
int tcase,n,m,a[1100],b[1100];
int gcd(int x,int y)
{
	if(y==0)
		return x;
	return gcd(y,x%y);
}
int lcm(int x,int y)
{
	return x*y/gcd(x,y);
}
int main()
{
	int loop,i,j,l,temp,min;
	freopen("B-small-attempt0.in","r",stdin);
	freopen("B-small-attempt0.out","w",stdout);
	scanf("%d",&tcase);
	for(loop=1;loop<=tcase;loop++)
	{
		scanf("%d %d",&n,&m);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			b[i]=0;
		}
		l=a[1];
		for(i=1;i<=n;i++)
			l=lcm(l,a[i]);
		temp=0;
		for(i=1;i<=n;i++)
		{
			temp+=l/a[i];
		}
		m%=temp;
		if(m==0)
			m+=temp;
		for(i=1;i<=m;i++)
		{
			for(j=1;j<=n;j++)
			{
				if(b[j]==0)
				{
					b[j]=a[j];
					break;
				}
			}
			if(j==n+1)
			{
				min=2147483647;
				for(j=1;j<=n;j++)
				{
					if(b[j]<min)
						min=b[j];
				}
				for(j=1;j<=n;j++)
				{
					b[j]-=min;
				}
				i--;
				continue;
			}
			if(i==m)
			{
				printf("Case #%d: %d\n",loop,j);
			}
		}
	}
	return 0;
}