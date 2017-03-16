#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {
  int nocases;
  cin >> nocases;
  getchar();
  for (int rr = 1; rr <= nocases; ++rr) {
    vector<int> v = vector<int>();
    int n, x = 0, y = 0, t = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      int j;
      cin >> j;
      v.push_back(j);
      if (i > 0) {
	x += max(0, v[i-1] - j);
	t = max(t, v[i-1] - j);
      }
    }
    for (int i = 0; i+1 < n; ++i)
      y += min(t, v[i]);
    printf("Case #%d: %d %d\n", rr, x, y);
  }
  return 0;
}
