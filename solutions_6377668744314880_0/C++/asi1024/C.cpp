#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

typedef long double ld;
typedef complex<ld> P;
const ld eps = 1e-7, pi = acos(-1.0);

bool isOK(ld a, ld b) {
  ld c = b - a;
  if (c < -eps) c += 2 * pi;
  return (c < pi + eps);
}

int calc(vector<ld> &angle) {
  int N = angle.size();
  int j = 0, res = N;
  REP(i,N) {
    while (isOK(angle[i], angle[j])) {
      j = (j + 1) % N;
      if (i == j) return 0;
    }
    res = min(res, (i - j + N) % N);
  }
  return res;
}

int main() {
  int T; cin >> T;
  REP(cas, T) {
    int N; cin >> N;
    vector<P> p(N);
    REP(i,N) {
      ld x, y; cin >> x >> y;
      p[i] = P(x, y);
    }
    cout << "Case #" << cas + 1 << ":" << endl;
    REP(i,N) {
      vector<ld> angle;
      REP(j,N) {
        if (i == j) continue;
        angle.push_back(arg(p[j] - p[i]));
      }
      sort(ALL(angle));
      cout << calc(angle) << endl;
    }
  }
  return 0;
}
