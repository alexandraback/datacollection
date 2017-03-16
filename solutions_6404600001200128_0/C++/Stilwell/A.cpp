#include <stdio.h>
#include <stdlib.h>
using namespace std;

int T,Case,n,i,j,k,ans1,ans2,Min;
int a[10005];

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d",&n);
		for(i=1;i<=n;++i)scanf("%d",&a[i]);
		ans1=ans2=0;Min=0;
		for(i=2;i<=n;++i)
		if(a[i]<a[i-1])
		{
			k=a[i-1]-a[i];
			ans1+=k;
			if(k>Min)Min=k;
		}
		for(i=1;i<n;++i)if(a[i]>=Min)ans2+=Min;else ans2+=a[i];
		++Case;
		printf("Case #%d: %d %d\n",Case,ans1,ans2);
	}
}
