#include<cstdio>
#include<cstring>
#include<algorithm>
#define  LL long long
using namespace std;
struct Point{
	int x,y,id;
}p[32],pp[32],q[32];
bool f[32],flag[32],is_on_convex[32];
int n,Testcase;
bool cmp(Point x,Point y){
	return x.x<y.x||x.x==y.x&&x.y<y.y;
}
inline LL xmul(Point a,Point b,Point c,Point d){
	return (LL)(b.x-a.x)*(d.y-c.y)-(LL)(b.y-a.y)*(d.x-c.x);
}
inline  void Convex()
{
	int m=0,last,top;
	for(int i=1;i<=n;i++)
		if(f[pp[i].id])
		{
			p[++m]=pp[i];
		}
		
	sort(p+1,p+m+1,cmp);

	
	q[1]=p[1];q[2]=p[2];top=2;
	for(int i=3;i<=m;i++){
		while(top>1&&xmul(q[top-1],q[top],q[top],p[i])>0)
			top--;
		q[++top]=p[i];
	}
	last=top;
	q[++top]=p[m-1];
	for(int i=m-2;i;i--){
		while(top>last&&xmul(q[top-1],q[top],q[top],p[i])>0)
			top--;
		q[++top]=p[i];
	}
	memset(is_on_convex,0,sizeof(is_on_convex));
	for(int i=1;i<=top;i++)
		is_on_convex[q[i].id]=1;
}
inline int count(int mask)
{
	int cnt=0;
	for(int i=0;i<n;i++)if((1<<i)&mask)cnt++;
	return cnt;
}
int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&Testcase);
	for(int t=1;t<=Testcase;t++)
	{
		scanf("%d",&n);

		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&pp[i].x,&pp[i].y);
			pp[i].id=i;
			f[i]=1;
		}
		if(n<=2)
		{
			printf("Case #%d: \n",t);
			for(int i=1;i<=n;i++)printf("0\n");
			continue;
		}
		Convex();
		for(int i=1;i<=n;i++)flag[i]=is_on_convex[i];
		printf("Case #%d:\n",t);
		for(int i=1;i<=n;i++)
		{
			if(flag[i])
			{
				printf("0\n");
				continue;
			}
			int mincut=n-1;
			for(int mask=0;mask<1<<n;mask++)
				if((1<<(i-1)&mask)==0 and (count(mask)<mincut))
				{
					for(int j=1;j<=n;j++)
						if((1<<(j-1))&mask)
							f[j]=0;
						else f[j]=1;
					Convex();
					if(is_on_convex[i])
					{
						mincut=min(mincut,count(mask));
					}
				}
			printf("%d\n",mincut);
		}
	}
}