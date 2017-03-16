#include<iostream>
#include<cstdio>
using namespace std;
int n,x[3100],y[3100];
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int TT=1;TT<=T;++TT)
	{
		scanf("%d",&n);
		for (int i=0;i<n;++i)
			scanf("%d%d",&x[i],&y[i]);
		printf("Case #%d:\n",TT);
		for (int i=0;i<n;++i)
		{
			int ans=n-1;
			for (int j=0;j<n;++j)
			  if (i!=j)
			  if (x[i]==x[j])
			  {
			  	int l=0,r=0;
			  	for (int k=0;k<n;++k)
			  	  if (x[k]<x[i]) ++l;
			  	  else if (x[k]>x[i]) ++r;
			  	if (l<ans) ans=l;
			  	if (r<ans) ans=r;
			  }
			  else
			  if (y[i]==y[j])
			  {
			  	int l=0,r=0;
			  	for (int k=0;k<n;++k)
			  	  if (y[k]<y[i]) ++l;
			  	  else if (y[k]>y[i]) ++r;
			  	if (l<ans) ans=l;
			  	if (r<ans) ans=r;
			  }
			  else
			{
				int po=0,ne=0;
				double m=double(y[i]-y[j])/double(x[i]-x[j]);
				for (int k=0;k<n;++k)
				{
					double l=(y[k]-y[i]-m*x[k]+m*x[i])/(m+1.0/m);
					if (l>0) ++po;
					else if (l<0) ++ne;
				}
				if (po<ans) ans=po;
				if (ne<ans) ans=ne;
			}
			printf("%d\n",ans);
		}
	}
}
