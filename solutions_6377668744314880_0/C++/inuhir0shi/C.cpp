

#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;
template<class T> inline bool amax (T &a, const T &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool amin (T &a, const T &b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> ostream& operator << (ostream &os, const vector<T> &v) { os << "["; for (typename vector<T>::const_iterator it = v.begin(); it != v.end(); it++) { os << (it != v.begin() ? ", " : "") << *it; } os << "]"; return os; }
template<class T> ostream& operator << (ostream &os, const set<T> &s) { os << "["; for (typename set<T>::const_iterator it = s.begin(); it != s.end(); it++) { os << (it != s.begin() ? ", " : "") << *it; } os << "]"; return os; }
template<class Key, class Val> ostream& operator << (ostream &os, const map<Key, Val> &m) { os << "{"; for (typename map<Key, Val>::const_iterator it = m.begin(); it != m.end(); it++) { os << (it != m.begin() ? ", " : "") << it->first << ":" << it->second; } os << "}"; return os; }
template<class T, class S> ostream& operator << (ostream &os, const pair<T, S> &p) { os << "(" << p.first << ", " << p.second << ")"; return os; }
template <class Target, class Source> inline Target lexical_cast (const Source &s) { Target t; stringstream ss; ss << s; ss >> t; return t; }

//> v < ^ (clock wise)
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
const int INFI = 1<<28;
const long long int INFL = 1LL<<60;
const double INFD = 1e+300;
const float INFF = 1e+100;
const double EPS = 1e-8;

#include <complex>

#define EPS 1e-8
using namespace std;
typedef complex<double> Point;
namespace std {
    bool operator < (const Point &a, const Point &b) {
        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);
    }
    Point operator / (const Point &p, const double &a) {
        return Point(real(p)/a, imag(p)/a);
    }
    Point operator * (const Point &p, const double &a) {
        return Point(real(p)*a, imag(p)*a);
    }
    bool operator == (const Point &a, const Point &b) {
        return real(a) == real(b) && imag(a) == imag(b);
    }
}
typedef vector<Point> Polygon;
struct Line : public vector<Point> { 
    Line () {}
    Line (const Point &a, const Point &b) {
        push_back(a); push_back(b);
    }
};
struct Circle {
    Point c; double r;
    Circle () {}
    Circle (const Point &c, double r) : c(c), r(r) {}
};
double cross (const Point &a, const Point &b) {
    return imag(conj(a)*b);
}
double dot (const Point &a, const Point &b) {
    return real(conj(a)*b);
}
int ccw (Point a, Point b, Point c) {
    b -= a; c -= a;
    if (cross(b, c) > 0)   return +1; //ccw
    if (cross(b, c) < 0)   return -1; //cw
    if (dot(b, c) < 0)     return +2; //c--a--b on line
    if (norm(b) < norm(c)) return -2; //a--b--c on line
    return 0; //a--c--b or (c=b)
}
Point projection(const Line &l, const Point &p) {
    double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);
    return l[0] + t*(l[0]-l[1]);
}
Point reflection(const Line &l, const Point &p) {
    return p + 2.0 * (projection(l, p) - p);
}
Polygon convexHull (Polygon g) {
    int n = g.size(), k = 0;
    sort(g.begin(), g.end());
    Polygon ch(2*n);
    for (int i = 0; i < n; ch[k++] = g[i++]) //lower-hull
        while (k >= 2 && ccw(ch[k-2], ch[k-1], g[i]) <= 0 && abs(ccw(ch[k-2],ch[k-1],g[i])) != 2) --k;
    for (int i = n-2, t = k+1; i >= 0; ch[k++] = g[i--]) //upper-hull
        while (k >= t && ccw(ch[k-2], ch[k-1], g[i]) <= 0&& abs(ccw(ch[k-2],ch[k-1],g[i])) != 2) --k;
    ch.resize(k-1);
    return ch;
}
int main(){
    cout.setf(ios::fixed); cout.precision(10);
    ios_base::sync_with_stdio(false);
    int T;
    cin >> T;
    int C = 0;
    while (T--) {
        int N;
        cin >> N;
        vector<Point> ps(N);
        map<Point, int> idx;
        for (int i = 0; i < N; i++) {
            cin >> real(ps[i]) >> imag(ps[i]);
            idx[ps[i]] = i;
       //     cout << real(ps[i]) << " " << imag(ps[i]) << " " << idx[ps[i]] << endl;
        }
        
        vector<int> ans(N, 1<<28);
        if (N == 1) {
            ans[0] = 0;
        } else if (N == 2) {
            ans[0] = 0;
            ans[1] = 0;
        } else if (N == 3) {
            ans[0] = 0;
            ans[1] = 0;
            ans[2] = 0;
        }
        for (int i = 1; i < (1<<N); i++) {
            if (__builtin_popcount(i) < 2) continue;
            Polygon G;
            for (int j = 0; j < N; j++) {
                if (i & (1<<j)) G.push_back(ps[j]);
            }
            /*
            if (i == (1|2|4|16)) {
                for (int k = 0; k < G.size(); k++) {
                    cout << "x " << real(G[k]) << "y " << imag(G[k]) << endl;
                }
            cout << endl;
            }*/
            G = convexHull(G);
            /*
            if (i == (1|2|4|16)) {
                for (int k = 0; k < G.size(); k++) {
                    cout << "x " << real(G[k]) << "y " << imag(G[k]) << endl;
                }
            }*/
            for (int j = 0; j < G.size(); j++) {
                int p = idx[G[j]];
                ans[p] = min(ans[p], N-__builtin_popcount(i));
            }
        }
        cout << "Case #" << ++C << ": " << endl;
        for (int i = 0; i < N; i++) cout << ans[i] << endl;
    }
    return 0;
}
