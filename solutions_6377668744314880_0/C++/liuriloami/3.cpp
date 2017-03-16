#include <bits/stdc++.h>
using namespace std;

struct point {
    double x,y;
    point() {x = y = 0.0;}
    point (double _x, double _y) : x(_x), y(_y) {}
    bool operator < (point other) const {
        if (fabs(x-other.x) > 0.0001)
            return x < other.x;
        return y < other.y;
    };
    bool operator == (point other) const {
      return (fabs(x-other.x) < 0.0001 && fabs(y - other.y) < 0.0001);  
    };
} pivot;

double cross(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

point toVec(point a, point b) {
    point res;
    res.x = b.x-a.x;
    res.y = b.y-a.y;
    return res;
}


double collinear(point p, point q, point r) {
    return fabs(cross(toVec(p,q), toVec(p,r))) < 0.00001;
}

double ccw(point p, point q, point r) {
  return cross(toVec(p, q), toVec(p, r)) > 0 || collinear(p,q,r);
}
double dist(point a, point b) {
    return hypot(a.x-b.x, a.y-b.y);
}


bool angleCmp(point a, point b) {
    if (collinear(pivot, a, b)) 
        return dist(pivot, a) < dist(pivot,b);
    double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
    double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
    return atan2(d1y, d1x) - atan2(d2y, d2x) < 0;
}

vector<point> CH(vector<point> P) {
    int i, j, n = (int)P.size();
    if (n <= 3) {
        if (!(P[0] == P[n-1])) P.push_back(P[0]);
        return P;
    }
    
    int P0 = 0;
    for (i = 1; i < n; i++)
        if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
            P0 = i;
    point temp = P[0]; 
    P[0] = P[P0];
    P[P0] = temp;
    pivot = P[0];
    sort(++P.begin(), P.end(), angleCmp);
    vector<point> S;
    S.push_back(P[n-2]);
    S.push_back(P[0]);
    S.push_back(P[1]);
    i = 2;
    while (i < n) {
        j = (int)S.size() - 1;
        if (ccw(S[j-1], S[j], P[i]))
            S.push_back(P[i++]);
        else 
            S.pop_back();
    }
    return S;
}
int main (int argc, char** argv) {
    pivot.x = 0;
    pivot.y = 0;
    int nTests;
    cin >> nTests;
    for (long long int test = 1; test <= nTests; test++) {
        int n;
        cin >> n;
        vector<point> trees;
        for (int i = 0; i < n; i++) {
            point tmp;
            cin >> tmp.x >> tmp.y;
            trees.push_back(tmp);
        }
        vector<point> hull = CH(trees);
        cout << "Case #" << test << ":\n";
        for (int i = 0; i < n; i++) {
            int res = n;
            for (int j = 0; j < hull.size(); j++) {
                if (trees[i] == hull[j]) {
                    res = 0;
                    break;
                }
                for (int k = j+1; k < hull.size(); k++) {
                    if (ccw(hull[j], trees[i], hull[k]) &&
                ccw(hull[(j-1+hull.size())%hull.size()], hull[j],
trees[i]) && ccw(trees[i], hull[k],
trees[(k+1)%hull.size()])) {
                        res = min(res, k-j-1);
}
                }
            }
            if (res == n) res = 0;
            cout << res << endl;
        }
    }
    return 0;
}