#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int T,Case,n,i,j,k,l,ans,sum,sum1,sum2;
int x[3005],y[3005];

struct node
{
	int x,y,z,val;
}t[10005];
inline bool cmp(const node &a,const node &b)
{
    if(a.z!=b.z)return a.z>b.z;
    return (long long)a.x*b.y<(long long)a.y*b.x;
}
long long calc(int x,int y){return (long long)t[x].x*t[y].y-(long long)t[x].y*t[y].x;}

int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T)
	{
		++Case;printf("Case #%d:\n",Case);
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
		if(n==1)
		{
			printf("0\n");
			continue;
		}
		for(i=1;i<=n;++i)
		{
			k=0;
			for(j=1;j<=n;++j)
			if(i!=j)
			{
				++k;
				t[k].x=x[j]-x[i];
				t[k].y=y[j]-y[i];
				if(t[k].x>=0)
				{
					if(t[k].y>=0)t[k].z=1;
					else t[k].z=4;
				}
				else
				{
					if(t[k].y>=0)t[k].z=2;
					else t[k].z=3;
				}
			}
			sort(t+1,t+k+1,cmp);
			l=1;t[l].val=1;
			for(j=2;j<=k;++j)
			if(calc(j-1,j)!=0)
			{
				++l;
				if(j!=l)t[l]=t[j];
				t[l].val=1;
			}else ++t[l].val;
			for(j=1;j<=l;++j)t[l+j]=t[j];
			k=sum=0;
			ans=n-1;
			for(j=1;j<=l;++j)
			{
				sum-=t[j].val;
				if(k<j)k=j,sum=0;
				for(;calc(j,k+1)<0;)
				{
					++k;
					sum+=t[k].val;
				}
				sum1=sum;
				sum2=n-1-t[j].val-sum1;
				if(calc(j,k+1)==0&&k+1!=j+l)sum2-=t[k+1].val;
				if(sum1<ans)ans=sum1;
				if(sum2<ans)ans=sum2;
			}
			printf("%d\n",ans);
		}
	}
}
