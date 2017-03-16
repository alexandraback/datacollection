#include<cstdio>
#include<cmath>
#include<algorithm>
#define ll long long

int n,x[3100],y[3100],s[6100],t,Ans;

double a[3100],_a[6100];

bool cmp(int x,int y){return a[x]<a[y];}

bool XJ(int x1,int y1,int x2,int y2){return (1ll*x1*y2-1ll*x2*y1)==0;}

int main()
{
	int i,j,k,Case,TestCase;
	//freopen("c.in","rb",stdin);
	//freopen("c.out","wb",stdout);
	scanf("%d",&TestCase);
	for(Case=1;Case<=TestCase;Case++)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%d%d",x+i,y+i);
		printf("Case #%d:\n",Case);
		for(i=0;i<n;i++)
		{
			t=0;
			for(j=0;j<n;j++)
				if(i!=j)
				{
					a[j]=atan2(y[j]-y[i],x[j]-x[i]);
					s[t++]=j;
				}
			std::sort(s,s+t,cmp);
			for(j=0;j<t;j++)
			{
				s[j+t]=s[j];
				_a[j+t]=(_a[j]=a[s[j]])+2*M_PI;
			}
			Ans=n-1;
			for(j=k=0;j<t;j++)
			{
				for(;k<2*t;k++)
				{
					if(fabs(_a[k]-_a[j]-M_PI)<1e-4&&XJ(x[s[j]]-x[i],y[s[j]]-y[i],x[s[k]]-x[i],y[s[k]]-y[i]))break;
					if(_a[k]-_a[j]-M_PI>(1e-6))break;
				}
				if(k-j-1<Ans)
					Ans=k-j-1;
			}
			printf("%d\n",Ans);
		}
	}
	return 0;
}
