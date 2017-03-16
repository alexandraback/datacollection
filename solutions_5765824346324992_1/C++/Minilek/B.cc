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

int b, n, m[1001];

int main(int argc, char* argv[]) {
  int nocases;
  cin >> nocases;
  getchar();
  for (int rr = 1; rr <= nocases; ++rr) {
    cin >> b >> n;
    for (int i = 0; i < b; ++i)
      cin >> m[i];
    long long lo = 0, hi = 100000LL*2000000000LL, s, nz;
    while (lo+1 < hi) {
      long long mid = (lo+hi)/2;
      s = 0, nz = 0;
      for (int i = 0; i < b; ++i) {
	s += mid/m[i];
	if (mid % m[i] == 0)
	  ++nz;
      }
      if (s+b-nz >= n)
	hi = mid;
      else 
	lo = mid;
    }    
    int cur = 0;
    s = 0, nz = 0;
    for (int i = 0; i < b; ++i) {
      s += lo/m[i];
      if (lo % m[i] == 0)
	++nz;
    }
    s += b - nz;
    while (cur < b) {
      if (s == n-1 && lo%m[cur] == 0) {
	printf("Case #%d: %d\n", rr, cur+1);
	break;
      } else if (lo%m[cur] == 0)
	++s;
      ++cur;
    }
  }
  return 0;
}
