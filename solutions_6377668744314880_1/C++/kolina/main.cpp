#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#include <cstdlib>
#include <queue>
#include <set>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <bitset>
#include <sstream>
#include <cassert>

using namespace std;

struct point {
    long long x, y;
};

bool compare(const pair<int, point>& a, const pair<int, point>& b) {
    return a.second.x < b.second.x || (a.second.x == b.second.x && a.second.y < b.second.y);
}

bool cross(const point& a, const point& b, const point& c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) <= 0;
}

bool cross_counter(const point& a, const point& b, const point& c) {
    return a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y) >= 0;
}

void convex_hull(vector<pair<int, point> >& a) {
    if (a.size() == 1)
        return;
    sort(a.begin(), a.end(), compare);
    pair<int, point> p1 = a[0], p2 = a.back();
    vector<pair<int, point> > up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (size_t i = 1; i < a.size(); ++i) {
        if (i == a.size() - 1 || cross(p1.second, a[i].second, p2.second)) {
            while (up.size() >= 2 && !cross(up[up.size() - 2].second, up[up.size() - 1].second, a[i].second))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || cross_counter(p1.second, a[i].second, p2.second)) {
            while (down.size() >= 2 && !cross_counter(down[down.size() - 2].second, down[down.size() - 1].second, a[i].second))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
    a.clear();
    for (size_t i = 0; i < up.size(); ++i)
        a.push_back(up[i]);
    for (size_t i = down.size() - 2; i > 0; --i)
        a.push_back(down[i]);
}

long long triangle_area_2(const point& p1, const point& p2) {
    return p1.x * p2.y - p1.y * p2.x;
}

bool clockwise(const point& p1, const point& p2) {
    return triangle_area_2(p1, p2) > 0;
}

bool good(const point& p1, const point& p2) {
    long long r = triangle_area_2(p1, p2);
    if (r >= 0)
        return true;
    //if (r == 0 && p1.x * p2.x + p1.y * p2.y > 0)
    //	return true;
    return false;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        cin >> n;
        vector<pair<int, point> > p(n);
        for (int i = 0; i < n; ++i) {
            cin >> p[i].second.x >> p[i].second.y;
            p[i].first = i;
        }
        vector<pair<int, point> > res(p);
        convex_hull(res);
        vector<bool> inside(n);
        for (int i = 0; i < res.size(); ++i)
            inside[res[i].first] = true;
        cout << "Case #" << t + 1 << ":\n";
        for (int i = 0; i < n; ++i) {
            if (inside[i])
                cout << 0 << "\n";
            else {
                vector<point> v;
                for (int j = 0; j < n; ++j) {
                    if (j != i) {
                        point p1;
                        p1.x = p[j].second.x - p[i].second.x;
                        p1.y = p[j].second.y - p[i].second.y;
                        v.push_back(p1);
                    }
                }
                sort(v.begin(), v.end(), clockwise);
                int cur = 0;
                int ans = n - 1;
                for (int j = 0; j < n - 1; ++j) {
                    if (cur == j)
                        cur = (cur + 1) % (n - 1);
                    while (good(v[j], v[cur]))
                        cur = (cur + 1) % (n - 1);
                    int have = cur - j;
                    if (have < 0)
                        have += n - 1;
                    ans = min(ans, n - 1 - have);
                }
                cout << ans << "\n";
            }
        }
    }
    return 0;
}
