#include<cstdio>
#include<cstring>
#include<algorithm>
#define fou(i,j,k) for (int i=j;i<=k;i++)
#define fod(i,j,k) for (int i=j;i>=k;i--)
using namespace std;

typedef long long LL;

int n,m,K;

void init()
{
	scanf("%d%d%d",&n,&m,&K);
}

void make(int x,int y)
{
	int a1,a3;
	if (x>y) swap(x,y);
	if (y%2==0) a1=y/2; else a1=y/2+1;
	if (K<=a1){
		printf("0\n");
		return;
	}
	K-=a1;
	if (y%2==0) a3=1; else a3=0;
	if (K<=a3){
		printf("%d\n",K);
		return;
	}
	K-=a3;
	printf("%d\n",a3+K*2);
}

void solve()
{
	int a1,a2,a3,bef;
	if (n==1 || m==1){
		make(n,m);
		return;
	}
	if (n%2==0 && m%2==0) a1=n*m/2;
	if (n%2==0 && m%2==1) a1=n/2*m;
	if (n%2==1 && m%2==0) a1=n*m/2;
	if (n%2==1 && m%2==1) a1=n/2*m+m/2+1;
	bef=0;
	if (K<=a1){
		printf("0\n");
		return;
	}
	K-=a1;
	if (n%2==1 && m%2==1) a3=0; else a3=2;
	if (K<=a3){
		printf("%d\n",K*2);
		return;
	}
	K-=a3;
	bef+=a3*2;
	a2=n+m-2-a3;
	if (K<=a2){
		printf("%d\n",bef+K*3);
		return;
	}
	K-=a2;
	bef+=a2*3;
	printf("%d\n",bef+K*4);
}

int main()
{
	int T;
	scanf("%d",&T);
	fou(i,1,T){
		printf("Case #%d: ",i);
		init();
		solve();
	}
	return 0;
}
