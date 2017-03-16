#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<list>
#include<map>
#include<set>
#include<queue>
#include<deque>
#include<vector>
#include<functional>
#include<string>
#define INF 1000000007
#define ll long long
#define rep(i,k) for(int i=G.start[k];i!=INF;i=G.next[i])

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);

class point
{
public:
    double x, y;
	int id;
    point(){};
    point(double x, double y):x(x),y(y){};
 
    static int xmult(const point &ps, const point &pe, const point &po)
    {
        return (ps.x - po.x) * (pe.y - po.y) - (pe.x - po.x) * (ps.y - po.y);
    }

    double operator *(const point &_Off) const
    {
        return x * _Off.y - y * _Off.x;
    }
    point operator - (const point &_Off) const
    {
        return point(x - _Off.x, y - _Off.y);
    }
    bool operator == (const point &_Off) const
    {
        return std::fabs(_Off.x - x) < eps && std::fabs(_Off.y - y) < eps;
	}
    bool operator != (const point &_Off) const
    {
        return ((*this) == _Off) == false;
    }
    double dis2(const point &_Off) const
    {
        return (x - _Off.x) * (x - _Off.x) + (y - _Off.y) * (y - _Off.y);
    }
    double dis(const point &_Off) const
    {
        return std::sqrt((x - _Off.x) * (x - _Off.x) + (y - _Off.y) * (y - _Off.y));
    }
};

bool cmp(const point p1,const point p2)
{
	return p1.id<p2.id;
}

class pVector
{
public:
    point s, e;
    double a, b, c;
 
    pVector(){}
    pVector(const point &s, const point &e):s(s),e(e){}
 
    double operator *(const point &_Off) const
    {
        return (_Off.y - s.y) * (e.x - s.x) - (_Off.x - s.x) * (e.y - s.y);
    }
    double operator *(const pVector &_Off) const
    {
        return (e.x - s.x) * (_Off.e.y - _Off.s.y) - (e.y - s.y) * (_Off.e.x - _Off.s.x);
    }
    bool pton()
    {
        a = s.y - e.y;
        b = e.x - s.x;
        c = s.x * e.y - s.y * e.x;
        return true;
    }
    friend bool operator<(const point &_Off, const pVector &_Ori)
    {
        return (_Ori.e.y - _Ori.s.y) * (_Off.x - _Ori.s.x)
            < (_Off.y - _Ori.s.y) * (_Ori.e.x - _Ori.s.x);
    }
    bool lhas(const point &_Off) const
    {
        return std::fabs((*this) * _Off) < eps;
    }
    bool shas(const point &_Off) const
    {
        return lhas(_Off)
            && _Off.x - std::min(s.x, e.x) > -eps && _Off.x - std::max(s.x, e.x) < eps
            && _Off.y - std::min(s.y, e.y) > -eps && _Off.y - std::max(s.y, e.y) < eps;
    }
    double dis(const point &_Off, bool isSegment = false)
    {
        pton();
 
        double td = (a * _Off.x + b * _Off.y + c) / sqrt(a * a + b * b);
 
        if(isSegment)
        {
            double xp = (b * b * _Off.x - a * b * _Off.y - a * c) / ( a * a + b * b);
            double yp = (-a * b * _Off.x + a * a * _Off.y - b * c) / (a * a + b * b);
            double xb = std::max(s.x, e.x);
            double yb = std::max(s.y, e.y);
            double xs = s.x + e.x - xb;
            double ys = s.y + e.y - yb;
            if(xp > xb + eps || xp < xs - eps || yp > yb + eps || yp < ys - eps)
                td = std::min(_Off.dis(s), _Off.dis(e));
        }
 
        return fabs(td);
    }
    point mirror(const point &_Off) const
    {
        point ret;
        double d = a * a + b * b;
        ret.x = (b * b * _Off.x - a * a * _Off.x - 2 * a * b * _Off.y - 2 * a * c) / d;
        ret.y = (a * a * _Off.y - b * b * _Off.y - 2 * a * b * _Off.x - 2 * b * c) / d;
        return ret;
    }
    static pVector ppline(const point &_a, const point &_b)
    {
        pVector ret;
        ret.s.x = (_a.x + _b.x) / 2;
        ret.s.y = (_a.y + _b.y) / 2;
        ret.a = _b.x - _a.x;
        ret.b = _b.y - _a.y;
        ret.c = (_a.y - _b.y) * ret.s.y + (_a.x - _b.x) * ret.s.x;
        if(std::fabs(ret.a) > eps)
        {
            ret.e.y = 0.0;
            ret.e.x = - ret.c / ret.a;
            if(ret.e == ret. s)
            {
                ret.e.y = 1e10;
                ret.e.x = - (ret.c - ret.b * ret.e.y) / ret.a;
            }
        }
        else
        {
            ret.e.x = 0.0;
            ret.e.y = - ret.c / ret.b;
            if(ret.e == ret. s)
            {
                ret.e.x = 1e10;
                ret.e.y = - (ret.c - ret.a * ret.e.x) / ret.b;
            }
        }
        return ret;
    }
    bool equal(const pVector &_Off) const
    {
        return lhas(_Off.e) && lhas(_Off.s);
    }
    bool parallel(const pVector &_Off) const
    {
        return std::fabs((*this) * _Off) < eps;
    }
    point crossLPt(pVector _Off)
    {
        point ret = s;
        double t = ((s.x - _Off.s.x) * (_Off.s.y - _Off.e.y) - (s.y - _Off.s.y) * (_Off.s.x - _Off.e.x))
                / ((s.x - e.x) * (_Off.s.y - _Off.e.y) - (s.y - e.y) * (_Off.s.x - _Off.e.x));
        ret.x += (e.x - s.x) * t;
        ret.y += (e.y - s.y) * t;
        return ret;
    }
    bool crossSL(const pVector &_Off) const
    {
        double rs = (*this) * _Off.s;
        double re = (*this) * _Off.e;
        return rs * re < eps;
    }
    bool isCrossSS(const pVector &_Off) const
    {
        return (
            (std::max(s.x, e.x) >= std::min(_Off.s.x, _Off.e.x)) &&
            (std::max(_Off.s.x, _Off.e.x) >= std::min(s.x, e.x)) &&
            (std::max(s.y, e.y) >= std::min(_Off.s.y, _Off.e.y)) &&
            (std::max(_Off.s.y, _Off.e.y) >= std::min(s.y, e.y)) &&
            ((pVector(_Off.s, s) * _Off) * (_Off * pVector(_Off.s, e)) >= 0.0) &&
            ((pVector(s, _Off.s) * (*this)) * ((*this) * pVector(s, _Off.e)) >= 0.0)
            );
    }
};
 
bool inpol[3005];

class polygon
{
public:
    const static long maxpn = 4000;
    point pt[maxpn];
    long n;
 
    point& operator[](int _p)
    {
        return pt[_p];
    }
 
    double area() const
    {
        double ans = 0.0;
        int i;
        for(i = 0; i < n; i ++)
        {
            int nt = (i + 1) % n;
            ans += pt[i].x * pt[nt].y - pt[nt].x * pt[i].y;
        }
        return std::fabs(ans / 2.0);
    }
    point gravity() const
    {
        point ans;
        ans.x = ans.y = 0.0;
        int i;
        double area = 0.0;
        for(i = 0; i < n; i ++)
        {
            int nt = (i + 1) % n;
            double tp = pt[i].x * pt[nt].y - pt[nt].x * pt[i].y;
            area += tp;
            ans.x += tp * (pt[i].x + pt[nt].x);
            ans.y += tp * (pt[i].y + pt[nt].y);
        }
        ans.x /= 3 * area;
        ans.y /= 3 * area;
        return ans;
    }
    bool chas(const point &_Off) const
    {
        double tp = 0, np;
        int i;
        for(i = 0; i < n; i ++)
        {
            np = pVector(pt[i], pt[(i + 1) % n]) * _Off;
            if(tp * np < -eps)
                return false;
            tp = (std::fabs(np) > eps)?np: tp;
        }
        return true;
    }
    bool ahas(const point &_Off) const
    {
        int ret = 0;
        double infv = 1e-10;
        pVector l = pVector(_Off, point( -infv ,_Off.y));
        for(int i = 0; i < n; i ++)
        {
            pVector ln = pVector(pt[i], pt[(i + 1) % n]);
            if(fabs(ln.s.y - ln.e.y) > eps)
            {
                point tp = (ln.s.y > ln.e.y)? ln.s: ln.e;
                if(fabs(tp.y - _Off.y) < eps && tp.x < _Off.x + eps)
                    ret ++;
            }
            else if(ln.isCrossSS(l))
                ret ++;
        }
        return (ret % 2 == 1);
    }
    polygon split(pVector _Off)
    {
        polygon ret;
        point spt[2];
        double tp = 0.0, np;
        bool flag = true;
        int i, pn = 0, spn = 0;
        for(i = 0; i < n; i ++)
        {
            if(flag)
                pt[pn ++] = pt[i];
            else
                ret.pt[ret.n ++] = pt[i];
            np = _Off * pt[(i + 1) % n];
            if(tp * np < -eps)
            {
                flag = !flag;
                spt[spn ++] = _Off.crossLPt(pVector(pt[i], pt[(i + 1) % n]));
            }
            tp = (std::fabs(np) > eps)?np: tp;
        }
        ret.pt[ret.n ++] = spt[0];
        ret.pt[ret.n ++] = spt[1];
        n = pn;
        return ret;
    }
	static bool graham_cmp(const point &l, const point &r)
    {
        return l.y < r.y || (l.y == r.y && l.x < r.x);
    }
    polygon& graham(point _p[], int _n)
    {
        int i, len;
        std::sort(_p, _p + _n, polygon::graham_cmp);
        n = 1;
        pt[0] = _p[0], pt[1] = _p[1];
        for(i = 2; i < _n; i ++)
        {
            while(n && point::xmult(_p[i], pt[n], pt[n - 1]) > 0)
                n --;
            pt[++ n] = _p[i];
        }
        len = n;
        pt[++ n] = _p[_n - 2];
        for(i = _n - 3; i >= 0; i --)
        {
            while(n != len && point::xmult(_p[i], pt[n], pt[n - 1]) > 0)
                n --;
            pt[++ n] = _p[i];
        }
		for(i=0;i<n;i++)
			inpol[pt[i].id]=true;
        return (*this);
    }
	/*int mindel(const point _p)
	{
		for(int i=0;i<n;i++)
		{
			pVector tmp(_p,pt[i]);
			
	}*/
};
point s[35],p[35];
int n,sp=0,ans=10005;
polygon S;
bool b[35]={0};

void dfs(int pos,int tar)
{
	if(pos==n)
	{
		memset(inpol,0,sizeof(inpol));
		sp=0;
		for(int i=0;i<n;i++)
		{
			if(b[i])s[sp++]=p[i];
		}
		S.graham(s,sp);
		if(inpol[p[tar].id])ans=min(ans,n-sp);
		return;
	}
	if(pos!=tar)
		dfs(pos+1,tar);
	b[pos]=1;
	dfs(pos+1,tar);
	b[pos]=0;
}

int main()
{
freopen("1a-c.in","r",stdin);
freopen("1a-c.out","w",stdout);
	
	ios::sync_with_stdio(false);
	
	int T;
    cin>>T;
	for(int cas=1;cas<=T;cas++)
	{
		memset(inpol,0,sizeof(inpol));
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>p[i].x>>p[i].y;
			p[i].id=i;
		}
		cout<<"Case #"<<cas<<":"<<endl;
		for(int i=0;i<n;i++)
		{
			memset(b,0,sizeof(b));
			sp=0;
			ans=10005;
			dfs(0,i);
			cout<<ans<<endl;
			/*if(inpol[i])cout<<0<<endl;
			else cout<<S.mindel(p[i])<<endl;
			*/
		}
	}
	
	return 0;
}
