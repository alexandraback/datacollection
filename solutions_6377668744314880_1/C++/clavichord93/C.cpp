/**************************************************
 *        Problem:  GCJ 2015 Round 1A Problem C
 *         Author:  clavichord93
 *          State:  
 **************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const double EPS = 1e-9;
const double PI = acos(-1.0);
inline int sgn(double a) {
    return a > EPS ? 1 : (a < -EPS ? -1 : 0);
}

const int MAX_N = 3005;

struct Point {
	double x, y;
	Point() { x = y = 0; }
	Point(double _x, double _y) : x(_x), y(_y) {}
	Point operator + (const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point operator - (const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
    Point operator * (const double &k) const {
        return Point(x * k, y * k);
    }
    Point operator / (const double &k) const {
        return Point(x / k, y / k);
    }
	Point& operator = (const Point &a) {
		x = a.x, y = a.y;
		return *this;
	}
	bool operator < (const Point &a) const {
		return sgn(x - a.x) < 0 || (!sgn(x - a.x) && sgn(y - a.y) < 0);
	}
	bool operator == (const Point &a) const{
		return !sgn(x - a.x) && !sgn(y - a.y);
	}
	bool operator != (const Point &a) const {
		return sgn(x - a.x) || sgn(y - a.y);
	}
    //法向量，左手方向
    Point normal() const {
        return Point(-y, x);
    }
    void read() {
        scanf("%lf %lf", &x, &y);
    }
    void print() {
        printf("%.6f %.6f\n", x, y);
    }
};
typedef Point Vector;

inline double dot(const Point &a, const Point &b, const Point &c) {
	return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}
inline double det(const Point &a, const Point &b, const Point &c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}
inline double area(const Point &a, const Point &b, const Point &c) {
	return abs(det(a, b, c));
}
inline double triangleArea(const Point &a, const Point &b, const Point &c) {
	return abs(det(a, b, c)) / 2.0;
}

int n;
Point p[MAX_N];
double ang[MAX_N];

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            p[i].read();
        }
        printf("Case #%d:\n", cas);
        if (n == 1) {
            printf("0\n");
        }
        else {
            for (int i = 0; i < n; i++) {
                int cntAng = 0;
                for (int j = 0; j < n; j++) {
                    if (j != i) {
                        ang[cntAng++] = atan2(p[j].y - p[i].y, p[j].x - p[i].x);
                    }
                }
                sort(ang, ang + cntAng);
                //for (int j = 0; j < cntAng; j++) {
                    //printf("%f ", ang[j]);
                //}
                //printf("\n");
                int ans = INF;
                for (int h1 = 0, t1 = 0, h2 = 0, t2 = 0; h2 < cntAng; h1 = t1, h2 = t2) {
                    while (t1 < cntAng && sgn(ang[t1] - ang[h1]) == 0) t1++;
                    while (h2 < cntAng && sgn(ang[h2] - ang[h1] - PI) < 0) h2++;
                    while (t2 < cntAng && sgn(ang[t2] - ang[h1] - PI) <= 0) t2++;
                    //printf("%d %d %d %d\n", h1, t1, h2, t2);
                    ans = min(ans, h2 - t1);
                    ans = min(ans, cntAng - (t2 - h1));
                }
                printf("%d\n", ans);
            }
        }
    }

    return 0;
}

/*
const int main_stack = 16;
char my_stack[128<<20];

int main() {
    __asm__("movl %%esp, (%%eax);\n"::"a"(my_stack):"memory");
    __asm__("movl %%eax, %%esp;\n"::"a"(my_stack + sizeof(my_stack) - main_stack):"%esp");
    Main();
    __asm__("movl (%%eax), %%esp;\n"::"a"(my_stack):"%esp");
    return 0;
}
*/
