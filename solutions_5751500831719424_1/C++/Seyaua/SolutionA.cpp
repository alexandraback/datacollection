#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cmath>
#include <queue>
#include <ctime>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

const int maxN = 110;

string s[maxN];
vector <int> curval[maxN];

void solve(int tcase) {
  printf("Case #%d: ", tcase);
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }

  vector <char> tmp;
  vector <int> mns;
  vector <int> mxs;
  for (int i = 0; i < s[0].length(); ++i) {
    tmp.push_back(s[0][i]);
    int j = i;
    while (j < s[0].length() && s[0][j] == s[0][i]) {
      ++j;
    }
    mns.push_back(j - i);
    mxs.push_back(j - i);
    i = j - 1;
  }

  curval[0] = mns;

  for (int i = 1; i < n; ++i) {
    string cur = s[i];
    vector <char> ntmp;
    vector <int> nmns;
    vector <int> nmxs;
    for (int i = 0; i < cur.length(); ++i) {
      ntmp.push_back(cur[i]);
      int j = i;
      while (j < cur.length() && cur[j] == cur[i]) {
        ++j;
      }
      nmns.push_back(j - i);
      nmxs.push_back(j - i);
      i = j - 1;
    }
    if (ntmp != tmp) {
      cout << "Fegla Won" << endl;
      return;
    }

    for (int j = 0; j < tmp.size(); ++j) {
      mns[j] = min(mns[j], nmns[j]);
      mxs[j] = max(mxs[j], nmxs[j]);
    }
    curval[i] = nmns;
  }

  int total = 0;

  for (int i = 0; i < tmp.size(); ++i) {
    int mn = 1000000000;
    for (int j = mns[i]; j <= mxs[i]; ++j) {
      int cur = 0;
      for (int k = 0; k < n; ++k) {
        cur += abs(curval[k][i] - j);
      }
      mn = min(mn, cur);
    }
    total += mn;
  }
  cout << total << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t;
  scanf("%d", &t);

  for (int i = 0; i < t; ++i) {
    solve(i + 1);
  }

  return 0;
}
