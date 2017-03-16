#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1 << 28;


int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;
    vector<string> s(N);
    string a;
    for (int i = 0; i < N; i++) cin >> s[i];
    a = s[0];
    a.erase(unique(a.begin(), a.end()), a.end());

    bool ok = true;
    for (int i = 1; i < N; i++) {
      string r = s[i];
      r.erase(unique(r.begin(), r.end()), r.end());
      if (a != r) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      cout << "Fegla Won" << endl;
      continue;
    }

    vector<vector<int>> b(N, vector<int>(a.size()));
    for (int i = 0; i < N; i++) {
      int p = 0;
      for (int j = 0; j < a.size(); j++) {
        while (s[i][p] == a[j]) {
          b[i][j]++;
          p++;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < a.size(); i++) {
      int r = INF;
      for (int j = 0; j < N; j++) {
        int sum = 0;
        for (int k = 0; k < N; k++) {
          sum += abs(b[j][i] - b[k][i]); 
        }
        r = min(r, sum);
      }
      ans += r;
    }
    cout << ans << endl;
  }
}