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
    int n;
    cin >> n;
    vector<int> arr(n);
    FOR(n) scanf("%d", &arr[i]);

    int64 first = 0, second = 0;
    int diff = 0;
    for (int i = 1; i < n; ++i)
    {
      first += max(0, arr[i - 1] - arr[i]);
      diff = max(diff, arr[i - 1] - arr[i]);
    }

    for (int i = 0; i < n-1; ++i)
    {
      second += min(diff, arr[i]);
    }

    printf("Case #%d: ", CASE);
    cout << first << " " << second << endl;
  }

  return 0;
}