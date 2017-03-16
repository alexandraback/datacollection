#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <sstream>
using namespace std;
pair<string, vector<int> > canonical(string s) {
  string ret = "";
  vector<int> v;
  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    ++cnt;
    if ((i+1==s.size()) || (s[i]!=s[i+1])) {
      ret += string(1, s[i]);
      v.push_back(cnt);
      cnt = 0;
    }
  }
  return make_pair(ret, v);
}
int main(int argc, char* argv[]) {
  int nocases;
  cin >> nocases;
  getchar();
  for (int rr = 1; rr <= nocases; ++rr) {
    int n;
    cin >> n;
    string strs[n];
    vector< vector<int> > cnts;
    for (int i = 0; i < n; ++i)
      cin >> strs[i];
    pair<string, vector<int> > p = canonical(strs[0]);
    string a = p.first;
    cnts.push_back(p.second);
    bool bad = false;
    for (int i = 1; i < n; ++i) {
      p = canonical(strs[i]);
      if (p.first != a) {
	bad = true;
	break;
      }
      cnts.push_back(p.second);
    }
    if (bad) {
      printf("Case #%d: Fegla Won\n", rr);
      continue;
    }
    int tot = 0;
    for (int i = 0; i < a.size(); ++i) {
      int best = 1000000000;
      for (int j = 1; j < 150; ++j) {
	int r = 0;
	for (int k = 0; k < n; ++k)
	  r += abs(cnts[k][i] - j);
	best = min(r, best);
      }
      tot += best;
    }
    printf("Case #%d: %d\n", rr, tot);
  }
  return 0;
}
