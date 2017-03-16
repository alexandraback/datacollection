# include <iostream>
# include <cstdio>
# include <vector>
# include <algorithm>
# include <cstring>
# include <cmath>

using namespace std;

typedef long long LL;

struct point {
    int x ,y;
    point(){}
    point(int _x,int _y):x(_x), y(_y){}
    void read() { scanf("%d%d", &x, &y); }
    point operator-(const point&c) const {
        return point(x - c.x, y - c.y);
    }
    long long operator*(const point&c)const {
        return (LL)x * c.y - (LL)y * c.x;
    }
    bool operator<(const point&c)const {
        return atan2(y, x) < atan2(c.y, c.x);
    }
} a[3200];

vector<point> v;

void solve() {
    int sz = v.size();
    if(sz <= 1) { puts("0"); return; }
    int i = 0, j = 1, cnt = sz - 1;
    while(j < sz && v[i] * v[j] >= 0){ ++j; --cnt;}
    int ans = cnt;
    if(j == sz) { puts("0"); return; }
    for(i = 1; i < sz; ++i) {
        ++cnt;
        while(j != i && v[i] * v[j] >= 0) {
            if(++j == sz) j = 0; --cnt;
        }
        if(j == i) { puts("0"); return; }
        ans = min(ans, cnt);
    }
    printf("%d\n", ans);
}

int n;
int main() {
    freopen("C.in","r",stdin);
    int T; scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        scanf("%d", &n);
        printf("Case #%d:\n", cas);
        for(int i = 0; i < n; ++i) a[i].read();
        for(int i = 0; i < n; ++i) {
            v.clear();
            for(int j = 0; j < n; ++j) if(i!=j) {
                v.push_back(a[i] - a[j]);
            }
            sort(v.begin(), v.end());
            solve();
        }
    }
    return 0;
}

