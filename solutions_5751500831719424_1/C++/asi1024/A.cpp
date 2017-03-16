#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

int solve(vector<vector<pair<char,int>>> &vs) {
  REP(i,vs.size()) {
    if (vs[0].size() != vs[i].size()) return -1;
    REP(j,vs[0].size())
      if (vs[0][j].first != vs[i][j].first) return -1;
  }
  int res = 0;
  REP(j,vs[0].size()) {
    vector<int> v;
    REP(i,vs.size()) v.push_back(vs[i][j].second);
    sort(v.begin(), v.end());
    //REP(i,v.size()) cout << v[i] << " "; cout << endl;
    REP(i,v.size()) res += abs(v[v.size()/2] - v[i]);
  }
  return res;
}

int main() {
  int t, n;
  cin >> t;
  REP(cas,t) {
    cin >> n;
    vector<vector<pair<char,int>>> vs(n);
    string str;
    REP(i,n) {
      cin >> str;
      REP(j,str.size()) {
        if (vs[i].size() > 0 && vs[i][vs[i].size()-1].first == str[j])
          vs[i][vs[i].size()-1].second++;
        else
          vs[i].push_back(make_pair(str[j], 1));
      }
    }
    int res = solve(vs);
    if (res == -1)
      printf("Case #%d: Fegla Won\n", cas+1);
    else
      printf("Case #%d: %d\n", cas+1, res);
  }
  return 0;
}
