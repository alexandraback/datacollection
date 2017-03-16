#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int mincost(vector<vector<pair<char, int>>> & data, int col)
{
  int mincost = 10000000;
  for (int len = 1; len <= 101; ++len) {
    int cost = 0;
    for (int i = 0; i < data.size(); ++i) {
      cost += abs(len - data[i][col].second);
    }
    mincost = min(mincost, cost);
  }
  return mincost;
}

void go(vector<vector<pair<char, int>>> & data)
{
  int n = data[0].size();
  for (int i = 0; i < data.size(); ++i) if (data[i].size() != n) {
    cout << "Fegla Won" << endl;
    return;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < data.size(); ++j) if (data[j][i].first != data[0][i].first) {
      cout << "Fegla Won" << endl;
      return;
    }
  }
  int cost = 0;
  for (int i = 0; i < n; ++i) cost += mincost(data, i);
  cout << cost << endl;

}

int main()
{
  int ntc; cin >> ntc;
  for (int tc = 1; tc <= ntc; ++tc) {
    int n; cin >> n;
    string s;
    vector<vector<pair<char, int>>> data((n));
    getline(cin, s);
    for (int i = 0; i < n; ++i) {
      getline(cin, s);
      char last = ':';
      for (int j = 0; j < s.size(); ++j) {
        if (s[j] != last) {
          data[i].push_back(make_pair(s[j], 1));
        } else {
          data[i].back().second++;
        }
        last = s[j];
      }
    }
    cout << "Case #" << tc << ": ";
    go(data);
  }
}
