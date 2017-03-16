//#include "testlib.h"

#include <iostream>
#include <math.h>
#include <map>
#include <vector>
#include <stdlib.h>
#include <memory.h>
#include <time.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <cassert>
#include <queue>

using namespace std;

int x[20];
int y[20];
int ans[20];


    typedef pair<long long, long long> point;
    
    bool cw(const point &a, const point &b, const point &c) {
        return (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first) < 0;
    }
    
    vector<point> convexHull(vector<point> p) {
        int n = (int)p.size();
        if (n <= 3)
            return p;
        int k = 0;
        sort(p.begin(), p.end());
        vector<point> q(n * 2);
        for (int i = 0; i < n; q[k++] = p[i++])
            for (; k >= 2 && !cw(q[k - 2], q[k - 1], p[i]); --k)
                ;
        for (int i = n - 2, t = k; i >= 0; q[k++] = p[i--])
            for (; k > t && !cw(q[k - 2], q[k - 1], p[i]); --k)
                ;
        q.resize(k - 1 - (q[0] == q[1]));
        return q;
    }

bool on_line(point x, point a, point b) {
    return a.first * (b.second - x.second) - b.first * (a.second - x.second) + x.first * (a.second - b.second) == 0;
}

int main() {
    ios::sync_with_stdio(0);
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    
    int TT; cin >> TT;
    for(int t = 1; t <= TT; ++t) {
        int n;
        cin >> n;
        for(int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
            ans[i] = n-1;
        }
        
        for(int m = 0; m < (1 << n); ++m) {
            
            vector<point> v;
            int cc = 0;
            for(int i = 0; i < n; ++i)
            if ((m >> i) % 2)
                v.push_back(make_pair(x[i], y[i]));
            else
                cc++;
            
            v = convexHull(v);
            for(int i = 0; i < n; ++i) if ((m >> i) % 2) {
                bool fnd = 0;
                for(int j = 0; !fnd && j < v.size(); ++j)
                if ((v[j].first == x[i] && v[j].second == y[i]) ||
                    on_line(make_pair(x[i], y[i]), v[j], v[(j+1)%v.size()]))
                    fnd = 1;
                
                if (fnd)
                    ans[i] = min(ans[i], cc);
            }
            
            
        }
        
        cout << "Case #" << t << ":\n";
        for(int i = 0; i < n; ++i)
            cout << ans[i] << "\n";
    }
    return 0;
}