#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <queue>

using namespace std;

#define	sqr(a)		((a)*(a))
#define	rep(i,a,b)	for(int i=(a);i<(int)(b);i++)
#define	per(i,a,b)	for(int i=((a)-1);i>=(int)(b);i--)
#define	PER(i,n)	per(i,n,0)
#define	REP(i,n)	rep(i,0,n)
#define	clr(a)		memset((a),0,sizeof (a))
#define	SZ(a)		((int)((a).size()))
#define	ALL(x)		x.begin(),x.end()
#define	mabs(a)		((a)>0?(a):(-(a)))
#define	inf			(0x7fffffff)
#define	eps			1e-6

#define	MAXN		
#define MODN		(1000000007)

typedef long long ll;

#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
struct point{double x,y;};

double xmult(point p1,point p2,point p0){
	return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
point p1,p2;
int graham_cp(const void* a,const void* b){
	double ret=xmult(*((point*)a),*((point*)b),p1);
	return zero(ret)?(xmult(*((point*)a),*((point*)b),p2)>0?1:-1):(ret>0?1:-1);
}
void _graham(int n,point* p,int& s,point* ch){
	int i,k=0;
	for (p1=p2=p[0],i=1;i<n;p2.x+=p[i].x,p2.y+=p[i].y,i++)
		if (p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
			p1=p[k=i];
	p2.x/=n,p2.y/=n;
	p[k]=p[0],p[0]=p1;
	qsort(p+1,n-1,sizeof(point),graham_cp);
	for (ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
		for (;s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps;s--);
}

int graham(int n,point* p,point* convex,int maxsize=1,int dir=1){
	point temp[3005];
	int s,i;
	_graham(n,p,s,temp);
	for (convex[0]=temp[0],n=1,i=(dir?1:(s-1));dir?(i<s):i;i+=(dir?1:-1))
		if (maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
			convex[n++]=temp[i];
	//delete []temp;
	return n;
}


#define TEST_LOCAL 1
int a[3005][2];
int main()
{
	freopen("data.in","r",stdin);
#if TEST_LOCAL
	freopen("data.out","w",stdout);
#endif

	int T;
	scanf("%d",&T);

	for (int K = 1;K <= T;K++)
	{
		int n;
		scanf("%d",&n);

		int res[3005];
		REP(i,n)
		{
			scanf("%d %d",&a[i][0],&a[i][1]);
			res[i] = n;
		}
		

		REP(i,(1 << n))
		{
			if (i == 0)
			{
				continue;
			}

			int cnt = 0;
			point ppp[3005];
			point pp[3005];
			int rr[3005];
			REP(j,n)
			{
				if ((i >> j) & 1)
				{
					pp[cnt].x = a[j][0];
					pp[cnt].y = a[j][1];
					ppp[cnt].x = a[j][0];
					ppp[cnt].y = a[j][1];
					rr[cnt] = j;
					cnt++;
				}
			}


			point qq[3005];
			int m = graham(cnt,pp,qq);
			REP(j,cnt)
			{
				REP(k,m)
				{
					if (ppp[j].x == qq[k].x &&
						ppp[j].y == qq[k].y)
					{
						res[rr[j]] = min(res[rr[j]],n - cnt);
						break;
					}
				}
			}
		}
		
		printf("Case #%d:\n",K);
		REP(i,n)
		{
			printf("%d\n",res[i]);
		}
	}


	return 0;
}
