#include <bits/stdc++.h>

using namespace std;

template<class T> inline T sqr(const T& a) {
  return a * a;
}

template<class T> inline T middle(const T &a, const T &b) {
  return (a + b) / 2;
}

template<class T> inline int len(const T &c) {
  return static_cast<int>(c.size());
}

typedef long long li;
typedef long double ld;
typedef pair<int, char> pt;

const ld EPS = 1e-9;
const ld PI = 2 * acos(0.0);
const int N = 100;

string Make(char a, char b) {
  string s;
  s.push_back(a);
  if (b >= 'A') {
    s.push_back(b);
  }
  return s;
}

void HandleCase() {
  int n;
  scanf("%d", &n);
  vector<pt> ps;
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    ps.push_back({x, 'A' + i});
  }
  sort(ps.begin(), ps.end());
  int d = ps[n - 1].first - ps[n - 2].first;
  vector<string> answer;
  while (d > 1) {
    answer.push_back(Make(ps[n - 1].second, ps[n - 1].second));
    d -= 2;
  }
  if (d == 1) {
    answer.push_back(Make(ps[n - 1].second, '\0'));
    --d;
  }
  assert(d == 0);
  ps[n - 1].first = ps[n - 2].first;
  string small;
  for (int i = 0; i < n - 2; ++i) {
    for (int j = 0; j < ps[i].first; ++j) {
      small.push_back(ps[i].second);  
    }
  }
  int p = len(small) / 2;
  for (int i = 0; i < p; ++i) {
    answer.push_back(Make(small[i * 2], small[i * 2 + 1]));  
  }
  if (len(small) & 1) {
    answer.push_back(Make(small.back(), '\0'));
  }
  for (int i = 0; i < ps[n - 2].first; ++i) {
    answer.push_back(Make(ps[n - 1].second, ps[n - 2].second));
  }
  for (auto s : answer) {
    printf(" %s", s.c_str());
  }
  puts("");
}

int main() {
  int tests;
  scanf("%d", &tests);
  for (int test = 1; test <= tests; ++test) {
    printf("Case #%d:", test);
    HandleCase();
  }
  return 0;
}
