#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <utility>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

void PrintTestCase(int test_index) {
  cout << "Case #" << test_index << ":\n";
}

struct Vector {
  double x, y;

  Vector(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}

  double SqrSize() const {
    return x * x + y * y;
  }
};

Vector operator+(const Vector& u, const Vector& v) {
  return Vector(u.x + v.x, u.y + v.y);
}

Vector operator-(const Vector& u, const Vector& v) {
  return Vector(u.x - v.x, u.y - v.y);
}

Vector operator*(double alpha, const Vector& u) {
  return Vector(alpha * u.x, alpha * u.y);
}

double ScalProd(const Vector& u, const Vector& v) {
  return u.x * v.x + u.y * v.y;
}

double VectProd(const Vector& u, const Vector& v) {
  return u.x * v.y - u.y * v.x;
}

class Cmp {
 public:
  bool operator()(const Vector& lhs, const Vector& rhs) const {
    double vect_prod = VectProd(lhs, rhs);
    if (vect_prod != 0) {
      return vect_prod > 0;
    }
    return lhs.SqrSize() < rhs.SqrSize();
  }
};

Vector LeftDown(const vector<Vector>& p) {
  Vector res = p[0];
  for (int i = 1; i < p.size(); ++i) {
    if (res.x > p[i].x || res.x == p[i].x && res.y > p[i].y) {
      res = p[i];
    }
  }
  return res;
}

vector<Vector> ConvexHull(const vector<Vector>& p) {
  vector<Vector> q = p;
  Vector ld = LeftDown(p);
  for (int i = 0; i < q.size(); ++i) {
    q[i] = q[i] - ld;
  }
  sort(q.begin(), q.end(), Cmp());
  vector<Vector> res = {q[0], q[1]};
  for (int i = 2; i < q.size(); ++i) {
    while (VectProd(res[res.size() - 1] - res[res.size() - 2], q[i] - res.back()) < 0) {
      res.pop_back();
    }
    res.push_back(q[i]);
  }
  for (int i = (int)q.size() - 2; i > 0; --i) {
    if (VectProd(res.back(), q[i]) == 0) {
      res.push_back(q[i]);
    }
  }
  for (Vector& u : res) {
    u = u + ld;
  }
  return res;
}

bool InSeg(const Vector& u, const Vector& a, const Vector& b) {
  return VectProd(a - u, b - u) == 0 && ScalProd(a - u, b - u) <= 0;
}

int F(const Vector& u, const vector<Vector>& p_) {
  int n = p_.size();
  vector<Vector> p = p_;
  for (int i = 0; i < n; ++i) {
    p.push_back(p_[i]);
  }
  int res = n;
  for (int i = 0; i < n; ++i) {
    if (n == 3) {
      res = min(res, 1);
      for (int j = 0; j < n; ++j) {
        if (InSeg(u, p[j], p[j + 1])) {
          res = 0;
        }
      }
      continue;
    }
    Vector q = p[i];
    int l = i + 1;
    int r = i - 1 + n;
    while (l != r) {
      int m = (l + r) / 2;
      Vector v = p[m];
      if (VectProd(u - q, v - q) < 0) {
        l = m + 1;
      } else {
        r = m;
      }
      // cout << "l = " << l << " r = " << r << endl;
    }
    int c = (i - l + n) % n - 1;
    res = min(res, c);
    // res = min(res, n - 2 - c);
    // cout << "res = " << res << endl;
  }
  return res;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  // freopen("", "r", stdin);
  // freopen("", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int n;
    cin >> n;
    vector<Vector> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i].x >> p[i].y;
    }
    if (n <= 3) {
      PrintTestCase(test_index + 1);
      for (int i = 0; i < n; ++i) {
        cout << "0\n";
      }
      continue;
    }
    vector<Vector> ch = ConvexHull(p);
    /*
    cout << "!" << endl;
    for (int i = 0; i < ch.size(); ++i) {
      cout << ch[i].x << ' ' << ch[i].y << endl;
    }
    */
    PrintTestCase(test_index + 1);
    for (int i = 0; i < n; ++i) {
      cout << F(p[i], ch) << "\n";
    }
  }
  return 0;
}
