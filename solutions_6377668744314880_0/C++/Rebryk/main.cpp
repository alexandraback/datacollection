#include <iostream>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string.h>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int T, n;

struct point {
    long long x, y;
};

long long f(point a, point b, point c) {
    return (long long)a.x*((long long)b.y-(long long)c.y)+(long long)b.x*((long long)c.y-(long long)a.y)+(long long)c.x*((long long)a.y-(long long)b.y);
}

vector < int > g, up, down;
point p[100];
int ans[100];

long long f(int a, int b, int c) {
    return f(p[a], p[b], p[c]);
}

bool cmp( point a, point b ) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmpInt(int a, int b) {
    return cmp(p[a], p[b]);
}

void convex(int mask) {
    g.resize(0);
    down.resize(0);
    up.resize(0);
    
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (mask & (1 << i))
            g.push_back(i), ++cnt;
    
    cnt = n - cnt;
    
    sort(g.begin(), g.end(), cmpInt);
    if (g.size() <= 3)
        return;

    int p1, p2;
    p1 = g[0];
    p2 = g.back();
    
    up.push_back(p1);
    down.push_back(p1);
    
    for (int i = 1; i < g.size(); ++i) {
        if (i == g.size() - 1 || f(p1, g[i], p2) <= 0) {
            while (up.size() >= 2 && f(up[up.size() - 2], up[up.size() - 1], g[i]) > 0)
                up.pop_back();
            up.push_back (g[i]);
        }
        
        if (i == g.size() - 1 || f(p1, g[i], p2) >= 0) {
            while (down.size() >= 2 && f(down[down.size() - 2],down[down.size() - 1], g[i]) < 0)
                down.pop_back();
            down.push_back (g[i]);
        }
    }
    
    for (int i = 0; i < up.size(); ++i)
        ans[up[i]] = min(ans[up[i]], cnt);
    
    for (int i = 0; i < down.size(); ++i)
        ans[down[i]] = min(ans[down[i]], cnt);
    
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n;
        
        for (int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y;
        
        for (int i = 0; i < n; ++i)
            ans[i] = max(0, n - 3);
        
        for (int i = 0; i < (1 << n); ++i)
            convex(i);
        
        cout << "Case #" << t << ":" << endl;
        for (int i = 0; i < n; ++i)
            cout << ans[i] << endl;
    }
}