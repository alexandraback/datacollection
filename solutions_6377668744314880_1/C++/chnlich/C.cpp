/*
	Author : ChnLich
*/
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<iostream>
#include<sstream>
#include<fstream>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<string>
#include<bitset>
#include<functional>
#include<utility>

using namespace std;

typedef long long llint;
typedef pair<int,int> ipair;
typedef unsigned int uint;
#define pb push_back
#define fi first
#define se second
#define mp make_pair

const int MOD=1000000007,dx[]={0,1,0,-1},dy[]={1,0,-1,0};
const double eps=1e-8;

void read(int &k)
{
	k=0; char x=getchar();
	while(x<'0'||x>'9') x=getchar();
	while(x>='0'&&x<='9') { k=k*10-48+x; x=getchar(); }
}

int T,n;

struct point
{
	int x,y;
	point(int _x=0,int _y=0)
	{
		x=_x; y=_y;
	}
	point operator - (const point&b)
	{
		return point(x-b.x,y-b.y);
	}
} a[3010],b[6010];

int check(const point&a)
{
	if (a.y<0) return 0;
	if (a.y>0) return 1;
	if (a.x>0) return 0;
	return 1;
}

int sgn(llint x)
{
	if (x==0) return 0;
	return x>0?1:-1;
}

int scross(const point&a,const point&b)
{
	return sgn(1ll*a.x*b.y-1ll*a.y*b.x);
}

bool cmp(const point&a,const point&b)
{
	int sa=check(a);
	int sb=check(b);
	if (sa!=sb) return sa<sb;
	return scross(a,b)>0;
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		fprintf(stderr,"%d\n",tt);
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d%d",&a[i].x,&a[i].y);
		printf("Case #%d:\n",tt);
		
		for(int i=0;i<n;i++)
		{
			int ans=n-1;
			int m=0;
			for(int j=0;j<n;j++) if (j!=i) b[m++]=a[j]-a[i];
			sort(b,b+m,cmp);
			for(int j=0;j<m;j++) b[j+m]=b[j];
			int nxt=0;
			for(int j=0;j<m;j++)
			{
				while(nxt<=j) nxt++;
				while(nxt<2*m&&scross(b[j],b[nxt])>0) nxt++;
				ans=min(ans,nxt-j-1);
				//while(nxt<m&&scross(b[j],b[nxt])>=0) nxt++;
				//ans=min(ans,m-nxt+j);
			}
			printf("%d\n",ans);
		}
		
		// brute force
		/*
		int o=1<<n;
		static int out[50];
		for(int i=0;i<n;i++) out[i]=n-1;
		for(int i=0;i<o;i++)
		{
			int del=__builtin_popcount((~i)&(o-1));
			#define in(i,j) (((i)>>(j))&1)
			for(int j=0;j<n;j++) if (in(i,j)) 
			for(int k=j+1;k<n;k++) if (in(i,k))
			{
				int dd=0,t;
				for(t=0;t<n;t++) if (in(i,t))
				{
					int dir=scross(a[k]-a[j],a[t]-a[j]);
					if (dir*dd<0) break;
					if (dir) dd=dir;
				}
				if (t<n) continue;
				out[j]=min(out[j],del);
				out[k]=min(out[k],del);
			}
		}
		for(int i=0;i<n;i++) printf("%d\n",out[i]);
		*/
	}
	
	return 0;
}
