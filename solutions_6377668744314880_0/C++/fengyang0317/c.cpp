#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <cctype>
#include <stack>
#include <ctime>
#include <strstream>
#include <unordered_map>
#include <unordered_set>
typedef long long ll;
#define EPS 1e-8
using namespace std;
typedef pair<int,int> pii;
template<class T> inline T euclide(T a,T b,T &x,T &y)//NOTES:a*x+b*y=1;
{if(a<0){T d=euclide(-a,b,x,y);x=-x;return d;}
if(b<0){T d=euclide(a,-b,x,y);y=-y;return d;}
if(b==0){x=1;y=0;return a;}else{T d=euclide(b,a%b,x,y);T t=x;x=y;y=t-(a/b)*y;return d;}}

struct point
{
	ll x, y;
	bool operator==(const point &b)
	{
		return x==b.x&&y==b.y;
	}
};
bool mult(point sp, point ep, point op){
	return (sp.x - op.x) * (ep.y - op.y)
		> (ep.x - op.x) * (sp.y - op.y);
}
bool operator < (const point &l, const point &r){
	return l.y < r.y || (l.y == r.y && l.x < r.x);
}
int graham(point pnt[], int n, point res[]){
	ll i, len, k = 0, top = 1;
	sort(pnt, pnt + n);
	if (n == 0) return 0; res[0] = pnt[0];
	if (n == 1) return 1; res[1] = pnt[1];
	if (n == 2) return 2; res[2] = pnt[2];
	for (i = 2; i < n; i++) {
		while (top && mult(pnt[i], res[top], res[top-1]))
			top--;
		res[++top] = pnt[i];
	}
	len = top; res[++top] = pnt[n - 2];
	for (i = n - 3; i >= 0; i--) {
		while (top!=len && mult(pnt[i], res[top],
			res[top-1])) top--;
		res[++top] = pnt[i];
	}
	return top; // 返回凸包中点的个数
}
int main()
{
	ios_base::sync_with_stdio(false);
	freopen("C-small-attempt1.in","r",stdin);
	freopen("out.txt","w",stdout);
	int cas;
	int ki,i,j;
	scanf("%d",&cas);
	for(ki=1;ki<=cas;ki++)
	{
		printf("Case #%d:\n",ki);
		point ps[30],ve[30],ori[30];
		int n,to;
		cin>>n;
		for(i=0;i<n;i++)
		{
			cin>>ps[i].x>>ps[i].y;
			ori[i]=ps[i];
		}
		int res[30];
		memset(res,-1,sizeof(res));
		to=graham(ps,n,ve);
		for(i=0;i<to;i++)
		{
			for(j=0;j<n;j++)
				if(ori[j]==ve[i])res[j]=0;
		}
		for(i=0;i<n;i++)
		{
			if(res[i]==-1)
			{
				//res[i]=n;
				for(int mask=0;mask<(1<<n);mask++)
				{
					if(mask&(1<<i)==0)continue;
					int co=0;
					point pl[30],ll[30];
					for(j=0;j<n;j++)
						if(mask&(1<<j))
						{
							pl[co]=ps[j];
							co++;
						}
					if(co<3)continue;
					int lo=graham(pl,co,ll);
					for(j=0;j<lo;j++)
						if(ll[j]==ori[i])
						{
							res[i]=max(res[i],co);
							break;
						}
				}
				res[i]=n-res[i];
			}
		}
		for(i=0;i<n;i++)
			cout<<res[i]<<endl;
		fflush(stdout);
	}
	return 0;
}