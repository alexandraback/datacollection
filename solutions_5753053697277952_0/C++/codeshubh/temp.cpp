#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,i,j,k,n,p,u,T,m;
	int a[1000000];
	char c[1000000],e;
	scanf("%d",&t);
	for(T=1;T<=t;++T)
	{
		m=0;
		scanf("%d",&n);
		for(i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
			m+=a[i];
		}
		printf("Case #%d: ",T);
		while(m)
		{
			p=0;
			int max=a[0];
			for(i=1;i<n;++i)
			{
				if(a[i]>max)
				{
					max=a[i];
					p=i;
				}
			}
			int p1;
			int m2=-1;
			for(i=0;i<n;++i)
			{
				if(i==p)
					continue;
				if(a[i]>m2)
				{
					m2=a[i];
					p1=i;
				}
			}
			k=m2+max;
			if(k!=m)
			{
				printf("%c",p+'A');
				a[p]--;
				m--;
			}
			else
			{
				printf("%c%c",p+'A',p1+'A');
				a[p]--;
				a[p1]--;
				m-=2;
			}
			if(m!=0)
				printf(" ");
			else
				printf("\n");
		}
	}
	return 0;
}
