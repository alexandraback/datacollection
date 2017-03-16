#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct point
{
	int x,y,p;
	point(int _x=0,int _y=0) {x=_x,y=_y;}
	bool operator <(const point&B) const {return x<B.x||(x==B.x&&y<B.y);}
	friend ll operator *(const point&A,const point&B) {return 1ll*A.x*B.y-1ll*A.y*B.x;}
	friend point operator -(const point&A,const point&B) {return point(A.x-B.x,A.y-B.y);}
} a[6005],c[6005],q[6005];
int N,M;
bool b[6005];

void init()
{
	scanf("%d",&N);
	for (int i=0; i<N; i++) scanf("%d%d",&a[i].x,&a[i].y),a[i].p=i;
}

bool check(int bg)
{
	int t=0,n=0;
	for (int i=0; i<N; i++) if (b[i]) c[++n]=a[i];
	sort(c+1,c+n+1);
	/*
	for (int i=1; i<=n; i++)
	{
		for (;t&&(c[i]-q[t-1])*(q[t]-q[t-1])<0; t--);
		q[++t]=c[i];
	}
//	for (int i=1; i<=t; i++) cout<<"  "<<q[i].x<<' '<<q[i].y<<' '<<q[i].p<<endl;
//	puts("====");
	for (int i=n-1; i; i--)
	{
		for (;t&&(c[i]-q[t-1])*(q[t]-q[t-1])<0; t--);
		q[++t]=c[i];
	}
	for (int i=1; i<=t; i++) if (q[i].p==bg) return 1;
	return 0;*/
	for (int i=1; i<=n; i++)
	{
		for (;t>1&&(c[i]-q[t-1])*(q[t]-q[t-1])>0; t--);
		q[++t]=c[i];
	}
	for (int i=n-1,tt=t; i; i--)
	{
		for (;t>tt&&(c[i]-q[t-1])*(q[t]-q[t-1])>0; t--);
		q[++t]=c[i];
	}
	//for (int i=1; i<=t; i++) q[t+i]=q[i];
	//for (int i=3; i<=t; i++) if ((q[i]-q[i-2])*(q[i-1]-q[i-2])>0) cerr<<"BG"<<endl;
//	for (int i=1; i<=t; i++) cout<<"  "<<q[i].x<<' '<<q[i].y<<' '<<q[i].p<<endl;
	for (int i=1; i<=t; i++) if (q[i].p==bg) return 1;
	return 0;
}

void doit()
{
	for (int i=0; i<N; i++)
	{
		int res=1e9;
		for (int j=0; j<1<<N; j++) if ((j>>i)&1)
		{
			int t=0;
			for (int k=0; k<N; k++) b[k]=(j>>k)&1,t+=!b[k];
			if (t<res&&check(i))
			{
			//	cout<<i<<' '<<j<<' '<<t<<endl;
				res=min(res,t);
			}
		}
		printf("%d\n",res);
	}
}

int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int i=1; i<=T; i++)
	{
		init();
		printf("Case #%d:\n",i);
		doit();
	}
	return 0;
}
/*
2
5
0 0
10 0
10 10
0 10
5 5
9
0 0
5 0
10 0
0 5
5 5
10 5
0 10
5 10
10 10
*/
