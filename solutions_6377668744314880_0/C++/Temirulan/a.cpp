#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define ll long long
#define pii pair < int, int >
#define pll pair < long long, long long>
#define ull unsigned long long
#define y1 stupid_cmath
#define left stupid_left
#define right stupid_right
#define vi vector <int>
#define sz(a) (int)a.size()
#define forit(it, s) for(__typeof(s.begin()) it = s.begin(); it != s.end(); it++)
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x))

const int inf = (int)1e9;
const int mod = inf + 7;
const double eps = 1e-9;
const double pi = acos(-1.0);

struct Point {
    int x, y;
    
    Point () {}
    Point (int x, int y) : x(x), y(y) {}
};

struct Line {
    ll a, b, c;
    
    Line () {}
    Line (Point p, Point q) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = -a * p.x - b * p.y;
    }
    
    int sgn(Point p) {
        ll val = a * p.x + b * p.y + c;
        if(val > 0) return 1;
        if(val < 0) return -1;
        return 0;
    }
};

Point a[200];
int n, ans[200];
int t;

void solve(int num) {
    printf("Case #%d:\n", num);
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int x, y;
        scanf("%d%d\n", &x, &y);
        a[i] = Point(x, y);
        ans[i] = n-1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            int k1 = 0, k2 = 0;
            for(int t = 0; t < n; t++) {
                int s = Line(a[i],a[j]).sgn(a[t]);
                if(s == 1) k1++;
                if(s == -1) k2++;
            }
            ans[i] = min(ans[i], min(k1, k2));
            ans[j] = min(ans[j], min(k1, k2));
        }
    }
    for(int i = 0; i < n; i++) printf("%d\n", ans[i]);
}

int main(){
    
    scanf("%d\n", &t);
    
    for(int i = 1; i <= t; i++) solve(i);
    
    return 0;
}
