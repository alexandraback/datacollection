#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>
#include <cmath>

using namespace std;

typedef long long ll;

const int N = 3010;

struct Point
{
	long long x, y;
	Point(){}
	Point(long long _x, long long _y): x(_x), y(_y) {}
	Point operator + (const Point &o) const {return Point(x + o.x, y + o.y);}
	Point operator - (const Point &o) const {return Point(x - o.x, y - o.y);}
	Point operator * (long long o) {return Point(x * o, y * o);}
	Point operator / (long long o) {return Point(x / o, y / o);}
	long long dot(const Point &o) const {return x * o.x + y * o.y;}
	long long det(const Point &o) const {return x * o.y - y * o.x;}
	void read() {scanf("%lld%lld", &x, &y);}
	void show() {cout << x << ' ' << y << endl;}
};// 2D_Geo_Point

int ans[N], n;
Point p[N], q[N];
Point origin;

bool cmp(const Point& p1, const Point& p2)
{
    return atan2(p1.y - origin.y, p1.x - origin.x) < atan2(p2.y - origin.y, p2.x - origin.x);
}

int main(){
    int _, cas = 1;
    for(scanf("%d", &_); _--; ){
        printf("Case #%d:\n", cas++);
        scanf("%d", &n);
        for(int i = 0; i < n; ++i) p[i].read(), ans[i] = n - 1;

        for (int i = 0; i < n; ++i){
            origin = p[i];
            int nn = 0;
            for(int j = 0; j < n; ++j) if(i != j) q[nn++] = p[j];
            sort(q, q + nn, cmp);
            for(int j = 0, jj = 0; j < nn; ++j){
                while((q[j] - origin).det(q[(jj + 1) % nn] - origin) > 0) jj = (jj + 1) % n;
                int tmp = jj - j;
                if(tmp < 0) tmp += nn;
                ans[i] = min(ans[i], tmp);
            }
        }
        for(int i = 0; i < n; ++i) printf("%d\n", ans[i]);
    }
    return 0;
}