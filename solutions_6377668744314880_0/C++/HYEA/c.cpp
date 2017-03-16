#include<cstdio>
#include<algorithm>
using namespace std;
long long x[3030];
long long y[3030];
inline long long area2(int a,int b,int c)
{
	return (x[b]-x[a])*(y[c]-y[a]) - (y[b]-y[a])*(x[c]-x[a]);
}
int ccw(int a,int b,int c)
{
	long long res=area2(a,b,c);
	if(res<0) return -1;
	if(res==0) return 0;
	return 1;
}
void tmain()
{
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++)
	{
		scanf("%lld%lld",x+i,y+i);
	}
	if(N<=3)
	{
		printf("\n");
		for(int i=0;i<N;i++) printf("0\n");
		return;
	}
	printf("\n");
	for(int i=0;i<N;i++)
	{
		int ans=N;
		for(int j=0;j<N;j++)
		{
			if(i==j) continue;
			int m=0,p=0;
			for(int k=0;k<N;k++)
			{
				int r=ccw(i,j,k);
				if(r<0) m++;
				if(r>0) p++;
			}
			ans=min(ans,min(m,p));
		}
		printf("%d\n",ans);
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		tmain();
	}
	return 0;
}