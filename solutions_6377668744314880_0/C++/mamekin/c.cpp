#include <cstdio>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <bitset>
#include <numeric>
#include <limits>
#include <climits>
#include <cfloat>
#include <functional>
using namespace std;

class Point
{
public:
    long long y, x;
    Point(){
        y = x = 0;
    }
    Point(long long y0, long long x0){
        y = y0;
        x = x0;
    }
    Point operator+(const Point& p) const{
        return Point(y + p.y, x + p.x);
    }
    Point operator-(const Point& p) const{
        return Point(y - p.y, x - p.x);
    }
    Point operator*(int a) const{
        return Point(y * a, x * a);
    }
    long long dot(const Point& p) const{
        return y * p.y + x * p.x; // |a|*|b|*cosƒÆ
    }
    long long cross(const Point& p) const{
        return x * p.y - y * p.x; // |a|*|b|*sinƒÆ
    }
};

void solve(const vector<Point>& p)
{
    int n = p.size();
    if(n == 1){
        cout << 0 << endl;
        return;
    }

    for(int i=0; i<n; ++i){
        int ans = INT_MAX;
        for(int j=0; j<n; ++j){
            if(i == j)
                continue;

            int a = 0;
            int b = 0;
            for(int k=0; k<n; ++k){
                long long c = (p[j] - p[i]).cross(p[k] - p[i]);
                if(c < 0)
                    ++ a;
                else if(c > 0)
                    ++ b;
            }
            ans = min({ans, a, b});
        }
        cout << ans << endl;
    }
}

int main()
{
    int T;
    cin >> T;

    for(int t=1; t<=T; ++t){
        int n;
        cin >> n;
        vector<Point> p(n);
        for(int i=0; i<n; ++i)
            cin >> p[i].x >> p[i].y;

        cout << "Case #" << t << ':' << endl;
        solve(p);
    }

    return 0;
}