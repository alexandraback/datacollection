#include<stdio.h>
#include<algorithm>
using namespace std;
const int Maxn=1020;
int a[Maxn],rep[Maxn];
typedef long long Int;
/*
3
5 5
1 1 1 1 1
5 448257424
*/
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int _,cs=1;scanf("%d",&_);
	while(_--)
	{
		int n,b;
		scanf("%d%d",&b,&n);
		for(int i=1;i<=b;i++)scanf("%d",a+i);
		Int L=-1,R=1LL<<60;
		while(L+1<R)
		{
			Int mid=(L+R)>>1;
			Int tp=0;
			for(int i=1;i<=b;i++)tp+=mid/a[i]+1;
			if(tp>=n)R=mid;
			else L=mid;
		}
		//printf("%lld\n",R);
		int ans;
		for(int i=1;i<=b;i++)
			if(R%a[i]==0)
			{
				rep[i]=1;
				n-=R/a[i];
			}
			else
			{
				rep[i]=0;
				n-=R/a[i]+1;
			}
		for(int i=1;i<=b;i++)
		{
			n-=rep[i];
			if(!n){ans=i;break;}
		}
		printf("Case #%d: %d\n",cs++,ans);
	}
}
