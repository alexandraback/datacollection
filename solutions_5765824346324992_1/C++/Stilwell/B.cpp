#include <stdio.h>
#include <stdlib.h>
using namespace std;

int T,Case,n,m,i,j,k;
long long l,r,mid,sum,aim;
int a[100005];
bool b[100005];

int main()
{
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;++i)scanf("%d",&a[i]);
		l=0;r=10000000000000000ll;aim=r;
		while(l<=r)
		{
			mid=(l+r)/2;
			sum=0;
			for(i=1;i<=n;++i)sum+=mid/a[i]+1;
			if(sum>=m)aim=mid,r=mid-1;
			else l=mid+1;
		}
		sum=0;
		for(i=1;i<=n;++i)b[i]=false;
		for(i=1;i<=n;++i)
		{
			sum+=aim/a[i]+1-(aim%a[i]==0);
			if(aim%a[i]==0)b[i]=true;
		}
		for(i=1;i<=n;++i)
		if(b[i])
		{
			++sum;
			if(sum==m)break;
		}
		++Case;
		printf("Case #%d: %d\n",Case,i);
	}
}
