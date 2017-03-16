#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> h[110];
string base[110];

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      h[i].clear(); base[i] = "";
      string s; cin >> s;
      for (int j = 0; j < s.size(); j++) {
        if (j == 0 || s[j] != s[j-1]) {
          h[i].push_back(0);
          base[i] += s[j];
        }
        h[i][h[i].size()-1]++;
      }
    }

    bool poss = true;
    for (int i = 0; i < n; i++)
      if (base[i] != base[0])
        poss = false;

    cout << "Case #" << c << ": ";
    if (!poss) cout << "Fegla Won" << endl;
    else {
      int res = 0;
      for (int i = 0; i < h[0].size(); i++) {
        int best = 1000000000;
        for (int len = 1; len <= 100; len++) {
          int cur = 0;
          for (int j = 0; j < n; j++) cur += abs(h[j][i] - len);
          best = min(best, cur);
        }
        res += best;
      }
      cout << res << endl;
    }
  }
  return 0;
}
