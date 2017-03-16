#include<bits/stdc++.h>
#define rep(i,s,n) for((i)=(s);(i)<=(n);(i)++)
#define getint(x) scanf("%d",&x)
#define getlong(x) scanf("%lld",&x)
#define putint(x) printf("%d",x)
#define putintln(x) printf("%d\n",x)
#define putlong(x) printf("%lld",x)
#define putlongln(x) printf("%lld\n",x)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
pair<int,int > p[20];
int side(int i,int j,int k)
{
	int x1=p[i].first;
	int x2=p[j].first;
	int y1=p[i].second;
	int y2=p[j].second;
	int x3=p[k].first;
	int y3=p[k].second;
	double res;
	if(x1!=x2)
	{
		double d=y2-y1;
		d=d/(x2-x1);
		res=(y3-y1)-d*(x3-x1);
	}
	else
	{
		res=(x3-x1);
	}
	if(res<0)
		return -1;
	else if(res>0)
		return 1;
	else
		return 0;
}

int main()
{
	int t,n,ind,i,x,y,j,k;
	getint(t);
	rep(ind,1,t)
	{
		getint(n);
		rep(i,0,n-1)
		{
			getint(x);
			getint(y);
			p[i]=mp(x,y);
		}
		int ar[20]={0};
		int	val[20]={0};
		if(n>3)
		{
			rep(i,0,n-1)
		{
			rep(j,0,n-1)
			{
				if(j==i||(ar[i]&&ar[j]))
					continue;
				int val=0,tr1=0,tr2=0;
				rep(k,0,n-1)
				{
					if(k==j||k==i)
						continue;
					int l=side(i,j,k);
					if(l<0)
						tr1=1;
					else if(l>0)
						tr2=1;
				}
				tr1*=tr2;
				if(tr1!=1)
				{
					ar[i]=1;
					ar[j]=1;
				}
			}
		}
		
		rep(i,0,n-1)
		{
			if(ar[i]==1)
				continue;
			int minl=n+1;
			rep(j,0,n-1)
			{
				if(i==j)
					continue;
				int val1=0,val2=0;
				rep(k,0,n-1)
				{
					if(k==j||k==i)
						continue;
					if(side(i,j,k)<0)
						val1++;
					else if(side(i,j,k)>0)
						val2++;
				}
				int re=min(val1,val2);
				minl=min(minl,re);
			}
			val[i]=minl;
		}
		}
		printf("Case #%d:\n",ind);
		rep(i,0,n-1)
		putintln(val[i]);
	}
}