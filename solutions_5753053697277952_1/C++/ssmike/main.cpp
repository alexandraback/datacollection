#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <iomanip>
using namespace std;

#define INF 1e+9
#define mp make_pair
#define lint long long
#define pii pair<int, int>

#define MAXN 30

int p[MAXN];

int getmax(int n) {
  int r = 0;
  for (int i = 0; i < n; i++) {
    if (p[i] > p[r])
      r = i;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(false);
  cout << setprecision(10) << fixed;
  freopen("inp", "r", stdin);
  freopen("outp", "w", stdout);
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cout << "Case #" << i + 1 << ": ";
    int n; cin >> n;
    for (int j = 0; j < n; j++) {
      cin >> p[j];
    }
    int gz = 0;
    for (int i = 0; i < n; i++)
      gz += p[i] > 0;
    while (gz > 0) {
      if (gz == 2) {
        cout << " ";
        for (int i = 0; i < n; i++) {
          if (p[i] > 0) {
            cout << (char)('A' + i);
            p[i]--;
            gz -= p[i] == 0;
          }
        }
      } else {
        int m = getmax(n);
        cout << " " << (char)('A' + m);
        p[m]--;
        gz -= p[m] == 0;
      }
    }
    cout << endl;
  }
}
