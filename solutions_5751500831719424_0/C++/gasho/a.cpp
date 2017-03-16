#include <string>
#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
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
#include <ctime>
#include <fstream>
#include <queue>
#include <cassert>

using namespace std;

#define D(x) cout << #x << "=" << x << "\n"

string get_p(const string& s) {
  string p;
  char prev_c = ' ';
  for (const auto& c: s) {
    if (c != prev_c) {
      p.push_back(c);
    }
    prev_c = c;
  }
  return p;
}

int main(void) {
  int n_tests;
  cin >> n_tests;
  for (int test_case = 1; test_case <= n_tests; ++test_case) {
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
    }
    string p = get_p(v[0]);
    bool fail = false;
    for (int i = 1; i < n; ++i) {
      if (get_p(v[i]) != p) {
        fail = true;
        break;
      }
    }
    int result = 0;
    if (!fail) {
      vector<int> idx(n, 0);
      for (const auto& c: p) {
        vector<int> f(n, 0);
        for (int i = 0; i < n; ++i) {
          while (idx[i] < v[i].size() && v[i][idx[i]] == c) {
            ++idx[i];
            ++f[i];
          }
        }
        sort(f.begin(), f.end());
        int mid = f[n / 2];
        for (int i = 0; i < n; ++i) {
          result += abs(f[i] - mid);
        }
      }
    }
    cout << "Case #" << test_case << ": ";
    if (fail) {
      cout << "Fegla Won";
    } else {
      cout << result;
    }
    cout << "\n";
  }
  return 0;
}

