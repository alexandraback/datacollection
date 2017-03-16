#include<cstdio>
#include<cstring>
#include<algorithm>
#define fou(i,j,k) for (int i=j;i<=k;i++)
#define fod(i,j,k) for (int i=j;i>=k;i--)
using namespace std;

typedef long long LL;

const int maxn=1010;

int a[maxn],n;

void init()
{
	scanf("%d",&n);
	fou(i,1,n) scanf("%d",&a[i]);
}

void solve()
{
	int ans1,ans2,d;
	ans1=0;
	d=0;
	fou(i,2,n){
		if (a[i-1]>a[i]){
			ans1+=a[i-1]-a[i];
			if (d<a[i-1]-a[i]) d=a[i-1]-a[i];
		}
	}
	ans2=0;
	fou(i,1,n-1){
		if (a[i]<d) ans2+=a[i]; else ans2+=d;
	}
	printf("%d %d\n",ans1,ans2);
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
