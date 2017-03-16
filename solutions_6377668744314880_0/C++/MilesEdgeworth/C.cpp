#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct point {
  int x, y;

  int cross(const point& p) const {
    return x * p.y - y * p.x;
  }

  int mag2(const point& p) const {
    return (x - p.x)*(x - p.x) + (y - p.y)*(y - p.y);
  }

  bool operator<(const point& p) const;
} cmp_point;

int ar(const point& a, const point& b, const point& c) {
  point ab = {b.x - a.x, b.y - a.y}, ac = {c.x - a.x, c.y - a.y};
  return ab.cross(ac);
}

bool point::operator<(const point& p) const {
  int cx = ar(cmp_point, *this, p);
  if (cx == 0) {
    return mag2(cmp_point) > p.mag2(cmp_point);
  } else {
    return cx > 0;
  }
}


int bitcount(int k) {
  int total = 0;
  for (int i = 0; i < 32; ++i) {
    total += (bool)(k & (1 << i));
  }
  return total;
}

bool on_boundary(vector<point>& convex, point& c) {
  bool has_zero = false;
  for (int i = 0; i < convex.size(); ++i) {
    point& a = convex[i];
    point& b = convex[(i + 1) % convex.size()];
    if (ar(a, b, c) == 0) has_zero = true;
    if (ar(a, b, c) < 0) return false;
  }
  return has_zero;
}

int solve(point* ptsx, int N, int keep) {
  vector<point> pts;
  for (int i = 0; i < N; ++i) {
    if (keep & (1 << i)) {
      pts.push_back(ptsx[i]);
    }
  }
  if (pts.size() < 3) return 0;
 
  //cout << "Points:" << endl;
  //for (int i = 0; i < pts.size(); ++i) {
  //  cout << pts[i].x << ' ' << pts[i].y << endl;
  //}
  //cout << endl;

  int min_i = 0;
  for (int i = 1; i < pts.size(); ++i) {
    if (pts[i].x < pts[min_i].x || (pts[i].x == pts[min_i].x && pts[i].y < pts[min_i].y)) {
      min_i = i;
    }
  }
  swap(pts[min_i], pts.back());
  point base = pts.back();
  cmp_point = base;
  pts.pop_back();

  sort(pts.begin(), pts.end());

  vector<point> convex = {base, pts[0]};
  for (int i = 1; i < pts.size(); ++i) {
    convex.push_back(pts[i]);
    int top = convex.size() - 1;
    //cout << convex[top - 2].x << ' ' << convex[top - 2].y << ' ' << convex[top - 1].x << ' ' << convex[top - 1].y << ' ' << convex[top].x << ' ' << convex[top].y << endl;
    //cout << ar(convex[top-2], convex[top-1], convex[top]) << endl;
    while (top >= 2 && ar(convex[top-2], convex[top-1], convex[top]) < 0) {
        swap(convex[top-1], convex[top]);
        convex.pop_back();
        top--;
    }
  }

  // cout << "convex:" << endl; for (int i = 0; i < convex.size(); ++i) { cout << convex[i].x << ' ' << convex[i].y << endl;
  // }
  // cout << endl;

  int area = 0;
  for (int i = 0; i < convex.size(); ++i) {
    area += ar({0, 0}, convex[i], convex[(i + 1) % pts.size()]);
  }
  if (area == 0) return 0;

  int ans = 0;
  for (int i = 0; i < N; ++i) {
    if (on_boundary(convex, ptsx[i])) {
      ans |= 1 << i;
      //cout << i << ' ';
    }
  }
  //cout << endl;
  return ans;
}

int main() {
  int T;
  cin >> T;

  for (int t = 1; t <= T; ++t) {
    int N;
    cin >> N;
    point pts[N];
    for (int i = 0; i < N; ++i) {
      cin >> pts[i].x >> pts[i].y;
    }

    cout << "Case #" << t << ":" << endl;
    int best[N];
    for (int i = 0; i < N; ++i) best[i] = 1000000000;
    for (int i = 0; i < (1 << N); ++i) {
      int ans = solve(pts, N, i);
      int count = bitcount(i);
      for (int j = 0; j < N; ++j) {
        if (ans & (1 << j)) {
          best[j] = min(best[j], N - count);
        }
      }
    }
    for (int i = 0; i < N; ++i) {
      cout << best[i] << endl;
    }
  }
}
