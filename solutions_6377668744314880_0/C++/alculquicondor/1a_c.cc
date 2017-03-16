#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define MAXN 3000

using namespace std;

typedef long long ll;
struct Pt {
  ll x, y;
  int id;
  Pt operator - (const Pt &b) const {
    return {x-b.x, y-b.y};
  }
  double ang() const {
    return atan2(y, x);
  }
  bool sameAng(const Pt &b) const {
    return x * b.y == y * b.x;
  }
  ll norm2() const {
    return x * x + y * y;
  }
  ll operator % (const Pt & b) const {
    return x * b.y - y * b.x;
  }
};

inline ll ccw(const Pt &p1, const Pt &p2, const Pt &p3) {
  return (p2 - p1) % (p3 - p1);
}

int n;
Pt A[MAXN];
Pt S[MAXN];
int sz;
vector<int> sq;

void go(int ori) {
  sq[A[0].id] = 0;
  S[0] = A[0];
  sz = 1;
  for (int i = 1; i < n; ++i) {
    while (sz > 1 and ccw(S[sz-2], S[sz-1], A[i]) * ori < 0)
      --sz;
    S[sz++] = A[i];
    int cnt = 0;
    for (int j = i + 1; j < n; ++j) {
      if (ccw(S[sz-2], S[sz-1], A[j]) * ori < 0)
        ++cnt;
    }
    //cerr << ' ' << A[i].id << ' ' << cnt << endl;
    sq[A[i].id] = min(sq[A[i].id], cnt);
  }
}

void solve() {
  cin >> n;
  sq.assign(n, n);
  int mini = 0;
  for (int i = 0; i < n; ++i) {
    cin >> A[i].x >> A[i].y;
    A[i].id = i;
    if (A[i].y < A[mini].y)
      mini = i;
  }
  swap(A[0], A[mini]);
  Pt &st = A[0];
  sort(A + 1, A + n, [st](const Pt &a, const Pt &b) {
      Pt d1 = a - st, d2 = b - st;
      if (d1.sameAng(d2))
        return d1.norm2() < d2.norm2();
      return d1.ang() < d2.ang();
    });
  go(1);
  sort(A + 1, A + n, [st](const Pt &a, const Pt &b) {
      Pt d1 = a - st, d2 = b - st;
      if (d1.sameAng(d2))
        return d1.norm2() < d2.norm2();
      return d1.ang() > d2.ang();
    });
  go(-1);
}

int main() {
  ios::sync_with_stdio(0);
  int tc;
  cin >> tc;
  for (int cs = 1; cs <= tc; ++cs) {
    cout << "Case #" << cs << ":" << endl;
    solve();
    for (int &x : sq)
      cout << x << endl;
  }
  return 0;
}
