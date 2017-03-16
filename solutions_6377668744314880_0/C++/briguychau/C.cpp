#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <complex>
#include <map>

#define PI 3.14159265358979323

using namespace std;

typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<double> vd;

int values[16];

struct comp {
    bool operator() (const pt & a, const pt & b) const {
        return a.imag() < b.imag() || (a.imag() == b.imag() && a.real() < b.real());
    }
};

bool pteq(const pt &a, const pt &b) {
    return a.real() == b.real() && a.imag() == b.imag();
}

ld cp(const pt &a, const pt &b) { return imag(conj(a)*b); }
inline bool cmp_lex_i(const pt &a, const pt &b)
{ return a.imag() < b.imag() || (a.imag() == b.imag() && a.real() < b.real()); }

typedef map<pt, int, comp> mpi;

pol chull(pol p) { // change <= 0 to < 0 to find collinear convex hull points
    sort(p.begin(), p.end(), cmp_lex_i); int top=0, bot=1; pol ch(2*p.size());
    for (int i=0, d=1; i < p.size() && i >= 0; i += d) {
        while (top > bot && cp(ch[top-1]-ch[top-2], p[i]-ch[top-2]) < 0) top--;
        ch[top++] = p[i]; if (i == p.size()-1) d = -1, bot = top;
    }
    ch.resize(max(1, top-1));
    return ch;
} // pts returned in ccw order.

void solve(int kase) {
    printf("Case #%d:\n", kase);
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        values[i] = -1;
    }

    pol points;
    mpi ptmap;

    for (int i = 0; i < n; ++i) {
        int x, y;
        scanf("%d %d", &x, &y);
        pt curr(1.0 * x, 1.0 * y);
        points.push_back(curr);
        ptmap[curr] = i;
    }

    pol convhull = chull(points);

    for (int i = 0; i < convhull.size(); ++i) {
        pt curr = convhull[i];
        int index = ptmap[curr];
        //printf("\tindex %d\n", index);
        values[index] = 0;
    }

    for (int ii = 0; ii < n; ++ii) {
        if (values[ii] == -1) {
            pt currpoint = points[ii];
            // need to determine angle of each point in relation to current point
            vd angles;
            for (int i = 0; i < n; ++i) {
                if (i == ii) continue;
                pt diff(points[i].real()-currpoint.real(), points[i].imag()-currpoint.imag());
                ld angle = arg(diff);
                if (angle < 0.0) angle += (2*PI);
                angles.push_back((double)angle);
            }
            sort(angles.begin(), angles.end());
            int start = 0;
            int end = 0;
            int min = 1<<30;
            for (int i = 0; i < n-1; ++i) {
                int start = i;
                //printf("values %f\n", angles[i]);
                for (int j = 1; j < n-1; ++j) {
                    int end = (start + j) % (n-1);
                    double anglediff = angles[end]-angles[start];
                    if (anglediff < 0) anglediff += (2*PI);
                    if (anglediff - PI > -1.0 * 1e-6) {
                        if (j-1 < min) min = (j-1);
                        break;
                    }
                }
            }
            values[ii] = min;
        }
    }

    for (int i = 0; i < n; ++i) {
        printf("%d\n", values[i]);
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        solve(i);
    }
    return 0;
}
