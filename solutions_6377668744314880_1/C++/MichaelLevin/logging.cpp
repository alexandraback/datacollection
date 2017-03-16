#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "C"

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<vvb> vvvb;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ll, ll> pll;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<vvd> vvvd;

typedef pair<ll, ll> Point;

Point Diff(const Point& a, const Point& b) {
  return Point(b.first - a.first, b.second - a.second);
}

ll ScalarProduct(const Point& a, const Point& b) {
  return a.first * b.first + a.second * b.second;
}

ll VectorProduct(const Point& a, const Point& b) {
  return a.first * b.second - a.second * b.first;
}

ll MyAbs(ll x) {
  if (x < 0) {
    return -x;
  }
  return x;
}

struct Compare {
  bool operator()(const Point& ca, const Point& cb) {
    if (ca.second >= 0 && cb.second < 0) {
      return true;
    }
    if (ca.second < 0 && cb.second >= 0) {
      return false;
    }
    if (ca.second == 0 && cb.second == 0) {
      return ca.first > cb.first;
    }
    ll vp = VectorProduct(ca, cb);
    if (vp != 0) {
      return vp > 0;
    }
    return MyAbs(ca.first) < MyAbs(cb.first);
  }
};

bool SameDirection(const Point& a, const Point& b) {
  return VectorProduct(a, b) == 0 && ScalarProduct(a, b) > 0;
}

vi SolveFast(int n, const vector<Point>& points) {
  vi results;
  for (int i = 0; i < n; ++i) {
    vector<Point> copy_points;
    for (int j = 0; j < n; ++j) {
      if (j != i) {
        copy_points.push_back(Diff(points[i], points[j]));
      }
    }
    sort(copy_points.begin(), copy_points.end(), Compare());
    for (int j = 0; j < n - 1; ++j) {
      copy_points.push_back(copy_points[j]);
    }
    int l = 0;
    while (l + 1 < n - 1 && SameDirection(copy_points[l], copy_points[l + 1])) {
      ++l;
    }
    int r = l;
    while (r + 1 < copy_points.size() && VectorProduct(copy_points[l], copy_points[r + 1]) > 0) {
      ++r;
    }
    int result = r - l;
    ++l;
    while (l < n - 1) {
      while (l + 1 < n - 1 && SameDirection(copy_points[l], copy_points[l + 1])) {
        ++l;
      }
      if (r < l) {
        r = l;
      }
      while (r + 1 < copy_points.size() && VectorProduct(copy_points[l], copy_points[r + 1]) > 0) {
        ++r;
      }
      result = min(result, r - l);
      ++l;
    }
    results.push_back(result);
  }
  return results;
}

vi SolveSlow(int n, const vector<Point>& points) {
  vi results;
  for (int i = 0; i < n; ++i) {
    int result = n - 1;
    for (int mask = 0; mask < (1 << n); ++mask) {
      if ((mask >> i) & 1) {
        continue;
      }
      vi left;
      for (int j = 0; j < n; ++j) {
        if ((mask >> j) & 1) {
          left.push_back(j);
        }
      }
      if (left.size() == n - 1) {
        int x = 2;
      }
      bool on_border = false;
      for (int j = 0; j < left.size(); ++j) {
        int other = left[j];
        ll a = points[other].second - points[i].second;
        ll b = points[i].first - points[other].first;
        ll c = -a * points[i].first - b * points[i].second;
        bool negative = false;
        bool positive = false;
        for (int k = 0; k < left.size(); ++k) {
          int index = left[k];
          ll side = a * points[index].first + b * points[index].second + c;
          if (side < 0) {
            negative = true;
          } else if (side > 0) {
            positive = true;
          }
        }
        if (!positive || !negative) {
          on_border = true;
          break;
        }
      }
      if (on_border) {
        result = min(result, n - (int)left.size() - 1);
      }
    }
    results.push_back(result);
  }
  return results;
}

void Output(const vi& result) {
  for (int i = 0; i < result.size(); ++i) {
    cerr << result[i] << ' ';
  }
  cerr << endl;
}

int main() {
  /*while (true) {
    int n = rand() % 10 + 1;
    cerr << n << endl;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
      do {
        points[i].first = rand() % 201 - 100;
        points[i].second = rand() % 201 - 100;
        bool good = true;
        for (int j = 0; j < i; ++j) {
          if (points[i] == points[j]) {
            good = false;
            break;
          }
        }
        if (good) {
          break;
        }
      } while (true);
    }
    for (int i = 0; i < n; ++i) {
      cerr << points[i].first << ' ' << points[i].second << endl;
    }
    vi result1 = SolveSlow(n, points);
    vi result2 = SolveFast(n, points);
    Output(result1);
    Output(result2);
    if (result1 != result2) {
      cerr << "Wrong answer" << endl;
      break;
    } else {
      cerr << "OK" << endl;
    }
  }*/
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int tests;
  cin >> tests;
  for (int test_index = 0; test_index < tests; ++test_index) {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; ++i) {
      cin >> points[i].first >> points[i].second;
    }
    cout << "Case #" << (test_index + 1) << ": " << endl;
    cerr << "Case #" << (test_index + 1) << ": " << endl;
    vector<int> results = SolveFast(n, points);
    for (int i = 0; i < n; ++i) {
      cout << results[i] << endl;
      cerr << results[i] << endl;
    }
  }
  return 0;
}
