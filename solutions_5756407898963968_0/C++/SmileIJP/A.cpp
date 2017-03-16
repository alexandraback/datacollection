#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <iterator>

#define ALL(v) v.begin(), v.end()

using namespace std;

template< typename T > T next() {  T tmp; cin >> tmp; return tmp; }

void solve() {
  vector< int > v[2];

  for (int k = 0; k < 2; ++k) {
    int r = next< int >() - 1;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        int val = next< int >();
        if (i == r) {
          v[k].push_back(val);
        }
      }
    }
    sort(v[k].begin(), v[k].end());
  }

  vector< int > res(v[0].size());
  int sz = set_intersection(ALL(v[0]), ALL(v[1]), res.begin()) - res.begin();
  if (sz == 0) {
    printf("Volunteer cheated!\n");
  } else if (sz >= 2) {
    printf("Bad magician!\n");
  } else {
    printf("%d\n", res[0]);
  }
}

int main() {

//  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);

  int test = next< int >();
  for (int i = 1; i <= test; ++i) {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}

