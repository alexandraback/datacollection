#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <iterator>
#include <ctime>
#include <iomanip>
#include <stdint.h>

typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

using namespace std;

#define ALL(a) a.begin(), a.end()
#define FOR(a) for (int i = 0; i < a; ++i)
#define D(a) #a << ": " << a << "\n"

int popcount(int n)
{
  int res = 0;
  while (n)
    res += n & 1,
    n >>= 1;
  return res;
}

int main()
{
  int CASES = 100000;
  cin >> CASES;
  for (int CASE = 1; CASE <= CASES; ++CASE)
  {
    int r, c, n;
    cin >> r >> c >> n;

    int limit = 1<<(r*c);
    int res = 1000000;
    for (int mask = 0; mask < limit; ++mask)
    {
      if (popcount(mask) != n)
        continue;

      vector<vector<int>> arr(r, vector<int>(c));
      for (int i = 0; i < r; ++i)
      {
        for (int j = 0; j < c; ++j)
        {
          if (mask & (1<<(i*c+j)))
            arr[i][j] = 1;
        }
      }

      int curr = 0;

      for (int i = 0; i < r; ++i)
        for (int j = 1; j < c; ++j)
          if (arr[i][j] && arr[i][j-1])
            ++curr;

      for (int j = 0; j < c; ++j)
        for (int i = 1; i < r; ++i)
          if (arr[i][j] && arr[i-1][j])
            ++curr;

      res = min(res, curr);
    }

    printf("Case #%d: ", CASE);
    cout << res << endl;

  }

  return 0;
}