#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct point
{
    long long x, y;
    point(int _x, int _y)
    {
        x = _x;
        y = _y;
    }
    point() {}
};

istream& operator>>(istream& is, point& p)
{
    is >> p.x >> p.y;
    return is;
}

bool operator<(const point& p1, const point& p2)
{
    if (p1.x != p2.x)
        return p1.x < p2.x;
    else
        return p1.y < p2.y;
}

bool operator==(const point& p1, const point& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

bool operator!=(const point& p1, const point& p2)
{
    return !(p1 == p2);
}

struct vect
{
    long long x, y;
    vect(point a, point b)
    {
        x = b.x - a.x;
        y = b.y - a.y;
    }
    long long sq_len()
    {
        return x * x + y * y;
    }
};

long long cp(vect u, vect v)
{
    return u.x * v.y - v.x * u.y;
}

long long dp(vect u, vect v)
{
    return u.x * v.x + u.y * v.y;
}

long long sq_point_distance(point a, point b)
{
    return vect(a, b).sq_len();
}

class compare
{
    point first;
  public:
    compare(point _first)
    {
        first = _first;
    }
    bool operator() (const point& p1, const point& p2)
    {
        if (cp(vect(first, p1), vect(first, p2)) == 0)
            return vect(first, p1).sq_len() < vect(first, p2).sq_len();
        else
            return cp(vect(first, p1), vect(first, p2)) > 0;
    }
};

vector<point> convex(const vector<point>& vec)
{
    int n = vec.size();
    if (n <= 2)
        return vec;
    point first = vec[0];
    for (int i = 1; i < n; i++)
        if (vec[i] < first)
            first = vec[i];
    vector<point> pts = vec;
    sort(pts.begin(), pts.end(), compare(first));
    vector<point> res;
    if (pts.size() >= 2)
    {
        pts.push_back(pts[0]);
        res = {pts[0], pts[1]};
        for (int i = 2; i < n + 1; i++)
        {
            while (res.size() >= 2 && cp(vect(res[res.size() - 1], res[res.size() - 2]), vect(res[res.size() - 1], pts[i])) >= 0)
            {
                if (cp(vect(res[res.size() - 2], res[res.size() - 1]), vect(res[res.size() - 1], pts[i])) == 0)
                {
                   if (dp(vect(res[res.size() - 2], res[res.size() - 1]), vect(res[res.size() - 1], pts[i])) < 0)
                       break;
                }
                res.pop_back();
            }
            res.push_back(pts[i]);
        }
    }
    else
        res = pts;
    return res;
}

bool is_point_in_segment(point p, point a, point b)
{
    return cp(vect(p, a), vect(p, b)) == 0 && dp(vect(p, a), vect(p, b)) <= 0;
}

bool is_point_in_border(point p, vector<point>& poly)
{
    if (poly[0] != poly[poly.size() - 1])
        poly.push_back(poly[0]);
    int n = poly.size();
    for (int i = 0; i < n; i++)
        if (is_point_in_segment(p, poly[i], poly[i - 1]))
            return true;
    return false; 
}

vector<int> solve(int n, vector<point>& pts)
{
    vector<vector<point> > convexes_of_subsets(1 << n);
    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<point> to_convex;
        for (int i = 0; i < n; i++)
            if ((mask >> i) & 1)
                to_convex.push_back(pts[i]);
        convexes_of_subsets[mask] = convex(to_convex);
    }
    //cerr << "Botva" << endl;
    vector<int> ans(n, 1791791791);
    for (int i = 0; i < n; i++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
            if (((mask >> i) & 1) && is_point_in_border(pts[i], convexes_of_subsets[mask]))
                ans[i] = min(ans[i], n - __builtin_popcount(mask));
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        vector<point> pts(n);
        for (int j = 0; j < n; j++)
            cin >> pts[j];
        vector<int> ans = solve(n, pts);
        cout << "Case #" << i + 1 << ":" << endl;
        for (int c : ans)
            cout << c << endl;
    }
    return 0;
}
