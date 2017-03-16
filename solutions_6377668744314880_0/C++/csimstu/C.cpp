#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
typedef long long ll;
const double kEps = 1e-8;

int sgn(double a, double b) {
  if (fabs(a-b) < kEps) return 0;
  return a > b ? 1 : -1;
}

struct PT {
  int x, y;
} p[3333];

PT operator-(PT a, PT b) {
  return PT{a.x-b.x, a.y-b.y};
}

ll cross(PT a, PT b) {
  return (ll)a.x * b.y - (ll)a.y * b.x;
}

bool myCmp(pair<double, PT> &A, pair<double, PT> &B) {
  return A.first < B.first;
}

double polar(PT t) {
  return atan2(t.y, t.x);
}

int main() {
  freopen("t.in", "r", stdin);
  freopen("t.out", "w", stdout);
  int T;
  cin >> T;
  for (int tc = 1; tc <= T; tc++) {
    cout << "Case #" << tc << ":\n";
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
      cin >> p[i].x >> p[i].y;
    for (int i = 0; i < N; i++) {
      vector<pair<double, PT>> arr;
      for (int j = 0; j < N; j++)
        if (i != j) {
          auto t = p[j] - p[i];
          arr.push_back(make_pair(atan2(t.y, t.x), t));
        }
      sort(arr.begin(), arr.end(), myCmp);
      vector<PT> vp;
      for (int m = arr.size(), i = 0; i < m; i++) {
        vp.push_back(arr[i].second);
      }
      int sz = (int)vp.size();
      for (int j = 0; j < sz; j++)
        vp.push_back(vp[j]);
      int ptr1 = 0, ptr2 = 0;
      int ans = max(0, sz - 2);
      for (; ptr1 < sz; ptr1++) {
        int cnt = 1;
        while (ptr1 + 1 < sz && (sgn(polar(vp[ptr1]), polar(vp[ptr1+1])) == 0 && cross(vp[ptr1], vp[ptr1+1]) == 0)) {
          cnt++;
          ptr1++;
        }
        ptr2 = max(ptr2, ptr1);
        while (ptr2 - ptr1 + cnt < sz && ptr2 + 1 < 2*sz &&
            cross(vp[ptr1], vp[ptr2+1]) >= 0)
          ptr2++;
        if (cross(vp[ptr1], vp[ptr2]) >= 0)
          ans = min(ans, N - 1 - (ptr2 - ptr1 + cnt));
      }
      cout << ans << endl;
    }
  }
}
