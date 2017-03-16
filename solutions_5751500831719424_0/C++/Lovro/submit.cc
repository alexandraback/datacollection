#define NDEBUG
#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T, typename U> inline void makemin(T &res, const U &x) {
  if (x < res) {
    res = x;
  }
}
#define ALL(x) (x).begin(), (x).end()

string remove_dups(string str) {
  str.erase(unique(ALL(str)), str.end());
  return str;
}

void rle(const string &str, vector<int> &cnt) {
  assert(cnt.empty());
  cnt.push_back(1);
  for (int i=1; i<(int)str.size(); ++i) {
    if (str[i] == str[i-1]) {
      ++cnt.back();
    } else {
      cnt.push_back(1);
    }
  }
}

int solve_column(const vector<int> &v) {
  int ans = INT_MAX/2;
  for (int x : v) {
    int cost = 0;
    for (int y : v) {
      cost += abs(y-x);
    }
    makemin(ans, cost);
  }
  return ans;
}

void solve1() {
  int N;
  cin >> N;

  vector<string> strs(N);
  for (string& str : strs) {
    cin >> str;
  }

  for (int i=1; i<N; ++i) {
    if (remove_dups(strs[0]) != remove_dups(strs[i])) {
      printf("Fegla Won\n");
      return;
    }
  }

  vector<vector<int> > counts(N);
  for (int i=0; i<N; ++i) {
    rle(strs[i], counts[i]);
    assert(counts[0].size() == counts[i].size());
  }

  int nruns = counts[0].size();
  int ans = 0;
  for (int j=0; j<nruns; ++j) {
    vector<int> cnt(N);
    for (int i=0; i<N; ++i) {
      cnt[i] = counts[i][j];
    }
    ans += solve_column(cnt);
  }
  printf("%d\n", ans);
}

int main() {
  ios_base::sync_with_stdio(0);

  int T;
  cin >> T;
  for (int tt=1; tt<=T; ++tt) {
    printf("Case #%d: ", tt);
    solve1();
    fflush(stdout);
  }
}
