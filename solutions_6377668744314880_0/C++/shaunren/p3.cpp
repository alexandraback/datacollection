#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <algorithm>
#include <functional>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stdint.h>
using namespace std;

struct point_t {
    int64_t x,y;
    point_t(int64_t a=0, int64_t b=0) : x(a), y(b) {}
    bool operator<(const point_t& p) const {
        int64_t d = (x*p.y - p.x*y);
        return d!=0 ? (d > 0) : (x*x + y*y < p.x*p.x + p.y*p.y);
    }
    point_t& operator=(const point_t& p) {
        x = p.x;
        y = p.y;
        //t = p.t;
        return *this;
    }
};
#define DIR(p0,p1,p2) (((p2).x-(p0).x)*((p1).y-(p0).y)-((p1).x-(p0).x)*((p2).y-(p0).y))

inline vector<point_t> graham_scan(const vector<point_t>& ps, int lo, int hi) // ps processed with minimum y-value point shifted to (0,0)
{
    //sort(ps.begin(), ps.end());
    vector<point_t> s;
    s.push_back(point_t());
    s.push_back(ps[lo]);
    if (lo+1 > hi) return s;
    s.push_back(ps[lo+1]);
    for (int i=lo+2;i<=hi;i++) {
        while (DIR(s[s.size()-2],s.back(),ps[i]) > 0) s.pop_back();
        s.push_back(ps[i]);
    }
    
    return s;
}


__attribute__((optimize("-O3")))
int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(0);

    int tcas;
    cin >> tcas;
    for (int cas=1;cas<=tcas;cas++) {
        int n;
        cin >> n;
        vector<point_t> points;
        
        point_t mp = point_t(1000000000000,10000000000000);
        for (int i=0;i<n;i++) {
            point_t p;
            cin >> p.x >> p.y;
            points.push_back(p);
            if (p.y < mp.y || (p.y == mp.y && p.x<mp.x)) mp = p;
        }

        cout<< "Case #" << cas << ":\n";
        if (n<4) {
            for (int i=0;i<n;i++) {cout << "0\n";}
            continue;
        }
        
        vector<point_t> ps;
        for (int i=0;i<n;i++) {
            points[i].x -= mp.x;
            points[i].y -= mp.y;
            if (points[i].x!=0 || points[i].y!=0) ps.push_back(points[i]);
        }
        //cerr << ps.size() << endl;
        sort(ps.begin(),ps.end());
        vector<point_t> conv = graham_scan(ps,0,ps.size()-1);
        conv.push_back(point_t());
        
        //cerr << "ps: " << ps.size() << ", " << "Conv: " << conv.size() << "\n";
        for (int i=0;i<n;i++) {
            for (auto p : conv) {
                if (p.x == points[i].x && p.y == points[i].y) {
                    cout << "0\n";
                    goto end;
                }
            }
            for (int j=0;j<conv.size()-1;j++) {
                point_t a = conv[j], b = conv[j+1];
                if (DIR(a,points[i],b) == 0 && min(a.x,b.x) <= points[i].x && points[i].x <= max(a.x,b.x) && min(a.y,b.y) <= points[i].y && points[i].y <= max(a.y,b.y)) {
                    cout << "0\n";
                    goto end;
                }
            }
            int j;
            for (j=0;j<ps.size();j++) {
                if (ps[j].x == points[i].x && ps[j].y == points[i].y) break;
            }
            
            cout << min(graham_scan(ps, 0, j).size(), graham_scan(ps, j, ps.size()-1).size())-2 << '\n';
        end: 0;
        }
    }
    
    return 0;
}










