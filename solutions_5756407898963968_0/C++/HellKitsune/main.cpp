#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int main() {
  freopen("input0.txt", "r", stdin);
  freopen("output0.txt", "w", stdout);
  int t;
  cin >> t;
  REP(test, t) {
    int k[2], a[2][4][4];
    int b[16] = {};
    int flag = -1;
    REP(i, 2) {
      cin >> k[i];
      REP(j, 4) REP(q, 4)
        cin >> a[i][j][q];
    }
    REP(i, 4) {
      ++b[a[0][k[0] - 1][i] - 1];
      ++b[a[1][k[1] - 1][i] - 1];
    }
    REP(i, 16) if (b[i] == 2) {
      if (flag == -1)
        flag = i + 1;
      else
        flag = -2;
    }
    if (flag == -1)
      cout << "Case #" << test + 1 << ": Volunteer cheated!" << endl;
    else if (flag == -2)
      cout << "Case #" << test + 1 << ": Bad magician!" << endl;
    else
      cout << "Case #" << test + 1 << ": " << flag << endl;
  }
  return 0;
}
