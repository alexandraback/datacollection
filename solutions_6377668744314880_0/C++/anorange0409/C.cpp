#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int a[10000], n, m, top;
const int Max = 100;
int x[10000],y[10000];
int result[1000];
struct Point{
    long long x, y;
    Point(int xx, int yy) {
        x = xx;
        y = yy;
    }
    Point(){}
}p[Max];
int res[Max];
Point re[Max];

bool cmp(Point a, Point b){
    if(a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

bool mult(Point sp, Point ep, Point op){
    return (sp.x-op.x)*(ep.y-op.y) >= (ep.x-op.x)*(sp.y-op.y);
}

long long sqr(long long x){
    return x*x;
}
long long dis(Point &a, Point &b) {
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

void Graham(){
    int i, len;
    top = 1;
    sort(p, p+n, cmp);
    for(i = 0; i < 3; i ++) res[i] =i;
    for(i = 2; i < n; i ++){
        while(top && mult(p[i], p[res[top]], p[res[top-1]])) top --;
        res[++ top] = i;
    }
    len = top;
    res[++ top] = n - 2;
    for(i = n - 3; i >= 0; i --){
        while(top != len && mult(p[i], p[res[top]], p[res[top-1]])) top --;
        res[++ top] = i;
    }
    for (int i = 0; i < top; i++)
        re[i] = p[res[i]];
}

bool eq(Point &a, Point &b){
    return a.x==b.x&&a.y==b.y;
}
bool in(Point &p, Point &x, Point &y) {
    if (eq(p,x)||eq(p,y)) return true;
    double d = dis(x,y);
    double d1 = dis(p,x);
    double d2 = dis(p,y);
    if ( abs(d1+d2-d ) < 1e-6) return true;
    else return false;

}

bool ok(Point p) {
    for (int i = 1; i < top; i++)
        if (in(p, re[i-1],re[i])) return true;
    if (in(p, re[0], re[top-1])) return true;
    return false;
}
void check() {
    n=0;
    for (int i = 0; i < m; i++)
        if (a[i]) {
            p[n++] = Point(x[i],y[i]);
        }
    if (n == 0) return;
    Graham();
    int upd = m-n;
    for (int i = 0; i < m; i++)
        if (a[i] && ok(Point(x[i],y[i])))
            result[i] = min(result[i], upd);
}

void dfs(int t) {
    if (t >= m) check(); else
    {
        a[t] = 1;
        dfs(t+1);
        a[t] = 0;
        dfs(t+1);
    }
}

int main()
{
    freopen("C-small-attempt1.in", "r",stdin);
    freopen("C-small.out", "w",stdout);
    int T;
    cin >> T;
    for (int o = 1; o <= T; o++)
    {
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> x[i] >> y[i];
            result[i] = 100;
        }
        dfs(0);
        printf("Case #%d:\n",o);
        for (int i = 0; i < m; i++)
            cout << result[i] << endl;
    }
}
