#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
//#include <utility>
//#include <set>
//#include <map>
//#include <queue>
#include <iomanip>
using namespace std;

#define mset(A,B) memset(A,B,sizeof(A));
#define mcpy(A,B) memcpy(A,B,sizeof(B));
typedef long long ll;
typedef long double ld;
typedef vector<int> vint;
//typedef vector<string> vstr;
#define FI(I,L,U) for (int I=L;I<U;I++)
#define sqr(x) ((x)*(x))

int r, c, n, m;
int bestans;
int mask[16][2];

void solve(int k, int t, int masks, int noise) {
  if (t == n) {
    if (noise < bestans) {
      bestans = noise;
      //cerr << "bestans=" << bestans << " t=" << t << " masks=" << masks << endl;
    }
    return;
  }
  if (k >= m) return;
  if (m - k + t < n) return;
  solve(k + 1, t, masks, noise);
  if (masks & mask[k][0]) noise++;
  if (masks & mask[k][1]) noise++;
  masks |= 1 << k;
  solve(k + 1, t + 1, masks, noise);
}

int main()
{
  int tcase = 0;
  ifstream fin("z.in");
  ofstream fout("z.out");
  fin >> tcase;
  for (int tind = 1; tind <= tcase; tind++) {
    //istringstream strin();
    fin >> r >> c >> n;
    if (r > c) swap(r, c);
    int ans = 0;
    if (/*true ||*/ n > (r * c + 1)/2) {
      if (/*false &&*/ r >= 2 && c >= 2 && n >= r * c - ((r-2)*(c-2)+1)/2) {
        ans = r * c * 2 - r - c - 4 * (r*c-n);
      } else {
        // update mask;
        bestans = r * c * 2 - r - c;
        m = r * c;
        for (int i = 0; i < r; i++) {
          for (int j = 0; j < c; j++) {
            int k = i * c + j;
            mask[k][0] = (i > 0) ? (1 << (k - c)) : 0;
            mask[k][1] = (j > 0) ? (1 << (k - 1)) : 0;
          }
        }
        solve(0, 0, 0, 0);
        ans = bestans;
      }
    }
    fout << "Case #" << tind << ": " << ans << endl;
  }
  return 0;
}
