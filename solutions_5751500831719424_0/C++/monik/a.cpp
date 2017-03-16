#include <algorithm>

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cassert>

#include <cmath>
#include <complex>
#include <cstring>

#define SIZE(s) ((int)((s).size()))
#define FOREACH(it,vec) for(typeof((vec).begin())it=(vec).begin();it!=(vec).end();++it)
#define REP(i,n) for(int i=0;i<(int)(n);++i)

using namespace std;

int N,T;

int main(void) {
  cin >> T;
  REP(t, T) {
    string s;
    long long poc = 0;
    cin >> N;
    vector<vector<pair<int, char> > > W(N);
    REP(n,N) {
      cin >> s;
      REP(i, SIZE(s)) {
        if (SIZE(W[n]) == 0) W[n].push_back(make_pair(1, s[i]));
        else {
          if (W[n].back().second == s[i]) ++W[n].back().first;
          else W[n].push_back(make_pair(1, s[i]));
        }
      }
    }
    int M = SIZE(W[0]);
    bool wrong = false;
    REP(n,N) if (SIZE(W[n]) != M) {
      wrong = true;
      break;
    }
    if (wrong) {
      cout << "Case #" << t + 1 << ": Fegla Won" << endl;
      continue;
    }
    
    REP(n,N) REP(m, M) if (W[n][m].second != W[0][m].second) {
      wrong = true;
      break;
    }
    if (wrong) {
      cout << "Case #" << t + 1 << ": Fegla Won" << endl;
      continue;
    }

    REP(m, M) {
      vector<int> p;
      REP(n, N) p.push_back(W[n][m].first);
      sort(p.begin(), p.end());
      int med = p[SIZE(p) / 2];
      REP(n, N) poc += abs(W[n][m].first - med);
    }
    cout << "Case #" << t + 1 << ": " << poc << endl;
  }
  return 0;
}
