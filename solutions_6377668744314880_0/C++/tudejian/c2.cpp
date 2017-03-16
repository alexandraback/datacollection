#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <climits>
#include <utility>
using namespace std;

const int kMaxN = 3000 + 10;

struct Point {
    long long x, y;
    Point() {}
    Point(long long xx, long long yy) : x(xx), y(yy) {}
};

long long cross(const Point& A, const Point& B, const Point& C) {
    return (((B).x-(A).x)*((C).y-(A).y)-((B).y-(A).y)*((C).x-(A).x));
}

long long distSqr(const Point& a, const Point& b) {
    return (((a).x-(b).x)*((a).x-(b).x)+((a).y-(b).y)*((a).y-(b).y));
}

Point pivot;

bool cmp(const Point& a, const Point& b) {
    int t = cross(pivot, a, b);
    return t > 0 || (t == 0 && distSqr(pivot, a) < distSqr(pivot, b));
}

void convexHull(Point s[], int n, Point ch[], int &m) {
    int i, k = 0, top = 1; if (n < 3) {
        for (i = 0; i < n; i++) ch[i] = s[i]; m = n; return ;
    }
    for (i = 1; i < n; i++)
        if (s[i].y < s[k].y || (s[i].y == s[k].y && s[i].x < s[k].x)) k = i;
    pivot = s[k]; s[k] = s[0]; s[0] = pivot;
    sort(s + 1, s + n, cmp);
    ch[0] = s[0]; ch[1] = s[1];
    for (i = 2; i < n; i++) {
        while (top > 0 && cross(s[i], ch[top], ch[top-1]) >= 0) top--; //Not Online 
        ch[++top] = s[i];
    }
    m = top + 1;
}

int T, N;
Point p[kMaxN];
Point s[kMaxN];
Point ch[kMaxN];
int M;

int main() {
    scanf("%d", &T);
    for (int cas = 0; cas < T; ++cas) {
        scanf("%d", &N);
        for (int i = 0; i < N; ++i) {
            scanf("%lld%lld", &s[i].x, &s[i].y);
            p[i] = s[i];
        }
        convexHull(p, N, ch, M);
        printf("Case #%d:\n", cas + 1);
        for (int i = 0; i < N; ++i) {
            int ans = N;
            for (int j = 0; j < N; ++j) {
                if (s[i].x == s[j].x && s[i].y == s[j].y) {
                    continue;
                }
                // s[i] and ch[j]
                int sumA = 0;
                int sumB = 0;
                for (int k = 0; k < N; ++k) {
                    long long t = cross(s[i], s[j], s[k]);
                    if (t > 0) sumA++;
                    else if (t < 0) sumB++;
                    if (sumA >= ans && sumB >= ans) {
                        break;
                    }
                }
                ans = min(ans, min(sumA, sumB));
            }
            if (ans == N) {
                ans = 0;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

