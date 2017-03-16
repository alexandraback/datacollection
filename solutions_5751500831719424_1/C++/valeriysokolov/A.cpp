#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <string>
#include <cstdlib>
#include <limits>

using namespace std;


typedef vector<pair<char, int> > CompVec;
typedef long long Int;

CompVec compress(const string &s) {
  CompVec vec;
  int start = 0;
  int len = s.length();
  while (start < len) {
    pair<char, int> cur = make_pair(s[start], 1);
    int i = start + 1;
    while (i < len && s[i] == cur.first) {
      ++cur.second;
      ++i;
    }
    start = i;
    vec.push_back(cur);
  }

  return vec;
}

Int local_cost(vector<Int> &v) {
  int len = v.size();
  Int cost = numeric_limits<Int>::max();
  for (Int x = 1; x <= 100; ++x) {
    Int loc_cost = 0;
    for (int i = 0; i < len; ++i) {
      loc_cost += abs(x - v[i]);
    }
    cost = min(cost, loc_cost);
  }
  return cost;
}

void solve(int test_num) {
  int n;
  cin >> n;
  vector<CompVec> invec(n);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    invec[i] = compress(s);
  }

  // Check lengths
  int comp_len = invec[0].size();
  for (int i = 1; i < n; ++i) {
    if (comp_len != invec[i].size()) {
      cout << "Case #" << test_num << ": Fegla Won\n";
      return;
    }
  }
  
  for (int i = 0; i < comp_len; ++i) {
    char ch = invec[0][i].first;
    for (int j = 1; j < n; ++j) {
      if (ch != invec[j][i].first) {
        cout << "Case #" << test_num << ": Fegla Won\n";
        return;
      }
    }
  }

  // Compute cost.
  Int cost = 0;
  for (int i = 0; i < comp_len; ++i) {
    vector<Int> v(n);
    for (int j = 0; j < n; ++j) {
      v[j] = invec[j][i].second;
    }

    cost += local_cost(v);
  }

  cout << "Case #" << test_num << ": " << cost << endl;
}

int main() {
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    solve(i);
  }
  return 0;
}
