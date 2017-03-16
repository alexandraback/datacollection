#include <iostream>

using namespace std;
class point
{
public:
    double x, y;
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

void convex(P p[], int s[], int& top, int &n)
{
	top = 1;
	sort(p, p + n);
	n = unique(p, p + n) - p;
	s[0] = 0; if(n == 1) {s[1] = 0; return ;}
	s[1] = 1; if(n == 2) {s[2] = 0; top = 2; return ;}
	for(int i = 2; i < n; ++i)
	{
		while(top && sign((p[i]-p[s[top - 1]]).det(p[s[top]]-p[s[top - 1]])) >= 0) top--;
		s[++top] = i;
	}
	int len = top;
	for(int i = n - 2; i >= 0; --i)
	{
		while(top != len && sign((p[i] - p[s[top-1]]).det(p[s[top]] - p[s[top -1]])) >= 0) top--;
		s[++top] = i;
	}
}
struct P
{
    double x, y, r;
};
int a[3009];
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; ++cas)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
        {
            scanf("%lf%lf",m &x, &y);
        }
        convex(P, a, n, 1);
        printf("Case #d:\n", cas);
        for (int i = 1; i <= n; ++i)
        {
            printf("%d\n", a[i]);
        }
    }
    return 0;
}
