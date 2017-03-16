#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
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
    return atan2(lhs.y, lhs.x) < atan2(rhs.y, rhs.x);
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

int place(ll x, ll y) {
    if (x > 0 && y >= 0) return 1;
    if (x <= 0 && y > 0) return 2;
    if (x < 0 && y <= 0) return 3;
    if (x >= 0 && y < 0) return 4;
    puts("bad");
    return -1;
}

bool same(const Point &a, const Point &b) {
    return (a ^ b) == 0 && place(a.x, a.y) == place(b.x, b.y);
}

int main() {
    int Tc, n;
    vector <Point> a, b;
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
                //fprintf(stderr, "Case %d, %d\n", ri, i);
                int minv = n;
                b.clear();
                rep (j, n) {
                    if (i != j) {
                        b.push_back(a[j] - a[i]);
                    }
                }
                bool allSame = true;
                rep (j, b.size()) {
                    if (!same(b[j], b[0])) {
                        allSame = false;
                    }
                }
                if (allSame) {
                    minv = 0;
                } else {
                    sort(b.begin(), b.end(), cmp);
                    vector <Point> c(b);
                    rep (j, c.size()) b.push_back(c[j]);
                    int j = 0, k = 0;
                    int m = c.size();
                    //cout << "m = " << m << endl;
                    while (j < m) {
                        while (j < m && same(b[j + 1], b[j])) j++;
                        if (j == m) break;
                        if (k <= j) k = j + 1;
                        while (k < m + m && (b[j] ^ b[k]) > 0) {
                            k++;
                        }
                        minv = min(minv, k - j - 1);
                        //printf("j = %d, k = %d\n", j, k);
                        j++;
                    }
                }
                printf("%d\n", minv);
            }
        }
    }
    return 0;
}

