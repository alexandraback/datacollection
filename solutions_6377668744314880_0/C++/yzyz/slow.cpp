#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <vector>
#define MAXN 15

using namespace std;

struct pt {
    long long x,y;
    pt(long long x = 0, long long y = 0) : x(x), y(y) {}
    pt operator + (pt p) { return pt(x + p.x, y + p.y); }
    pt operator - (pt p) { return pt(x - p.x, y - p.y); }
};

long long cross(pt a, pt b) {
    return a.x * b.y - a.y * b.x;
}

long long cross(pt a, pt b, pt c) {
    return cross(a - b, c - b);
}

int n;
pt p[MAXN];
int ans[MAXN];
vector<int> v,h[2];

long long cross(int a, int b, int c) {
    return cross(p[a],p[b],p[c]);
}

bool cmp(int a, int b) {
    if (p[a].x != p[b].x) return p[a].x < p[b].x;
    return p[a].y < p[b].y;
}

void insert(int i, vector<int> &uh) {
    while (uh.size() > 1) {
        int a = uh[uh.size()-2];
        int b = uh.back();
        if (cross(a,b,i) >= 0) break;
        uh.pop_back();
    }
    uh.push_back(i);
}

void calc(int mask) {
    v.clear();
    h[0].clear();
    h[1].clear();
    for (int i = 0; i < n; i++)
        if ((mask >> i) & 1) v.push_back(i);
    sort(v.begin(),v.end(),cmp);
    for (int ul = 0; ul < 2; ul++) {
        for (auto i : v) insert(i,h[ul]);
        for (int i = 0; i < n; i++) p[i].y *= -1;
    }
    int removed = n - __builtin_popcount(mask);
    /*
    if (removed == 0) {
        for (auto i : h[0]) cerr << i << ' '; cerr << endl;
        for (auto i : h[1]) cerr << i << ' '; cerr << endl;
    }
    */
    for (auto i : h[0]) ans[i] = min(ans[i], removed);
    for (auto i : h[1]) ans[i] = min(ans[i], removed);
}

int main() {
    int T;
    cin >> T;
    for (int TC = 1; TC <= T; TC++) {
        cerr << "Testcase " << TC << endl;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> p[i].x >> p[i].y;
            ans[i] = n;
        }
        for (int i = 0; i < (1<<n); i++) {
            calc(i);
        }
        cout << "Case #" << TC << ":\n";
        for (int i = 0; i < n; i++) {
            cout << ans[i] << '\n';
        }
    }
}
