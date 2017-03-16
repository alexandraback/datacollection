#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  unsigned nn;
  scanf("%d", &nn);
  for(unsigned ii = 1; ii <= nn; ++ii) {
    printf("Case #%d: ", ii);

    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
    //printf("%d %d %d\n", r, c, n);
    vector<int> vec (r * c, 0);
    for (auto&& it = vec.rbegin(); it != vec.rbegin() + n; ++it)
      *it = 1;
    vector<vector<int>> trp (r, vector<int> (c, 0));
    ll counter = 0;
    ll ret = 2 * r * c - r - c;
    do {
      counter = 0;
      for (unsigned i = 0; i < r; ++i) {
        for (unsigned j = 0; j < c; ++j) {
          trp[i][j] = vec[i * c + j];
        }
      }
      for (unsigned i = 0; i < r - 1; ++i) {
        for (unsigned j = 0; j < c - 1; ++j) {
          if (trp[i][j] == 1 && trp[i + 1][j] == 1)
            counter++;
          if (trp[i][j] == 1 && trp[i][j + 1] == 1)
            counter++;
        }
      }
      for (unsigned i = 0; i < r - 1; ++i) {
        if(trp[i][c - 1] == 1 && trp[i + 1][c - 1] == 1)
          counter++;
      }
      for (unsigned i = 0; i < c - 1; ++i) {
        if(trp[r - 1][i] == 1 && trp[r - 1][i + 1] == 1)
          counter++;
      }

      ret = min(ret, counter);

    } while(next_permutation(vec.begin(), vec.end()));
    printf("%ld\n", ret);
  }
  return 0;

}