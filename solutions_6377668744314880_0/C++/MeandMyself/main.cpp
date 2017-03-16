#include <cstdio>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;


struct pt {
    long long x, y;
};

bool cmp (pt a, pt b) {
    return a.x < b.x || a.x == b.x && a.y < b.y;
}

bool cw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) <= 0;
}

bool ccw (pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) >= 0;
}

vector <pt > convex_hull (vector<pt> & a) {
    if (a.size() == 1)  return a;
    sort (a.begin(), a.end(), &cmp);
    pt p1 = a[0],  p2 = a.back();
    vector<pt> up, down;
    up.push_back (p1);
    down.push_back (p1);
    for (size_t i=1; i<a.size(); ++i) {
        if (i==a.size()-1 || cw (p1, a[i], p2)) {
            while (up.size()>=2 && !cw (up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back (a[i]);
        }
        if (i==a.size()-1 || ccw (p1, a[i], p2)) {
            while (down.size()>=2 && !ccw (down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back (a[i]);
        }
    }
    // a.clear();
    vector <pt>b;
    for (size_t i=0; i<up.size(); ++i)
        b.push_back (up[i]);
    for (size_t i=down.size()-2; i>0; --i)
        b.push_back (down[i]);
    return b;
}

int main() {
    cin.tie(NULL);
    std::ios_base::sync_with_stdio(0);
    int t;

    fstream in;
    in.open ("//Users//Roman//Desktop//Contest//C_small.in.txt", std::fstream::in);
    fstream out;
    out.open ("//Users//Roman//Desktop//Contest//C_small.txt", std::fstream::in | std::fstream::out | std::fstream::app);

    //cin >> t;

    in >> t;
    //cout << t;
    for (int tt = 0; tt < t; ++tt){
        long long n, m;
        in >>  n;
        vector <pt> x(n);

        for (int i = 0; i < n; ++i){
            in >> x[i].x >> x[i].y;
        }

        /*for (int i = 0; i < t; ++i){
            cout <<  x[i].x << " " <<  x[i].y << endl;
        }*/

        vector < int > ans (n, n + 1);
        vector < pt > y;
        y.reserve(n*2);
        for (int i = 0; i < n; ++i) {
            for (int mask = 0; mask < 33000; ++mask) {
                y.push_back(x[i]);
                int my_mask = mask;
                for (int k = 0; k < n; ++k) {
                    if (k != i && my_mask%2 == 1) {
                        y.push_back(x[k]);
                    }
                    my_mask /= 2;
                }
                if (n - y.size() < ans[i]) {
                    vector<pt> check = convex_hull(y);
                    for (int k = 0; k < check.size(); ++k) {
                        if (check[k].x == x[i].x && check[k].y == x[i].y) {
                            ans[i] = n - y.size();
                        }
                    }
                }
                y.clear();
            }
        }


        out << "Case #" << tt + 1 << ":\n";
        for (int i = 0; i < ans.size(); ++i) {
            out << ans[i] << "\n";
        }
        // cout << end << endl;
    }
    return 0;
}