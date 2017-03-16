#include <stdio.h>
#include <stdlib.h>
using namespace std;

int T,Case,n,i,j,k,sum1,sum2,ans;
int x[10005],y[10005];
long long tmp;

long long cal(int a1,int b1,int a2,int b2){return (long long)a1*b2-(long long)a2*b1;}
long long calc(int a,int b,int c){return cal(x[b]-x[a],y[b]-y[a],x[c]-x[a],y[c]-y[a]);}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
		++Case;
		printf("Case #%d:\n",Case);
		for(i=1;i<=n;++i)
		{
			ans=n-1;
			for(j=1;j<=n;++j)
			if(i!=j)
			{
				sum1=sum2=0;
				for(k=1;k<=n;++k)
				if(k!=i&&k!=j)
				{
					tmp=calc(i,j,k);
					if(tmp<0)++sum1;
					if(tmp>0)++sum2;
				}
				if(sum1<ans)ans=sum1;
				if(sum2<ans)ans=sum2;
			}
			printf("%d\n",ans);
		}
	}
}
