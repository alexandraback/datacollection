/*
 *-
 * File: stuff.cpp
 * Author: Andy Y.F. Huang (azneye)
 * Created on Aug 23, 2014, 11:50:25 PM
 */

#include <bits/stdc++.h>

using namespace std;

namespace stuff {
typedef long long ll;
struct Point {
  int x, y, id;

  bool operator<(const Point& p) const {
    return x < p.x || (x == p.x && y < p.y);
  }

  Point operator-(const Point& p) const {
    return Point { x - p.x, y - p.y, -1 };
  }

  ll cross(const Point& p) const {
    return ll(x) * p.y - ll(y) * p.x;
  }

  friend ostream& operator<<(ostream& out, const Point& p) {
    return out << '(' << p.x << ',' << p.y << ')';
  }
};

bool ccw(Point p, Point a, Point b) {
  return (a - p).cross(b - p) > 0;
}

vector<Point> get_hull(const vector<Point>& pt) {
  vector<Point> res;
  for (int i = 0; i < (int) pt.size(); i++) {
    while (res.size() >= 2u && ccw(res[res.size() - 2], res[res.size() - 1], pt[i]))
      res.pop_back();
    res.push_back(pt[i]);
  }
  for (int i = pt.size() - 2, t = res.size(); i >= 0; i--) {
    while ((int) res.size() >= t + 1 && ccw(res[res.size() - 2], res[res.size() - 1], pt[i]))
      res.pop_back();
    res.push_back(pt[i]);
  }
  return res;
}

void solve(int test_num) {
  int N;
  cin >> N;
  vector<Point> pt(N);
  vector<int> res(N, N);
  for (int i = 0; i < N; i++) {
    cin >> pt[i].x >> pt[i].y;
    pt[i].id = i;
  }
  sort(pt.begin(), pt.end());
  for (int mask = 1; mask < (1 << N); mask++) {
    vector<Point> now;
    for (int i = 0; i < N; i++)
      if (1 << i & mask)
        now.push_back(pt[i]);
    vector<Point> hull = get_hull(now);
    const int bit_cnt = __builtin_popcount(mask);
    for (const Point& p : hull)
      res[p.id] = min(res[p.id], N - bit_cnt);
  }
  cout << "Case #" << test_num << ": " << endl;
  for (const int& val : res)
    cout << val << endl;
}

void solve() {
#ifdef AZN
  double start_t = clock();
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
//freopen("azn.txt", "w", stderr);
#endif
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1;
//scanf("%d", &T);
  cin >> T;
  for (int t = 1; t <= T; t++)
    solve(t);
#ifdef AZN
  cerr << "Took: " << ((clock() - start_t) / CLOCKS_PER_SEC);
#endif
}
}

int main() {
  stuff::solve();
  return 0;
}
