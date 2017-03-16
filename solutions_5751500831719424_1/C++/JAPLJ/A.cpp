#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <numeric>
#include <algorithm>
#include <bitset>
#include <complex>
#include <array>

using namespace std;

typedef unsigned uint;
typedef long long Int;

const int INF = 1001001001;
const Int INFLL = 1001001001001001001LL;

template<typename T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
template<typename T> void chmin(T& a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T& a, T b) { if (a < b) a = b; }
int in() { int x; scanf("%d", &x); return x; }

void solve() {
  int N = in();
  vector<string> S(N);

  for (int i = 0; i < N; ++i) {
    cin >> S[i];
  }

  vector<vector<pair<char, int>>> I;
  for (int i = 0; i < N; ++i) {
    vector<pair<char, int>> si;
    for (int j = 0; j < S[i].size(); ) {
      int k = j;
      while (k < S[i].size() && S[i][j] == S[i][k]) ++k;
      si.push_back(make_pair(S[i][j], k - j));
      j = k;
    }
    I.emplace_back(si);
  }

  for (int i = 1; i < N; ++i) {
    bool match = I[0].size() == I[i].size();
    for (int j = 0; j < I[0].size(); ++j) {
      match &= I[0][j].first == I[i][j].first;
    }
    if (!match) {
      puts("Fegla Won");
      return;
    }
  }

  int res = 0;
  for (int i = 0; i < I[0].size(); ++i) {
    vector<int> freq;
    for (int j = 0; j < N; ++j) {
      freq.push_back(I[j][i].second);
    }
    sort(freq.begin(), freq.end());

    int target = freq[N / 2];
    for (int j = 0; j < N; ++j) {
      res += abs(target - freq[j]);
    }
  }

  printf("%d\n", res);
}

int main()
{
  int T = in();

  for (int CN = 1; CN <= T; ++CN) {
    printf("Case #%d: ", CN);
    solve();
  }

  return 0;
}
