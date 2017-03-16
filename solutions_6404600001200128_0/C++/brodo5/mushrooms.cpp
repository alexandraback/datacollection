#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <iterator>

#if DEBUG
#include "prettyprint.hpp"
#define print_container(c) cout << c << endl;
#endif

using namespace std;

string FILENAME = "A-small-attempt0";

vector<int> read(string s){
  vector<int> ret;
  int n;
  istringstream sin(s);
  while(sin>>n)
    ret.push_back(n);
  return ret;
}

int main () {
  setvbuf(stdout, NULL, _IONBF, 0);
  freopen((FILENAME + ".in").c_str(), "r", stdin);
  freopen((FILENAME + ".out").c_str(), "w", stdout);
  int testcases;
  scanf("%d", &testcases);
  for (int case_id = 1; case_id <= testcases; case_id++) {
    printf("Case #%d: ", case_id);
    int n;
    scanf("%d", &n);
    vector<int> nums;
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      nums.push_back(a);
    }
    int first = 0;
    int second = 0;
    int biggest_drop = 0;
    for (int i = 0; i < n - 1; i++) {
      int before = nums[i];
      int after = nums[i + 1];
      if (after < before) {
        first += before - after;
        if (before - after > biggest_drop) {
          biggest_drop = before - after;
        }
      }
    }
    int rate = biggest_drop;
    for (int i = 0; i < n - 1; i++) {
      int num = nums[i];
      second += min(nums[i], rate);
    }
    printf("%d %d\n", first, second);
  }
  fflush(stdout);
}
