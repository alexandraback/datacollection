#define PRETEST
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <sstream>
using namespace std;

#define FILL(a,b) memset(a,b,sizeof(a))
#define SQR(a) ((a) * (a))

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef map<string, int> msi;
typedef map<int, int> mii;

const int INF = 0x4f4f4f4f;
const ll INFLL = 0x4f4f4f4f4f4f4f4f;

int main(int argc, char *argv[]) {
#ifdef PRETEST
  freopen("B-small.in", "r", stdin);
  freopen("out.txt", "w+", stdout);
#endif
  int T;
  scanf("%d", &T);
  for (int C = 1; C <= T; ++C) {
    int B, M;
    scanf("%d%d", &B, &M);
    vector<int> vec;
    for (int i = 0; i < B; ++i) {
      int x;
      scanf("%d", &x);
      vec.push_back(x);
    }
    ll hd = 0;
    ll tl = INFLL + 1;
    while (tl - hd > 1) {
      ll cnt = 0;
      ll mid = (hd + tl) / 2;
      for (int i = 0; i < B; ++i) {
        cnt += (mid + vec[i] - 1) / vec[i];
      }
      if (cnt < M) {
        hd = mid;
      } else {
        tl = mid;
      }
    }
    int ans = -1;
    {
      vector<pair<int, int> > tmp;
      int w, p = M;
      for (int i = 0; i < B; ++i) {
        w = vec[i] - hd % vec[i];
        if (w == vec[i]) {
          w = 0;
        }
        p -= (hd + w) / vec[i];
        tmp.push_back(make_pair(w, i + 1));
      }
      sort(tmp.begin(), tmp.end());
      ans = tmp[p - 1].second;
    }
    printf("Case #%d: %d\n", C, ans);
  }
  
  return 0;
}
