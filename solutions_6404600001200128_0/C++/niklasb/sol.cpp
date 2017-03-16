#include <bits/stdc++.h>
using namespace std;
int a[1001];
int main() {
  int T; cin >> T;
  for (int tc = 1; tc <= T; ++tc) {
    cout << "Case #" << tc << ": ";
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int a1 = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] < a[i-1]) a1 += a[i-1] - a[i];
    }
    double a2 =  0;
    double rate = 0;
    for (int i = 1; i < n; ++i) {
      if (a[i] < a[i-1]) {
        rate = max(rate,(a[i-1]-a[i])/10.0);
        //rate = max(rate, (a[i-1]-a[i]+9)/10);
      }
    }
    //cout << rate << endl;
    for (int i = 0; i < n-1; ++i) {
      a2 += min(rate * 10.0, (double)a[i]);
    }
    cout << a1 << " " << (int)a2 << endl;
  }
}
