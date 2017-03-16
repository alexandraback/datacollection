#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repn(i,a,n) for(int (i)=(a);(i)<(int)(n);(i)++)
#define EQ(a,b) (abs((a)-(b))<eps)
struct P
{
	ll x,y;
	P() {}
	P(ll x,ll y) : x(x),y(y){}
	P operator + (P p)
	{
		return P(x+p.x,y+p.y);
	}
	P operator - (P p)
	{
		return P(x-p.x,y-p.y);
	}
	P operator * (ll d)
	{
		return P(x*d,y*d);
	}
	ll dot(P p)
	{
		return x*p.x+y*p.y;
	}
	ll det(P p)
	{
		return x*p.y-y*p.x;
	}
};

bool on_line(P p1,P p2,P q)//直線p1-p2上にqがあるか
{
	return (p1-q).det(p2-q)==0ll;
}

bool triangle_sign(P p1,P p2,P q)
{
	return (p1-q).det(p2-q)>0ll;
}
int N;
P po[3010];
int ans[3010];
int main()
{
	int T;
	scanf("%d",&T);
	for(int t=0;t<T;t++)
	{
		scanf("%d",&N);
		for(int i=0;i<N;i++)ans[i]=N;
		for(int i=0;i<N;i++)scanf("%lld %lld",&po[i].x,&po[i].y);
		if(N==1)
		{
			printf("Case #%d:\n",t+1);
			printf("0\n");
			continue;
		}
		if(N==2)
		{
			printf("Case #%d:\n",t+1);
			printf("0\n");
			printf("0\n");
			continue;
		}
		for(int i=0;i<N;i++)
		{
			for(int j=i+1;j<N;j++)
			{
				int up=0,online=0;
				for(int k=0;k<N;k++)
				{
					if(on_line(po[i],po[j],po[k]))online++;
					if(triangle_sign(po[i],po[j],po[k]))up++;
				}
				//printf("%d %d %d %d\n",i,j,up,online);
				ans[i]=min(ans[i],min(N-online-up,up));
				ans[j]=min(ans[j],min(N-online-up,up));
			}
		}
		printf("Case #%d:\n",t+1);
		for(int i=0;i<N;i++)printf("%d\n",ans[i]);
	}
	return 0;
}
