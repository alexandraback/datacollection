#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#define LL long long 
using namespace std;
int n,m,cnt,B;
int a[1010];
LL calc(LL t)
{
	LL sum=0;
	for (int i=1;i<=B;i++)
	{
		sum+=t/a[i]+1;
	}
	return sum;
}
void work(int lab)
{
	printf("Case #%d: ",lab);
	scanf("%d%d",&B,&n);
	LL Maxa=0;
	for (int i=1;i<=B;i++) scanf("%d",&a[i]),Maxa=max(Maxa,(LL)a[i]);
	LL l=0,r=n*Maxa;
	while (l<r)
	{
		LL mid=(l+r)/2;
		if (calc(mid)>=n) r=mid;
		else l=mid+1;
	}
	LL tot=0;
	for (int i=1;i<=B;i++) tot+=l/a[i]+(l%a[i]!=0);
	for (int i=1;i<=B;i++)
	{
		if (l%a[i]==0) tot++;
		if (tot==n) 
		{
			printf("%d\n",i);
			break;
		}
	}
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t;
	scanf("%d\n",&t);
	for (int i=1;i<=t;i++)work(i);
	return 0;
}
