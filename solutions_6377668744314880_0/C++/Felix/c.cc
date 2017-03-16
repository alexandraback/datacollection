#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

#define DEBUG(x) cerr << #x << " = " << x << endl

#define FR first
#define SC second

using namespace std;

typedef long long ll;
typedef long double ld;

typedef pair<ld, int> PDI;

template <class Ta, class Tb> inline Tb cast(Ta a) {
  stringstream ss;
  ss << a;
  Tb b;
  ss >> b;
  return b;
};

const ld EPS = 1e-9;

ld normalize(ld alpha) {
  return atan2(sin(alpha), cos(alpha));
}

// Returns true iff alpha is in [a, b).
bool between(ld alpha, ld a, ld b) {
  if (b < a) b += 2.0 * M_PI;
  if (alpha < a) alpha += 2.0 * M_PI;
  return a - EPS < alpha && alpha < b - EPS;
}

vector<int> solve(const vector<ld>& x, const vector<ld>& y) {
  int n = int(x.size());
  vector<int> ret(n, n - 1);
  for (int squirrel = 0; squirrel < n; ++squirrel) {
    vector<PDI> trees;
    for (int i = 0; i < n; ++i) if (i != squirrel) {
      PDI tree;
      tree.FR = atan2(y[i] - y[squirrel], x[i] - x[squirrel]);
      tree.SC = i;
      trees.push_back(tree);
    }
    sort(trees.begin(), trees.end());
    for (int begin = 0, end = 1; begin < int(trees.size()); ++begin) {
      for (; between(trees[end].FR, trees[begin].FR, normalize(trees[begin].FR + M_PI))
             && end != begin;) {
        end = (end + 1) % int(trees.size());
      }
      // All on the same half.
      if (end == begin) {
        ret[squirrel] = 0;
        break;
      }
      int count = end - begin;
      if (count < 0) count += int(trees.size());
      --count;
      if (count < ret[squirrel]) {
        ret[squirrel] = count;
        if (ret[squirrel] == 0) break;
      }
    }
  }
  return ret;
}

int main() {
  int T;
  cin >> T;
  for (int ca = 1; ca <= T; ++ca) {
    int n;
    cin >> n;
    vector<ld> x(n), y(n);
    for (int i = 0; i < n; ++i) {
      cin >> x[i] >> y[i];
    }
    vector<int> sol = solve(x, y);
    cout << "Case #" << ca << ": " << endl;
    for (int i = 0; i < n; ++i) {
      cout << sol[i] << endl;
    }
  }
}

