#define PRETEST
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <sstream>
using namespace std;

#define INF 0x4f4f4f4f
#define FILL(a,b) memset(a,b,sizeof(a))
#define SQR(a) ((a) * (a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef map<int, int> mii;

class point {
 public:
  int x, y;
  point() {}
  point(int _x, int _y) {
    x = _x;
    y = _y;
  }
  point operator-(const point& p) const {
    return point(x - p.x, y - p.y);
  }
  ll operator*(const point& p) const {
    return (ll)x * p.y - (ll)y * p.x;
  }
  bool operator<(const point& p) const {
    return atan2(y, x) < atan2(p.y, p.x);
  }
};

void find(int &ans, vector<point>& vec) {
  int size = vec.size();
  if (size <= 1) {
    ans = 0;
    return;
  }
  int i = 0, j = 1, counter = size - 1;
  while (j < size && vec[i] * vec[j] >= 0) {
    ++j;
    --counter;
  }
  ans = counter;
  if (j == size) {
    ans = 0;
    return;
  }
  for (i = 1; i < size; ++i) {
    ++counter;
    while (j != i && vec[i] * vec[j] >= 0) {
      if (++j == size) {
        j = 0;
        --counter;
      }
    }
    if (j == i) {
      ans = 0;
      return;
    }
    ans = min(ans, counter);
  }
}

int main(int argc, char *argv[]) {
#ifdef PRETEST
  freopen("C-small.in", "r", stdin);
  freopen("out.txt", "w+", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int C = 1; C <= T; ++C) {
    int N;
    scanf("%d", &N);
    vector<point> vec;
    for (int i = 0; i < N; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      vec.push_back(point(x, y));
    }
    printf("Case #%d:\n", C);
    for (int i = 0; i < N; ++i) {
      vector<point> tmp;
      for (int j = 0; j < N; ++j) {
        if (i != j) {
          tmp.push_back(vec[i] - vec[j]);
        }
      }
      sort(tmp.begin(), tmp.end());
      int ans = 0;
      find(ans, tmp);
      printf("%d\n", ans);
    }
  }
  
  return 0;
}
