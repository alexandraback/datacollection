#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <deque>
#include <sstream>
#include <iomanip>
using namespace std;
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair <int, int> PII;

struct Point {
    ll x, y;
    int id;

    Point(ll x, ll y, int id): x(x), y(y), id(id) {}

    bool operator < (const Point &oth) const {
        return x < oth.x || (x == oth.x && y < oth.y);
    }

    Point operator - (const Point &oth) const {
        return Point(x - oth.x, y - oth.y, id);
    }

    Point operator + (const Point &oth) const {
        return Point(x + oth.x, y + oth.y, id);
    }    

    ll operator ^ (const Point &oth) const {
        return x * oth.y - y * oth.x;
    }

    ll size() const {
        return x * x + y * y;
    }
};

bool cmp(const Point &lhs, const Point &rhs) {
    return (lhs ^ rhs) > 0 || ((lhs ^ rhs) == 0 && lhs.size() < rhs.size());
}

vector <Point> convex(vector <Point> a) {
    int n = a.size();
    if (n <= 2) return a;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[0]) {
            swap(a[i], a[0]);
        }
    }
    Point base = a[0];
    for (int i = 1; i < n; i++) {
        a[i] = a[i] - a[0];
    }
    a[0] = a[0] - a[0];
    sort(a.begin() + 1, a.end(), cmp);
    vector <Point> res;
    res.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        while (res.size() >= 2 
            && ((a[i] - res[res.size() - 2]) ^ (res.back() - res[res.size() - 2])) >= 0
            ) {
            res.pop_back();
        }
        res.push_back(a[i]);
    }
    return res;
}

int main() {
    int Tc, n;
    vector <Point> a;
    scanf("%d", &Tc);
    rep (ri, Tc) {
        printf("Case #%d:\n", ri + 1);
        a.clear();
        scanf("%d", &n);
        rep (i, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            a.push_back(Point(x, y, i));
        }
        if (n <= 2) {
            rep (i, n) puts("0");
        } else {
            rep (i, n) {
                int minv = n;
                rep (j, n) {
                    if (i != j) {
                        int lhs = 0, mid = 0, rhs = 0;
                        rep (k, n) {
                            ll value = (a[k] - a[i]) ^ (a[j] - a[i]);
                            if (value < 0) {
                                lhs++;
                            } else if (value == 0) {
                                mid++;
                            } else {
                                rhs++;
                            }
                        }
                        minv = min(minv, min(lhs, rhs));
                    }
                }
                printf("%d\n", minv);
            }
        }
    }
    return 0;
}

