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

string FILENAME = "B-small-attempt1";

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
    int b, n;
    scanf("%d %d", &b, &n);
    vector<int> m;
    for (int i = 0; i < b; i++) {
      int a;
      scanf("%d", &a);
      m.push_back(a);
    }
    int product = 1;
    for (int i = 0; i < m.size(); i++) {
      product *= m[i];
    }
    int total_cuts_in_cycle = 0;
    for (int i = 0; i < m.size(); i++) {
      total_cuts_in_cycle += product / m[i];
    }
    int cycles = n / total_cuts_in_cycle;
    n -= total_cuts_in_cycle * cycles;
    vector<int> times;
    for (int i = 0 ; i < b; i++) {
      times.push_back(0);
    }
    if (n == 0) {
      printf("%d\n", b);
      continue;
    }
    for (int i = 0; i < product; i++) {
      bool done = false;
      for (int j = 0; j < m.size(); j++) {
        if (i % m[j] == 0) {
          if (n == 1) {
            printf("%d\n", j + 1);
            done = true;
            break;
          }
          n--;
        }
      }
      if (done) {
        break;
      }
    }
  }
  fflush(stdout);
}
