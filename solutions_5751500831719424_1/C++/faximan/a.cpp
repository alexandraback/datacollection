#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>
#include <math.h>
#include <stack>
#include <queue>
#include <stdio.h>

using namespace std;

#define INF 0x3FFFFFFF

int n;

int sol[101][101];

string charString(string s, int idx) {
  string res = "";
  int cur = -1;
  char a = '$';
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != a) {
      a = s[i];
      res += a;
      cur++;
    }
    sol[idx][cur]++;
  }

  return res;
}

int main() {
  int c;
  cin >> c;
  for (int cc = 1; cc <= c; cc++) {
    for (int j = 0; j < 101; j++)
      for (int k = 0; k < 101; k++)
        sol[j][k] = 0;
    cin >> n;
    vector<string> v;
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      v.push_back(s);
    }

    bool ok = true;
    string res = charString(v[0], 0);
    for (int i = 1; i < n; i++) {
      string cur = charString(v[i], i);
      if (res != cur) {
        ok = false;
      }
    }

    if (!ok) {
      printf("Case #%d: Fegla Won\n", cc);
    } else {
      int ans = 0;
      for (int i = 0; i < res.length(); i++) {
        int best = INF;
        for (int j = 0; j < 101; j++) {


          int cur = 0;
          for (int k = 0; k < n; k++) {
            cur += abs(j - sol[k][i]);
          }
          best = min(best, cur);
        }
        ans += best;
      }
    printf("Case #%d: %d\n", cc, ans);
  }
}


  return 0;
}
