#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>

using namespace std;

const int N_MAX = 4000;
long long X[N_MAX];
long long Y[N_MAX];
int N;

struct Point {
  Point(long long x_, long long y_) : x(x_), y(y_) {}
  long long x, y;
};


double atan3(double y, double x) {
  double ret = atan2(y, x);
  return (ret < 0 ? ret + 2 * M_PI : ret);
}
bool compare_angle(Point a, Point b) {
  if (a.x * b.y == a.y * b.x && a.x * b.x + a.y * b.y > 0)
    return false;
  if (a.y == 0 && a.x > 0)
    return true;
  return atan3(a.y, a.x) < atan3(b.y, b.x);
}


void init() {
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> X[i] >> Y[i];
}

int chops_needed(int k) {
  // cout << "chopping " << k << endl;

  vector<Point> pts;
  for (int i = 0; i < N; i++) {
    if (i == k) continue;
    pts.push_back(Point(X[i] - X[k], Y[i] - Y[k]));
  }
  sort(pts.begin(), pts.end(), compare_angle);

  /*
  cout << "pts: ";
  for (int i = 0; i < pts.size(); i++) {
    cout << "(" << pts[i].x << ", " << pts[i].y << ") ";
  }
  cout << endl;
  */

  int min_chops = 0;
  for (int i = 0; i < pts.size(); i++) {
    if (pts[i].y > 0)
      min_chops++;
  }

  for (int i = 0; i < pts.size(); i++) {
    Point p = pts[i];
    if (p.y < 0 || (p.y == 0 && p.x < 0))
      break;
    Point negp(-p.x, -p.y);

    vector<Point>::iterator start = upper_bound(pts.begin(), pts.end(), p, compare_angle);
    vector<Point>::iterator end = lower_bound(pts.begin(), pts.end(), negp, compare_angle);

    // cout << "se " << (start - pts.begin()) << " " << (end - pts.begin()) << endl;
    min_chops = min(min_chops, (int) (end - start));

    start = upper_bound(pts.begin(), pts.end(), negp, compare_angle);
    end = lower_bound(pts.begin(), pts.end(), p, compare_angle);
    // cout << "se2 " << (start - pts.begin()) << " " << (end - pts.begin()) << endl;
    int num_chops = (end - pts.begin()) + (pts.end() - start);
    min_chops = min(min_chops, num_chops);
  }

  return min_chops;
}

void solve_case(int t) {
  init();

  cout << "Case #" << t << ":\n";
  if (N == 1) {
    cout << "0\n";
    return;
  }

  for (int i = 0; i < N; i++) {
    cout << chops_needed(i) << "\n";
  }
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
