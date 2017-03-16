#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int CASE = 1; CASE <= T; CASE++) {
    int N;
    cin >> N;
    string str;
    vector<vector<pair<char, int>>> strs(N);
    set<string> mss;
    for (int i = 0; i < N; i++) {
      cin >> str;
      for (char c : str) {
        if (strs[i].empty() || strs[i].back().first != c) {
          strs[i].emplace_back(c, 1);
        } else {
          strs[i].back().second++;
        }
      }
      string ms;
      for (auto p : strs[i])
        ms += p.first;
      mss.insert(ms);
    }
    cout << "Case #" << CASE << ": ";
    if (mss.size() > 1) {
      cout << "Fegla Won";
    } else {
      int res = 0;
      for (int ii = 0; ii < strs[0].size(); ii++) {
        map<int, int> cnt;
        for (int iii = 0; iii < N; iii++)
          cnt[strs[iii][ii].second]++;
        if (cnt.size() == 1)
          continue;
        vector<pair<int, int>> pcnt(cnt.begin(), cnt.end());
        int tr = 100000;
        for (int i = 0; i < pcnt.size(); i++) {
          int t = 0;
          for (int j = 0; j < pcnt.size(); j++) if (i != j)
            t += abs(pcnt[i].first - pcnt[j].first) * pcnt[j].second;
          tr = min(tr, t);
        }
        res += tr;
      }
      cout << res;
    }
    cout << endl;
  }
}