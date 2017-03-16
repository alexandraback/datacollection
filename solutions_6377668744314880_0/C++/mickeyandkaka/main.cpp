#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#define clr(a,b)	memset(a,b,sizeof(a))
using namespace std;

typedef long long LL;

const double eps = 1e-8;

struct cpoint{
    double x, y;
    int idx;
    cpoint(double a=0.0,double b=0.0)	{x=a,y=b;}

    cpoint operator-(const cpoint &u) const{
        return cpoint(x-u.x, y-u.y);
    }

    double operator*(const cpoint &u) const{
        return x*u.y - y*u.x;
    }

    double operator^(const cpoint &u) const{
        return x*u.x + y*u.y;
    }
};

int dcmp(double x) {
	if (x < -eps) return -1; else return x > eps;
}

double cross(cpoint o, cpoint p, cpoint q) { // 叉积
	return (p-o) * (q-o);
}

//下标0开始
bool cmp(const cpoint &a,const cpoint &b) {
    return a.y < b.y || (a.y == b.y && a.x < b.x);
}

int graham(int n,cpoint p[],cpoint res[])	//<=不共线
{
    sort(p,p+n,cmp);
    if(n == 0)  return 0;   res[0] = p[0];
    if(n == 1)  return 1;   res[1] = p[1];
    if(n == 2)  return 2;

    int top = 1,len;
    for(int i=2; i<n; i++){
        while(top && dcmp(cross(res[top-1],res[top],p[i])) < 0)
            top--;
        res[++top] = p[i];
    }

    len = top;
    res[++top] = p[n-2];
    for(int i=n-3; i>=0; i--){
        while(top != len && dcmp(cross(res[top-1],res[top],p[i])) < 0)
            top--;
        res[++top] = p[i];
    }
    return top;
}

int T;
int n;
int ans[100];
cpoint p[100];

cpoint in[100], out[100];

int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("out","w", stdout);

	scanf("%d",&T);
	int cas = 1;
	while(T--)
	{
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
			p[i].idx = i;
			ans[i] = 100000;
		}

		for(int i=1; i<(1<<n); i++)
		{
			int st = i;
			int cnt = 0;
			for(int j=0; j<n; j++)
			{
				if( (1<<j) & st )
					in[cnt++] = p[j];
			}

			int res = graham(cnt, in, out);
			set<int> cst;

			for(int j=0; j<res; j++)
				cst.insert(out[j].idx);
			res = cst.size();


			for(set<int>::iterator it=cst.begin(); it!=cst.end(); it++)
			{
				ans[*it ] = min(ans[*it], n - __builtin_popcount(i));
			}
		}
		printf("Case #%d:\n",cas++);
		for(int i=0; i<n; i++)
			printf("%d\n",ans[i]);
	}

    return 0;
}
