#include <iostream>
#include <functional>
#include <vector>
#include <limits>
#include <algorithm>
#include <sstream>

using namespace std;

typedef pair<char, int> multichar_t;

vector<multichar_t> convert_str(string s) {
  char p = '\0';
  vector<multichar_t> res;
  for (auto c : s) {
    if (c == p) {
      ++res.back().second;
    } else {
      res.push_back({c, 1});
      p = c;
    }
  }

  return res;
}


string solve(vector<vector<multichar_t>> const & strs) {
  int size = strs[0].size();
  for (auto & s : strs) {
    if (s.size() != size)
      return "Fegla Won";
  }

  auto find_mid = [](std::vector<int> const & v) {
    int upper = *max_element(v.begin(), v.end());
    int lower = *min_element(v.begin(), v.end());

    int res = numeric_limits<int>::max();
    for (int x = lower; x <= upper; ++x) {
      int sum = 0;
      for (auto el : v) {
        sum += abs(el - x);
      }

      if (sum < res)
        res = sum;
    }

    return res;
  };

  int res = 0;
  for (int n = 0; n < size; ++n) {
    char c = strs[0][n].first;
    vector<int> cts;
    for (int sn = 0; sn < strs.size(); ++sn){
      if (strs[sn][n].first != c)
        return "Fegla Won";

      cts.push_back(strs[sn][n].second);
    }
    res += find_mid(cts);
  }

  ostringstream ss;
  ss << res;
  return ss.str();
}

int main() {
  int n;
  cin >> n;

  for (int test_case = 0; test_case < n; ++test_case) {
    int str_count;
    cin >> str_count;

    vector<vector<multichar_t>> all;
    for (int str_n = 0; str_n < str_count; ++str_n) {
      string s;
      cin >> s;
      all.push_back(convert_str(s));
    }

    cout << "Case #" << (test_case + 1) << ": " << solve(all) << "\n";
  }

}
