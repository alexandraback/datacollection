#include<cstdio>
#include<algorithm>
#include<cmath>
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
	double arr[6060];
	double PIEPS=3.141592653589793238+0.000000001;
	double PI=3.141592653589793238;
	for(int i=0;i<N;i++)
	{
		int ans=0;
		for(int j=0;j<N;j++)
		{
			if(i==j) arr[j]=0;
			else arr[j]=atan2(y[j]-y[i],x[j]-x[i])+2*PI;
		}
		sort(arr,arr+N);
		for(int j=0;j<N;j++)
			arr[N+j]=arr[j]+2*PI;
		arr[2*N]=4*PI;
		//for(int j=0;j<=2*N;j++) printf("%lf ",arr[j]);
		int mv=0;
		for(int j=0;j<=N;j++)
		{
			while(arr[mv]-arr[j]<=PIEPS) mv++;
			ans=max(ans,mv-j);
		}
		printf("%d\n",N-ans);
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