#include<cstdio>
#include<cstring>
#include<algorithm>
#define fou(i,j,k) for (int i=j;i<=k;i++)
#define fod(i,j,k) for (int i=j;i>=k;i--)
using namespace std;

typedef long long LL;

const int maxn=110;
const int oo=1000000000;

int a[maxn],n,K,b[maxn];

void init()
{
	scanf("%d%d",&n,&K);
	fou(i,1,n) scanf("%d",&a[i]);
}

int gcd(int x,int y)
{
	int te;
	if (x<y) swap(x,y);
	while (y){
		te=y;
		y=x%y;
		x=te;
	}
	return x;
}

int lcm(int x,int y)
{
	return x/gcd(x,y)*y;
}

void solve()
{
	int Min,p,gbs,tot;
	gbs=a[1];
	fou(i,2,n) gbs=lcm(gbs,a[i]);
	tot=0;
	fou(i,1,n) tot+=gbs/a[i];
	K%=tot;
	if (K==0) K+=tot;
	memset(b,0,sizeof(b));
	fou(i,1,K){
		Min=oo;p=0;
		fou(j,1,n)
			if (Min>b[j]){
				Min=b[j];p=j;
			}
		b[p]+=a[p];
	}
	printf("%d\n",p);
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
