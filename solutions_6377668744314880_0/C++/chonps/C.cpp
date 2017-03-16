#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#define sqr(x) ((x) * (x))

using namespace std;

typedef long long LL;

const int maxn = 6666;
const double eps = 1e-8;

struct Point{
	long long x, y;
	int xx;
}p[maxn];

Point operator + (Point u, const Point &v){
	u.x += v.x;
	u.y += v.y;
	return u;
}

Point operator - (Point u, const Point &v){
	u.x -= v.x;
	u.y -= v.y;
	return u;
}

long long operator * (const Point &u, const Point &v){
	return u.x * v.y - u.y * v.x;
}

long long operator ^ (const Point &u, const Point &v){
	return u.x * v.x + u.y * v.y;
}

int Sgn(double u){
	return u < -eps? -1: u > eps;
}

int getxx (const Point &u){
	if (u.x > 0LL && u.y >= 0LL) return 1;
	if (u.x <= 0LL && u.y > 0LL) return 2;
	if (u.x < 0LL && u.y <= 0LL) return 3;
	if (u.x >= 0LL && u.y < 0LL) return 4;
	return 0;
}

double getLen(const Point &u, const Point &v){
	return sqrt(sqr(u.x - v.x) + sqr(u.y - v.y));
}

Point center;
vector<Point> vec;

bool cmp(const Point &u, const Point &v){
	return u.xx < v.xx || u.xx == v.xx && u * v > 0LL || u.xx == v.xx && u * v == 0LL && abs(u.x) < abs(v.x);
}

int main(){
	int T;
	scanf("%d", &T);
	for (int TI = 1; TI <= T; ++TI){
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i){
			scanf("%lld%lld", &p[i].x, &p[i].y);
			p[i].xx = getxx(p[i]);
		}
		printf("Case #%d:\n", TI);
		for (int i = 1; i <= n; ++i){
			center = p[i];
			vec.clear();
			for (int j = 1; j <= n; ++j)
				if (i != j){
					vec.push_back(p[j] - center);
					vec[vec.size() - 1].xx = getxx(p[j] - center);
				}
			sort(vec.begin(), vec.end(), cmp);
			center = p[i] - p[i];
			for (int j = 0, m = (int)vec.size(); j < m; ++j)
				vec.push_back(vec[j]);
			int N = (n - 1) << 1;
			int ans = n - 1;
			for (int L = 0, R = 0; L < n - 1; ++L){
				for (; R - L + 1 < n && R < N && (center - vec[R]) * (vec[L] - vec[R]) >= 0; ++R);
				--R;
				ans = min(ans, (n - 1) - (R - L + 1));
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
