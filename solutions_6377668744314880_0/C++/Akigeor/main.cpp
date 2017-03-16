// Template by Akigeor
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define ff first
#define ss second
#define pb push_back
#define PII pair<int,int>
#define rep(i,n) for (i=0;i<(n);i++)
#define fo(i,L,R) for (i=(L);i<=(R);i++)
#define cls(x) memset(x,0,sizeof(x))
#define cin(x) scanf("%d",&x)
#define mINF 0x3f
#define INF 0x3f3f3f3f
#define MOD7 1000000007
#define MOD9 1000000009
#define PI acos(-1.0)
using namespace std;
struct point
{
	int x,y,ind;
	point(int a,int b) {x=a; y=b; ind=0;}
	point() {x=y=ind=0;}
};
point operator - (point a,point b)
{
	return point(a.x-b.x,a.y-b.y);
}
long long operator * (point a,point b)
{
	return 1LL*a.x*b.y-1LL*a.y*b.x;
}
point a[20];
int q[20];
bool cmp(point i,point j)
{
	if (i.x==j.x) return i.y<j.y;
	return i.x<j.x;
}
int cnt(int x)
{
	int m=0;
	while (x)
	{
		if (x&1) m++;
		x>>=1;
	}
	return m;
}
int d[20];
int main()
{
	int z,Z;
	cin(Z);
	fo(z,1,Z)
	{
		int i,j,k,l,n;
		cin(n);
		rep(i,n)
		{
			cin(a[i].x);
			cin(a[i].y);
			a[i].ind=i;
		}
		sort(a,a+n,cmp);
		rep(i,n) d[i]=n-1;
		fo(l,1,(1<<n)-1)
		{
			rep(j,n) if (l&(1<<j)) {q[0]=j; break;}
			k=0;
			int t=0,las=j;
			fo(i,j+1,n-1)
			{
				if (l&(1<<i))
				{
					las=i;
					while (t>k && (a[i]-a[q[t-1]])*(a[q[t]]-a[q[t-1]])>0) t--;
					q[++t]=i;
				}
			}
			k=t;
			for (i=las-1;i>=j;i--)
			{
				if (l&(1<<i))
				{
					while (t>k && (a[i]-a[q[t-1]])*(a[q[t]]-a[q[t-1]])>0) t--;
					q[++t]=i;
				}
			}
			j=cnt(l);
			fo(i,0,t) d[a[q[i]].ind]=min(d[a[q[i]].ind],n-j);
		}
		printf("Case #%d:\n",z);
		rep(i,n) printf("%d\n",d[i]);
	}
}
