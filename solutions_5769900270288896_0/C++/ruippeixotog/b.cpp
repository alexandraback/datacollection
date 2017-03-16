#include <cmath>
#include <iostream>

using namespace std;

int r, c, n;
bool arr[16][16];

int bf(int k, int i, int j) {
  if(k >= n) {
    int res = 0;
    for(int i = 0; i < r; i++) {
      for(int j = 0; j < c; j++) {
        if(arr[i][j]) {
          if(i - 1 >= 0 && arr[i - 1][j]) res++;
          if(j - 1 >= 0 && arr[i][j - 1]) res++;
        }
      }
    }
    return res;
  }

  if(j >= c) { i++; j = 0; }
  if(i >= r) { return 1e9; }

  arr[i][j] = true;
  int res = bf(k + 1, i, j + 1);
  arr[i][j] = false;
  return min(res, bf(k, i, j + 1));
}

int calc(int n, int fr, int corners, int edges, int cornerCost, int edgeCost) {
  cerr << "fr=" << fr << ",corners=" << corners << ",edges=" << edges << endl;

  int res = 0;
  n -= fr;

  if(n > 0) {
    res += min(corners, n) * cornerCost;
    n -= corners;
  }

  if(n > 0) {
    res += min(edges, n) * edgeCost;
    n -= edges;
  }

  if(n > 0) res += n * 4;
  return res;
}

int main() {
  int t; cin >> t;
  for(int tc = 1; tc <= t; tc++) {
    cerr << "case " << tc << endl;
    cin >> r >> c >> n;

    int res = bf(0, 0, 0);

    // int res = 0;

    // if(r == 1 || c == 1) {
    //   int cornerCost = 1;
    //   int edgeCost = 2;

    //   int fr = (r * c + 1) / 2;
    //   int corners = r * c % 2 == 0 ? 1 : 0;
    //   int edges = (r * c) / 2 - corners;

    //   res = calc(n, fr, corners, edges, cornerCost, edgeCost);

    // } else {
    //   int cornerCost = 2;
    //   int edgeCost = 3;

    //   int fr = (r * c + 1) / 2;
    //   int corners = r * c % 2 == 0 ? 2 : 0;
    //   int edges = r * c % 2 == 0 ? r + c - corners * 2 : 2 * (r / 2) + 2 * (c / 2);

    //   res = calc(n, fr, corners, edges, cornerCost, edgeCost);

    //   if(r * c % 2 != 0) {
    //     int frAlt = (r * c) / 2;
    //     int cornersAlt = 4;
    //     int edgesAlt = r + c + 2 - corners * 2;

    //     res = min(res, calc(n, frAlt, cornersAlt, edgesAlt, cornerCost, edgeCost));
    //   }
    // }

    cout << "Case #" << tc << ": " << res << endl;
  }
  return 0;
}
