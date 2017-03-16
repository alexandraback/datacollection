#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

void solve(VI &p) {
  int first = 0, second = 1;
  if (p[0] < p[1]) {
    swap(first, second);
  }
  for (int i = 0; i < p.size(); ++i) {
    if (p[i] > p[first]) {
      first = i;
    }
  }
  for (int i = 0; i < p.size(); ++i) {
    if (i != first && p[i] > p[second]) {
      second = i;
    }
  }
  int m = p[first] - p[second];
  for (int i = 0; i < m; ++i) {
    cout << char('A' + first) << " ";
  }
  for (int i = 0; i < p.size(); ++i) {
    if (i != first && i != second) {
      for (int j = 0; j < p[i]; ++j)
        cout << char('A' + i) << " ";
    }
  }
  for (int i = 0; i < p[second]; ++i) {
    cout << char('A' + first) << char('A' + second) << " ";
  }
  cout << "\n";
}

int main() {

#ifdef LocalHost
  //freopen("input", "rt", stdin);
  //freopen("A-small-attempt2.in", "rt", stdin);
  freopen("A-large.in", "rt", stdin);
  freopen("outputAL.txt", "w", stdout);
#endif

  int n; cin >> n;
  for (int t = 0; t < n; ++t) {
    int np;
    cin >> np;
    VI p(np);
    for (int i = 0; i < np; ++i) {
      cin >> p[i];
    }

    cout << "Case #" << t + 1 << ": ";
    solve(p);
  }
  return 0;
}
