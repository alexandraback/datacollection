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

typedef long long ll;

vector<int> m;

int main () {
  std::ios::sync_with_stdio(false);
  int t;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    int b, n, ans = 0;
    cin >> b >> n;
    m.clear();
    m.resize(b);
    for (int i = 0; i < b; i++) {
      cin >> m[i];
    }
    ll lo = 0, hi = 1e15;
    while (true) {
      ll mid = (lo + hi) / 2, started = 0, freed = 0;
      vector<bool> free(b, false);
      for (int i = 0; i < b; i++) {
	started += mid / m[i];
	if (mid % m[i] == 0) {
	  freed++;
	  free[i] = true;
	}
	else {
	  started++;
	}
      }
      if (started > n - 1) {
	hi = mid - 1;
      }
      else if (started + freed < n) {
	lo = mid + 1;
      }
      else {
	int pos = n - started - 1, cur = 0;
	for (int i = 0; i < b; i++) {
	  if (free[i]) {
	    if (cur == pos) {
	      ans = i + 1;
	    }
	    cur++;
	  }
	}
	break;
      }
    }
    cout << "Case #" << i << ": " << ans << endl;
  }
  return 0;
}
