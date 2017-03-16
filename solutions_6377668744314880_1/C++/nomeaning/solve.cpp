#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <queue>
#include <stack>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <deque>
#include <complex>
#include <string>
#include <iomanip>
#include <sstream>
#include <bitset>
#include <valarray>
#include <iterator>
using namespace std;

typedef long long int lli;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned long long ull;

#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define RREP(i,x) for(int i=(x);i>=0;i--)
#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)

const double EPS=1e-6;
const double INF=1e10;

const double PI = M_PI;
// 平面上の点
struct Point{
        Point(double x, double y):x(x) ,y(y){}
        Point(){}
        double x,y;
};
Point operator+(const Point &a, const Point &b){
        return Point(a.x + b.x, a.y + b.y);
}
Point operator-(const Point &a, const Point &b){
        return Point(a.x - b.x, a.y - b.y);
}
Point operator*(const Point &a, const double b){
        return Point(a.x * b, a.y * b);
}
// 必要時定義(複素数の積)
Point operator*(const Point &a,const Point &b){
        return Point(a.x*b.x-a.y*b.y, a.x*b.y+a.y*b.x);
}
// 必要時定義 (基本的に * 1.0 / (ほげほげ)で済ます
Point operator/(const Point &a, const double b){
        return Point(a.x / b, a.y / b);
}
// 外積 a × b
double cross(const Point &a, const Point &b){
        return a.x * b.y - a.y * b.x;
}
// 内積 a ・ b
double dot(const Point &a, const Point &b){
        return a.x * b.x + a.y * b.y;
}
// 比較 (必要時のみ定義)
bool operator<(const Point &a, const Point &b){
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}
// 一致確認 (必要時のみ定義)
bool operator==(const Point &a, const Point &b){
        return a.x == b.x && a.y == b.y;
}

// 角度(必要時のみ定義)
double atan(const Point &a){
        return atan2(a.y, a.x);
}
// |a|^2
double norm(const Point &a){
        return dot(a, a);
}
// |a|
double abs(const Point &a){
        return sqrt(norm(a));
}

// 一致確認(誤差考慮)
bool eq(const Point &a, const Point &b){
        return abs(a-b) < EPS;
}

// 点の90度回転(必要時定義)
Point rotate90(const Point &a){
        return Point(-a.y, a.x);
}
// 点の回転(必要時定義) ラジアン注意
Point rotate(const Point &a, double angle){
        return Point(cos(angle) * a.x - sin(angle) * a.y, sin(angle) * a.x + cos(angle) * a.y);
}
// 直線・線分
struct Line:vector<Point>{
        Line(Point a = Point(0,0), Point b = Point(0,0)){
                this->push_back(a);
                this->push_back(b);
        }
};

// 円
struct Circle: Point{
        double r;
        Circle(Point p = Point(0,0), double r=0):Point(p),r(r){}
};

// 多角形
typedef vector<Point> Polygon;

// 前後の頂点情報(必要時のみ)
Point next(const Polygon &a, int x){
        return a[(x + 1) % a.size()];
}
Point prev(const Polygon &a, int x){
        return a[(x - 1 + a.size()) % a.size()];
}
ostream& operator<<(ostream &os, const Point &a){
        return os<<"("<<a.x<<","<<a.y<<")";
}

istream& operator>>(istream &is, Point &a){
        return is>>a.x>>a.y;
}

int ccw(Point a, Point b, Point c){
        b = b - a; c = c - a;
        if (cross(b, c) > EPS) return +1; // 反時計周り
        if (cross(b, c) < -EPS) return -1;// 時計周り
        if (dot(b, c) < 0) return +2;     // c--a--bがこの順番に一直線上
        if (norm(b) < norm(c)) return -2; // a--b--cがこの順番に一直線上
        return 0;                         // a--c--bが一直線上
}
// 直線交差判定
// 同一直線の場合は交差していると判定する。
bool is_intersect_LL(const Line &l, const Line &m){
        return abs(cross(l[1] - l[0], m[1] - m[0])) > EPS || // 傾きが異なる
                        abs(cross(l[1] - l[0], m[1] - l[0])) < EPS; // 同じ直線である
}

// 直線と線分の交差判定
// 同一直線上にある場合も交差と判定
bool is_intersect_LS(const Line &l, const Line &s){
        return cross(l[1] - l[0], s[0] - l[0]) *
                        cross(l[1] - l[0], s[1] - l[0]) < EPS;
}

// 直線が線分を含むかの判定
bool is_intersect_LP(const Line &l, const Point &p){
        return abs(ccw(l[0], l[1], p))!=1;
}

// 線分交差判定
bool is_intersect_SS(const Line &s, const Line &t){
        return ccw(s[0], s[1], t[0]) * ccw(s[0], s[1], t[1]) <= 0 &&
                        ccw(t[0], t[1], s[0]) * ccw(t[0], t[1], s[1]) <= 0;
}

// 線分が直線を含むかどうか
bool is_intersect_SP(const Line &l, const Point &p){
        return ccw(l[0], l[1], p) == 0;
}

// 円が点を含むかどうか(境界含む EPSに注意)
bool is_intersect_CP(const Circle &c, const Point &p){
        return abs(c-p)<=c.r+EPS;
}

// 2円が共有点を持つかどうか (EPSに注意)
bool is_intersect_CC(const Circle &c,const Circle &d){
        return abs(c-d)<=c.r+d.r &&
                        abs(c-d)>= abs(c.r-d.r);
}
vector<Point> convex_hull(vector<Point> ps) {
        int n=ps.size(), k=0;
        sort(ps.begin(), ps.end());
        vector<Point> ch(2*n);
        for (int i=0; i < n; ch[k++]=ps[i++]) // lower-hull
                while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
        for (int i=n-2, t=k+1; i >= 0; ch[k++]=ps[i--]) // upper-hull
                while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
        ch.resize(k-1);
        return ch;
}

int main() {
  int T;
  cin >> T;
  for(int tc = 1; tc <= T; tc++) {
    cout << "Case #" << tc << ":" << endl;
    int N;
    cin >> N;
    vector<Point> pts(N);
    for(int i = 0; i < N; i++) {
      cin >> pts[i].x >> pts[i].y;
    }
    vector<int> ans(N, 999999999);
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < i; j++) {
        if(i == j)continue;
        int c1, c2;
        c1 = c2 = 0;
        for(int k = 0; k < N; k++) {
          int c = ccw(pts[i], pts[j], pts[k]);
          if(c == 1) {
            c1++;
          }else if(c == -1){
            c2++;
          }
        }
        c1 = min(c1,c2);
        ans[i] = min(ans[i],c1);
        ans[j] = min(ans[j],c1);
      }
    }
    if(N == 1) ans[0] = 0; // edge case
    for(int i = 0; i < N; i++) {
      cout << ans[i] << endl;
    }
  }
}
