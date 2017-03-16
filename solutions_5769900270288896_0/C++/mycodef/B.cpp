#include <iostream>
#include <algorithm>
#include <vector>

#include <cstdio>

using namespace std;

bool grid[17][17];

void main2() {
  int r, c, n;
  cin >> r >> c >> n;
  long long cnt = 1000000000;
  for (int i = 0; i < (1 << (r * c)); ++i) {
    if (__builtin_popcount(i) == n) {
      long long x = 0;
      for (int k1 = 0; k1 < r; ++k1) for (int k2 = 0; k2 < c; ++k2) grid[k1][k2] = false;
      for (int k1 = 0; k1 < r; ++k1) for (int k2 = 0; k2 < c; ++k2) {
//        cout << n << ' ' << k1 << ' '<< k2 << ' ' << (k1 * c + k2) << '\n';  
        if ((i >> (k1 * c + k2)) % 2 == 1) grid[k1][k2] = true;
      }
//      
//      for (int k1 = 0; k1 < r; ++k1) {
//        for (int k2 = 0; k2 < c; ++k2) cout << grid[k1][k2];
//        cout << '\n';
//      }
//      cout << '\n';
      for (int k1 = 0; k1 < r; ++k1) for (int k2 = 0; k2 < c; ++k2) if (grid[k1][k2]) {
        if (k1 - 1 >= 0 && grid[k1 - 1][k2]) ++x;
        if (k2 - 1 >= 0 && grid[k1][k2 - 1]) ++x;
      }
      cnt = min(cnt, x);
    }
  } 
  cout << cnt << '\n';
}

void main2_slow() {
  //
}

int main() {
#ifdef MOCKINGJAY
  freopen("source/data.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
#else
  freopen("source/B-small-1.in", "r", stdin);
  freopen("source/B-small-1.out", "w", stdout);
#endif


  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int T; cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    main2();
  }

}
