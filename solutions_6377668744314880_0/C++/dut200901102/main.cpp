#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <map>

using namespace std;

typedef long long ll;

const int N = 1010;
const int mod = 100007;

struct Point
{
	ll x, y;
    int index;
	Point(){}
	Point(ll _x, ll _y): x(_x), y(_y) {}
	Point operator + (const Point &o) const {return Point(x + o.x, y + o.y);}
	Point operator - (const Point &o) const {return Point(x - o.x, y - o.y);}
	Point operator * (int o) {return Point(x * o, y * o);}
	Point operator / (int o) {return Point(x / o, y / o);}
	ll det(const Point &o) const {return x * o.y - y * o.x;}
	void read() {scanf("%lld%lld", &x, &y);}
	void show() {cout << x << ' ' << y << endl;}
};// 2D_Geo_Point

int ans[N];
int tot;
Point p[N], sub[N];

bool cmp(Point x, Point y){
    if(x.y == y.y) return x.x < y.x;
    return x.y < y.y;
}
void convex(Point p[], int s[], int& top, int &n)
{
    // for(int i = 0; i < n; ++i) cout << p[i].index << ' ';
    // cout << endl;
	top = 1;
	sort(p, p + n, cmp);
	s[0] = 0; if(n == 1) {s[1] = 0; return ;}
	s[1] = 1; if(n == 2) {s[2] = 0; top = 2; return ;}
	for(int i = 2; i < n; ++i)
	{
		while(top && (p[i]-p[s[top - 1]]).det(p[s[top]]-p[s[top - 1]]) > 0) top--;
		s[++top] = i;
	}
	int len = top;
	for(int i = n - 2; i >= 0; --i)
	{
		while(top != len && (p[i] - p[s[top-1]]).det(p[s[top]] - p[s[top -1]]) > 0) top--;
		s[++top] = i;
	}
    
    // for(int i = 0; i <= top; ++i) cout << p[s[i]].index << ' '; cout << endl;
    
    // cout << "-----------" << endl;

}

int main(){    
    int _, cas = 1;
    for(scanf("%d", &_); _--; ){
        printf("Case #%d:\n", cas++);
        scanf("%d", &tot);
        for(int i = 0; i < tot; ++i) p[i].read(), p[i].index = i, ans[i] = tot;
        
        int mask = 1 << tot;
        for(int i = 1; i < mask; ++i){
            int s[N], top, nn = 0;
            for(int j = 0; j < tot; ++j) if(i >> j & 1) sub[nn++] = p[j];
            convex(sub, s, top, nn);
            for(int i = 0; i <= top; ++i){
                int cur = sub[s[i]].index;
                ans[cur] = min(ans[cur], tot - nn);
            }
        }
        for(int i = 0; i < tot; ++i) printf("%d\n", ans[i]);
    }
    return 0;
}