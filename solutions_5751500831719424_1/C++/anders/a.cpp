#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

string s[110];
int curr[110];
int counter[110];

int moves(int n) {
  int best = 100*100;
  for (int i=1; i<=100; ++i) {
    int num = 0;
    for (int j=0; j<n; ++j) {
      num += abs(counter[j]-i);
    }
    best = min(num, best);
  }
  return best;
}

int solve() {
  int n;
  cin >> n;
  int ans = 0;
  for (int i =0; i<n; ++i) {
    cin >> s[i];
    s[i] += "!"; //stop
    curr[i] = 0;
  }
  while (s[0][curr[0]] != '!') {
    char c = s[0][curr[0]];
    for (int i = 0; i<n; ++i) {
      if (s[i][curr[i]] != c) return -1;
      counter[i] = 1;

      while (s[i][curr[i]+1] == c) {
	++counter[i];
	++curr[i];
      }
    }
    ans += moves(n);
    for (int i =0; i<n; ++i) ++curr[i];
  }
  for (int i =0; i<n; ++i) if (s[i][curr[i]] != '!') return -1;
  return ans;
}

int main() {
  int c;
  cin >> c;
  for (int i=1; i<=c; ++i) {
    cout << "Case #" << i << ": ";
    int ans = solve();
    if (ans == -1) {
      cout << "Fegla Won" << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}

