#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(auto i = (c).begin(); i != (c).end(); ++i)
#define BIT(n, m) (((n) >> (m)) & 1)

typedef long long ll;

const ll inf = 1e15;
const ll mod = 1000 * 1000 * 1000 + 7;
const double eps = 1e-9;

void solve(){
  int R, C, N;
  cin >> R >> C >> N;

  int res = 1e9;
  REP(mask, 1 << (R * C)){
    if (__builtin_popcount(mask) == N){
      int cost = 0;
      REP(i, R * C) REP2(j, i + 1, R * C){
        int r_i = i / C, r_j = j / C;
        int c_i = i % C, c_j = j % C;
        if (abs(r_i - r_j) + abs(c_i - c_j) == 1 && BIT(mask, i) == 1 &&  BIT(mask, j) == 1){
          cost++;
        }
      }
      res = min(res, cost);
    }
  }
  cout << res << endl;
}
 
int main(){
  int T;
  cin >> T;
  REP(t, T){
    printf("Case #%d: ", t + 1);
    solve();
  }
  return 0;
}
