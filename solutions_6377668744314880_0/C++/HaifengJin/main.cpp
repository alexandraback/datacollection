#include <cstdio>
#include <algorithm>
using namespace std;

#define zero(x) (((x)>0?(x):-(x))<eps)
#define eps 1.0E-8
#define MAX_POINT_NUM 0
#define D(x) 

int double_cmp(double a)
{
	if (zero(a))
		return 0;
	return a > 0 ? 1 : -1;
}

const int MAX_N = 20;
const int INF = 0x3f3f3f3f;

struct point { double x, y;

	point()
	{}
	point(double x, double y):x(x), y(y)
	{}
	point operator - (point &a)
	{
		return point(x - a.x, y - a.y);
	}	
};

bool mult(point sp, point ep, point op){
	return (sp.x - op.x) * (ep.y - op.y)
		>= (ep.x - op.x) * (sp.y - op.y);
}

bool operator < (const point &l, const point &r){
	return l.y < r.y || (l.y == r.y && l.x < r.x);
}

int graham(point pnt[], int n, point res[]){
	int i, len, top = 1;
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
	return top;
	// 返回凸包中点的个数
}

point pnt[MAX_N];
int ans[MAX_N];
int n;
int convex_num;
point res[MAX_N];

struct Line
{
	point a, b;
	Line()
	{}
	Line(point a, point b):a(a), b(b)
	{}	
};

double cross_product(point a, point b)
{
	return a.x * b.y - b.x * a.y;
}
double cross_product(point p0, point p1, point p2)
{
	return cross_product(p1 - p0, p2 - p0);
}
double dot_product(point a, point b)
{
	return a.x * b.x + a.y * b.y;
}

double dot_product(point p0, point p1, point p2)
{
	return dot_product(p1 - p0, p2 - p0);
}

bool point_online_inclusive(point p, Line l)
{
	D(printf("%d %.2f\n",zero(cross_product(p, l.a, l.b)), dot_product(p, l.a, l.b)));
	return double_cmp(zero(cross_product(p, l.a, l.b))) && double_cmp(dot_product(p, l.a, l.b)) <= 0;
}

bool on_convex(point a)
{
	for (int i = 0; i < convex_num; i++)
		if (res[i].x == a.x && res[i].y == a.y)
			return true;
	for (int i = 0; i < convex_num; i++)
	{
		point p1 = res[i];
		point p2 = res[(i + 1) % convex_num];
		D(printf("%.2f %.2f %.2f\n", p1.y, p2.y, a.y));
		if (point_online_inclusive(a, Line(p1, p2)))
			return true;
	}
	return false;
}

void update(int bits, int num)
{
	int j = 0;
	while (bits > 0)
	{
		if (bits & 1 && on_convex(pnt[j]))
		{
			ans[j] = min(ans[j], num);
		}
		bits >>= 1;
		j++;
	}
}

void output()
{
	for (int i = 0; i < n; i++)
	{
		printf("%d\n", ans[i]);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		case_num++;
		printf("Case #%d:\n", case_num);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%lf%lf", &pnt[i].x, &pnt[i].y);
		}
		for (int i = 0; i < n; i++)
			ans[i] = INF;
		for (int i = 0; i < (1 << n); i++)
		{
			point temp[MAX_N];
			int top = 0;
			int bits = i;
			int j = 0;
			while (bits > 0)
			{
				if (bits & 1)
					temp[top++] = pnt[j];
				bits >>= 1;
				j++;
			}
			D(printf("**%d\n", top));
			convex_num = graham(temp, top, res);
			update(i, n - top);
		}
		output();
	}
	return 0;
}
