#include "iostream"
#include "cmath"
#include "cstdio"
#include "algorithm"
#include "map"
#include "numeric"
#include "queue"
#include "set"
#include "string"
#include "utility"
#include "vector"
using namespace std;
typedef long long ll;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
#define REP(i, a, b)                                                    \
	for (int i = int(a); i <= int(b); i++) // a to b, and variable i is local!
#define ITER(c, it) \
	for (auto it = (c).begin(); it != (c).end(); it++)

int main() {
  int T; scanf("%d", &T);
  for (int Ti = 1; Ti <= T; ++Ti) {
    int r1, r2, v;
    cin >> r1;
    vector<int> s1, s2, r;
    REP(i, 1, 4) {
      REP(j,1,4) {
        cin >> v;
        if (i == r1) {
          s1.push_back(v);
        }
      }
    }

    cin >> r2;
    REP(i, 1, 4) {
      REP(j,1,4) {
        cin >> v;
        if (i == r2) {
          s2.push_back(v);
        }
      }
    }

    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    set_intersection(s1.begin(), s1.end(),s2.begin(), s2.end(), back_inserter(r));

    if (r.empty()) {
      printf("Case #%d: Volunteer cheated!\n", Ti);
    } else if (r.size() > 1) {
      printf("Case #%d: Bad magician!\n", Ti);
    } else {
      printf("Case #%d: %d\n", Ti, r[0]);
    }
  }
  return 0;
}
