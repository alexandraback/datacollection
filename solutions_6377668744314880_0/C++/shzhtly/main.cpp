#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int maxn = 3005;
const int mod = 100007;
const double inf = 1e100;
const double eps = 1e-6;

struct Point {
	double x, y;
	int no;
	Point() {};
	Point(double x, double y,int no) :x(x), y(y), no(no) {};
	bool operator < (const struct Point &P) const {
		if (fabs(x - P.x)<eps) return y<P.y;
		else return x<P.x;
	}
	Point operator -(const Point& b) const{
		return Point(x - b.x, y - b.y, -1);
	}
	double operator *(const Point &b) const {//外积
		return x*b.y - y*b.x;
	}
	double operator ^(const Point &b) const {//内积
		return x*b.x + y*b.y;
	}
	bool operator ==(const Point &b) const {
		return fabs(b.x - x) < eps && fabs(b.y - y) < eps;
	}
	bool operator !=(const Point &b) const {
		return((*this) == b) == false;
	}
	double dis2(const Point &b) const {//距离平方
		return(x - b.x) *(x - b.x) + (y - b.y) *(y - b.y);
	}
	double dis(const Point &b) const {//距离
		return sqrt((x - b.x) *(x - b.x) + (y - b.y) *(y - b.y));
	}
};

Point base;
int n;
Point p[maxn], st[maxn];
int ans[maxn], mat[maxn];
bool flag[maxn];

bool cmpBYangle(const Point &a, const Point &b){
	if (fabs((a - base)*(b - base))<eps) return base.dis(a)<base.dis(b);
	return ((a - base)*(b - base))>0;
}

double xmult(const Point &ps, const Point &pe, const Point &po) {
	return (ps.x - po.x)*(pe.y - po.y) - (pe.x - po.x)*(ps.y - po.y);//vec2:po-->ps和vec2:po-->pe的叉积
}

int main(){
//	freopen("C-small-attempt1.in", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int T;
	double x, y;
	scanf("%d", &T);
	for (int TT = 1; TT <= T; ++TT){
		scanf("%d", &n);
		base = Point(inf, inf, n);
		for (int i = 0; i < n; ++i){
			scanf("%lf%lf", &x, &y);
			p[i] = Point(x, y, i);
			if (p[i] < base) base = p[i];
		}
		sort(p, p + n, cmpBYangle);
		int top = 0;
		memset(ans, 0, sizeof(ans));
		memset(flag, 0, sizeof(flag));
		for (int i = 0; i < n; ++i){
			while (top >= 2 && xmult(st[top - 1], p[i], st[top - 2]) < -eps){
				flag[st[top - 1].no] = false;
				top--;
			}
			st[top++] = p[i];
			flag[p[i].no] = 1;
		}
		for (int i = 0; i < n; ++i){
			if (flag[p[i].no]) continue;
			int num = n;
			for (int j = 0; j < n; ++j){
				if (j == i) continue;
				int ln = 0;
				int rn = 0;
				for (int k = 0; k < n; ++k){
					if (k == i || k == j) continue;
					double tmp = xmult(p[k], p[j], p[i]);
					if (tmp < -eps) ln++;
					else if (tmp > eps) rn++;
				}
				num = min(num, min(ln, rn));
			}
			ans[p[i].no] = num;
		}
		printf("Case #%d:\n", TT);
		for (int i = 0; i < n; ++i){
			printf("%d\n", ans[i]);
		}
	}
	return 0;
}