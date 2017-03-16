#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <utility>
#include <algorithm>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <list>
#include <iomanip>
#include <ctime>
#include <cassert>
#include <unordered_map>
#include <unordered_set>

#define WHAT_IS(x) cout << #x << " is " << x << endl;

using namespace std;

typedef long long LL;

vector<int> alls;

int main () {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int n, ans1 = 0, ans2 = 0, maxd = 0;
    cin >> n;
    alls.clear();
    alls.resize(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> alls[i];
    }
    for (int i = 1; i < n; i++) {
      if (alls[i] < alls[i - 1]) {
	ans1 += alls[i - 1] - alls[i];
	maxd = max(maxd, alls[i - 1] - alls[i]);
      }
    }
    for (int i = 0; i < n - 1; i++) {
      ans2 += min(alls[i], maxd);
    }
    cout << "Case #" << i << ": " << ans1 << " " << ans2 << endl;
  }
  return 0;
}
