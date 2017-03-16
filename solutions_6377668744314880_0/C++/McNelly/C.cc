#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define print(x) cout << x << endl
#define input(x) cin >> x


const int SIZE = 1024;
const double eps = 1e-8;


inline int zero(double x)
{
	if(x>eps) return 1;
	else if(x<-eps) return -1;
	else return 0;
}

inline double mul(double x)
{
	return x*x;
}

struct point {
    double x, y;
    point(){}
    point(double ix, double iy): x(ix), y(iy) {}
};

struct segment
{
	point p1,p2;
	segment(){}
	segment(const point &ip1,const point &ip2)
	{
		p1=ip1;p2=ip2;
	}

};

double pntDis(const point &a,const point &b)
{
	return sqrt(mul(a.x-b.x)+mul(a.y-b.y));
}

double xmult(const point &sp,const point &ep,const point &op)
{
	return ((sp.x-op.x)*(ep.y-op.y)-(sp.y-op.y)*(ep.x-op.x));
}


bool onSegment(segment s,point p)
{
	return zero(xmult(s.p2,p,s.p1))==0 &&
			zero((p.x-s.p1.x)*(p.x-s.p2.x))<=0 &&
			zero((p.y-s.p1.y)*(p.y-s.p2.y))<=0;
}


namespace ConvexHull//一定要多于三个点
{
    int sz;
    point array[SIZE];
    point stack[SIZE];
    point *p;
    inline void push(point n){*p=n; p++;}
    inline void pop(){p--;}
    inline void init(int isz)
    {
        sz=isz;
        memset(stack,0,sizeof(stack));
        p=stack;
    }

    int cmp(point p1,point p2)
    {
        if(zero(xmult(p1,p2,array[0])) > 0) return 1;
        else if(zero(xmult(p1,p2,array[0])) == 0
            && zero(pntDis(p1,array[0]) - pntDis(p2,array[0])) < 0) return 1;
        else return 0;
    }
    int findtop()
    {
        int res=0;
        for(int i=1;i<sz;i++)
        {
            if(array[i].y<array[res].y) res=i;
            else if(array[i].y==array[res].y && array[i].x<array[res].x) res=i;
        }
        return res;
    }

    int graham()
    {
        int top=findtop();
        push(array[top]);
        swap(array[0],array[top]);
        sort(array+1,array+sz,cmp);
        
        push(array[1]);
        push(array[2]);
        for(int i=3;i<sz;i++)
        {
            while(zero(xmult(array[i],*(p-1),*(p-2))) > 0) {
                pop();//有等号时，不包括点都在一条直线的情况
            }
            push(array[i]);
        }
        return p-stack;
    }
    
    //先求出凸包，然后传入凸包顶点数，求出最远顶点对的距离
    double maxPntDis(int num)
    {
        double ans=0;
        int q=1;
        stack[num]=stack[0];
        for(int p=0;p<num;p++)
        {
            while(xmult(stack[p+1],stack[q+1],stack[p])>xmult(stack[p+1],stack[q],stack[p]))
            {
                q=(q+1)%num;
            }
            ans=max(ans,max(pntDis(stack[p],stack[q]),pntDis(stack[p+1],stack[q+1])));
        }
        return ans;
    }
};

int n;
vector<point> vec;
vector<int> ans;

int brute_force(int u) {
    int res = n;
    for (int i = 0; i < (1 << n); i++) {
        if (!(i & (1 << u))) {
            continue;
        }
        vector<point> tmp;
        for (int j = 0; j < n; j++) {
            if (!(i & (1 << j))) {
                continue;
            }
            tmp.push_back(vec[j]);
        }
        if (tmp.size() < 3) {
            continue;
        }
        ConvexHull::init(tmp.size());
        for (int j = 0; j < (int)tmp.size(); j++) {
            ConvexHull::array[j] = tmp[j];
        }
        int m = ConvexHull::graham();
        for (int j = 0; j < m; j++) {
            point a = ConvexHull::stack[j];
            point b = ConvexHull::stack[(j + 1) % m];
            
            if (onSegment(segment(a, b), vec[u])) {
                res = min(res, n - (int)tmp.size());
            }
        }
    }
    return res;
}

void solve() {
    ConvexHull::init(n);
    for (int i = 0; i < n; i++) {
        ConvexHull::array[i] = vec[i];
    }
    int m = ConvexHull::graham();
    ans.clear();
    ans.resize(n);
    fill(ans.begin(), ans.end(), -1);
    for (int i = 0; i < m; i++) {
        point a = ConvexHull::stack[i];
        point b = ConvexHull::stack[(i + 1) % m];
        
        for (int j = 0; j < n; j++) {
            if (onSegment(segment(a, b), vec[j])) {
                ans[j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == -1) {
            ans[i] = brute_force(i);
        }
    }
    for (int i = 0; i < n; i++) {
        print(ans[i]);
    }
}

int main() {
    int T, cas = 1;
    int a, b;
    input(T);
    while (T--) {
        input(n);
        vec.clear();
        for (int i = 0; i < n; i++) {
            input(a >> b);
            vec.push_back(point(a, b));
        }
        printf("Case #%d: \n", cas++);
        solve();
    }
    return 0;
}

