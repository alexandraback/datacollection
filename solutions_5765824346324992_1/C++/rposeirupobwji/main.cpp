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

typedef unsigned int uint32;
typedef signed long long int64;
typedef unsigned long long uint64;

using namespace std;

#define ALL(a) a.begin(), a.end()
#define FOR(a) for (int i = 0; i < a; ++i)
#define D(a) #a << ": " << a << "\n"

int main()
{
  int CASES; cin >> CASES;
  for (int CASE = 1; CASE <= CASES; ++CASE)
  {
    int b, n;
    cin >> b >> n;
    vector<int> arr(b);
    FOR(b) scanf("%d", &arr[i]);

    int64 start = 0, end = 1000000000LL * 100000 + 5;

    if (n <= b)
    {
      printf("Case #%d: %d\n", CASE, n);
      continue;
    }

    int64 res = 0, lowerB, upperB;
    while (start <= end)
    {
      int64 mid = (start + end) / 2;

      lowerB = 0, upperB = 0;
      for (int i = 0; i < b; ++i)
      {
        lowerB += (mid - 1) / arr[i] + 1;
        upperB += mid / arr[i] + 1;
      }

      if (lowerB < n && n < upperB)
      {
        res = mid;
        break;
      }
      else if (lowerB >= n)
        end = mid - 1;
      else if (upperB <= n)
        start = mid + 1;
      else
        assert(false);
    }

    if (!res)
      res = start - 1;

    for (int i = 0; i < b; ++i)
    {
      n -= (res - 1) / arr[i] + 1;
    }

    assert(n > 0);

    for (int i = 0; i < b; ++i)
    {
      if (res % arr[i] == 0)
        --n;

      if (!n)
      {
        res = i + 1;
        break;
      }
    }


    printf("Case #%d: %d\n", CASE, res);
  }

  return 0;
}