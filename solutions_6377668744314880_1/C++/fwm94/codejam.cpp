#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define maxn 10009
#define eps 1e-9
using namespace std;
int tt,n;
const double PI=acos(-1.0);
const double INF=1e18;
struct Point
{
	double x,y;
	double ang;
	Point(double _=0,double __=0)
	{
		x=_;y=__;
	}
	void read()
	{
		scanf("%lf%lf",&x,&y);
	}
}p[maxn];
inline int sgn(double x)
{
	if(-eps<x&&x<eps)
		return 0;
	else if(x>0)
		return 1;
	else
		return -1;
}
double a[maxn],b[maxn];
inline int solve(int n,int m,int tot)
{
	int inup=0,indw=0;
	double cur=0;
	int i,j;
	for(i=0;i<n;i++)
	{
		if(sgn(a[i]-cur)==0)
			inup++;
		else
			break;
	}
	for(j=0;j<m;j++)
	{
		if(sgn(b[j]-(cur-PI))==0)
			indw++;
		else
			break;
	}
	int onright=0;
	for(int k=0;k<m;k++)
	{
		if(sgn(b[k]+PI)!=0)
			onright++;
	}
	int ans=min(onright,tot-onright-inup-indw);
	double ang1,ang2;
	int cnt1=0;
	int cnt2=0;
	while(i<n||j<m)
	{
		if(i<n)
			ang1=a[i]-cur;
		else
			ang1=INF;
		if(j<m)
			ang2=b[j]+PI-cur;
		else 
			ang2=INF;
		if(sgn(ang1-ang2)==0)
		{
			cnt1=1;
			while(i+1<n&&sgn(a[i+1]-a[i])==0)
				cnt1++,i++;
			cnt2=1;
			while(j+1<m&&sgn(b[j+1]-b[j])==0)
				cnt2++,j++;
			onright+=inup;
			inup=cnt1;
			indw=cnt2;
			onright-=indw;
			i++;j++;
		}
		else if(sgn(ang1-ang2)>0)
		{
			cnt2=1;
			while(j+1<m&&sgn(b[j+1]-b[j])==0)
				cnt2++,j++;
			indw=cnt2;
			onright-=indw;
			onright+=inup;
			inup=0;
			j++;
		}
		else
		{
			cnt1=1;
			while(i+1<n&&sgn(a[i+1]-a[i])==0)
				cnt1++,i++;
			onright+=inup;
			inup=cnt1;
			indw=0;
			i++;
		}
		ans=min(ans,onright);
		ans=min(ans,tot-onright-inup-indw);
	}
	return ans;
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&tt);
	int cnt1=0,cnt2=0,cot=1;
	double tmp;
	while(tt--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			p[i].read();
		printf("Case #%d:\n",cot++);
		for(int i=0;i<n;i++)
		{
			cnt1=cnt2=0;
			for(int j=0;j<n;j++)
			{
				if(j==i)
					continue;
				tmp=atan2(p[j].y-p[i].y,p[j].x-p[i].x);
				if(sgn(tmp-PI)==0)
					tmp=-tmp;
				if(sgn(tmp)>=0)
					a[cnt1++]=tmp;
				else
					b[cnt2++]=tmp;
			}
			sort(a,a+cnt1);
			sort(b,b+cnt2);
			printf("%d\n",solve(cnt1,cnt2,n-1));
		}	
	}
	//system("pause");
	return 0;
}