#include<cstdio>
using namespace std;
long long L,R,mid,tot;
int T,n,b,i,a[1010];
int main()
{
	scanf("%d",&T);
	for(int tec=1;tec<=T;tec++)
	{
		scanf("%d%d",&b,&n);
		for(i=1;i<=b;i++)scanf("%d",&a[i]);
		L=0;R=1e18;
		while(L<R)
		{
			mid=(L+R)>>1;tot=0;
			for(i=1;i<=b;i++)tot+=mid/a[i]+1;
			if(tot>=n)R=mid;else L=mid+1;
		}for(i=1;i<=b;i++)n-=(L+a[i]-1)/a[i];
		for(i=1;i<=b&&n;i++)if(L%a[i]==0)n--;
		printf("Case #%d: %d\n",tec,i-1);
	}
}
