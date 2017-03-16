#include <iostream>
#include <algorithm>
using namespace std;

int p[10000];

int main() {
  int t; cin >> t;
  for (int T = 1; T <= t; T++) {
    cout << "Case #" << T << ": ";
    int n; cin >> n;
    for (int i = 0; i < n; i++)
      cin >> p[i];
    int a1 = 0;
    int mx = 0;
    for (int i = 0; i < n-1; i++) {
      if (p[i] > p[i+1])
        a1 += p[i]-p[i+1];
      mx = max(mx,p[i]-p[i+1]);
    }
    int a2 = 0;
    for (int i = 0; i < n-1; i++)
      a2 += min(mx,p[i]);
    cout << a1 << " " << a2 << "\n";
  }
  return 0;
}
