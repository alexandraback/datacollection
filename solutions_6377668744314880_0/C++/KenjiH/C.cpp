#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define EACH(itr,c) for(__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); itr++)  
#define FOR(i,b,e) for (int i=(int)(b); i<(int)(e); i++)
#define MP(x,y) make_pair(x,y)
#define REP(i,n) for(int i=0; i<(int)(n); i++)

struct Point {
    long long x, y;
    Point() {}
    Point(long long x, long long y) : x(x), y(y) {}
    
    bool operator ==(const Point &p) const {
        return x == p.x && y == p.y;
    }

    Point operator +(const Point &p) const {
        return Point(x + p.x, y + p.y);
    }
    Point operator -(const Point &p) const {
        return Point(x - p.x, y - p.y);
    }
    long long det(const Point &p) {
        return x * p.y -y * p.x;
    }
};

bool cmp(const Point& p, const Point& q) {
    if (p.x != q.x) 
        return p.x < q.x;

    return p.y < q.y;
}

vector<Point> convex_hull(vector<Point> ps) {
    
    int n = ps.size();
    sort(ps.begin(), ps.end(), cmp);
    
    int k = 0;
    vector<Point> qs(n * 2);

    for (int i = 0; i < n; i++) {
        while (k > 1 && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) < 0) 
            k--;
        qs[k++] = ps[i];
    }

    for (int i = n - 2, t = k; i >= 0; i--) {
        while (k > t && (qs[k - 1] - qs[k - 2]).det(ps[i] - qs[k - 1]) < 0) 
            k--;
        qs[k++] = ps[i];
    }
    qs.resize(k - 1);

    return qs;
}

int N;
Point p[15];

int calc(int v) {

    if (N < 3)
        return 0;

    int ret = 100;
    for (int mask = 0; mask < 1<<N; mask++) {
        if (!(mask & 1<<v))
            continue;

        vector<Point> ps;
        REP (i, N) if (mask & 1<<i) ps.push_back(p[i]);
        
        vector<Point> qs = convex_hull(ps);
        bool ck = false;
        REP (i, qs.size()) {
            ck |= qs[i] == p[v];
        }

        if (ck)
            ret = min(ret, N - __builtin_popcount(mask));

    }

    return ret;
}

void solve() {
    cin >> N;
    REP (i, N) {
        int x, y;
        cin >> x >> y;
        p[i] = Point(x,y);
    }

    cout << endl;
    REP (i, N) {
        cout << calc(i) << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int T;
    cin >> T;
    REP (i, T) {
        cerr << "Case #" << i+1 << ": " << endl;
        cout << "Case #" << i+1 << ": ";
        solve();
    }

    return 0;
}
