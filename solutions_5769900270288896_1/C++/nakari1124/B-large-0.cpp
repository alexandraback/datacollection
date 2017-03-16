#include <cstdio>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long i64;
typedef i64 nkr_int;
typedef pair<i64, i64> pi;

typedef vector<nkr_int> vi;
typedef vector<vi> vvi;
#define pb push_back
#define iter(T) T::iterator
#define sz(a) int((a).size())
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define REP(s, e, n)  for(n = (s); n < (e); ++n)

class Solver {
public:
  Solver() {}
  ~Solver() {}

  void solve();
};

void Solver::solve() {
  i64 R, C, N;
  cin >> R >> C >> N;
  if(N <= (R * C + 1) / 2) {
    cout << 0 << endl;
    return;
  }
  
  if(C > R) {
    swap(R, C);
  }

  if(C == 1) {
    if(R % 2 == 0) {
      i64 cap = R / 2;
      if(N - cap == 1) {
	cout << 1 << endl;
      }
      else if(N - cap > 1) {
	cout << 1 + (N - cap - 1) * 2 << endl;
      }
    }
    else {
      i64 cap = (R + 1) / 2;
      cout << (N - cap) * 2 << endl;
    }
    return;
  }
  else if(C == 2) {
    i64 D = N - (R * C) / 2;
    if(D <= 2) {
      cout << 2 * D << endl;
    }
    else {
      cout << 4 + 3 * (D - 2) << endl;
    }
    return;
  }
  else {
    i64 V = R * C - N;
    i64 ans1, ans2;
    ans1 = ans2 = R * (C - 1) + C * (R - 1);

    i64 V0 = min(((R - 2) * (C - 2) + 1) / 2, V);
    ans1 -= V0 * 4;
    V -= V0;

    i64 V1 = min((((R - 2) / 2) + (C - 2) / 2) * 2, V);
    ans1 -= V1 * 3;
    V -= V1;

    i64 V2 = min(4LL, V);
    ans1 -= V2 * 2;
    V -= V2;

    V = R * C - N;
    V0 = min((R - 2) * (C - 2) / 2, V);
    ans2 -= V0 * 4;
    V -= V0;

    V1 = min(((R - 2 + 1) / 2 + (C - 2 + 1) / 2) * 2, V);
    ans2 -= V1 * 3;
    V -= V1;

    cout << min(ans1, ans2) << endl;
  }
}

int main(int argc, char *argv[]){

  i64 N;
  cin >> N;
  i64 n;

  Solver s;

  REP(0, N, n) {
    cout << "Case #" << n + 1 << ": ";

    s.solve();
  }

  return 0;
}

