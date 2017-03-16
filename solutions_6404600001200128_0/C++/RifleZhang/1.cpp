#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;

void solve (int tmp) {
  int a[5000];
  int n, ans1 = 0, ans2 = 0, ma = 0;
  cin >> n;
  for (int i=1; i<=n; i++) cin >> a[i];
  for (int i=2; i<=n; i++)
    if (a[i] < a[i-1])
      ans1 += a[i-1] - a[i];
  for (int i=2; i<=n; i++)
    if (ma < (a[i-1] - a[i]))
      ma = a[i-1] - a[i];
  for (int i=1; i<n; i++)
    if (a[i] < ma)
      ans2+=a[i];
    else ans2+=ma;
  // cout << ma << endl;
  cout << "Case #" << tmp << ": " << ans1 << " " << ans2 << endl;
  
}
int main () {

  int t = 0, tmp = 0;
  cin >> t;
  while (t) {
    tmp++;
    solve (tmp);
    t--;
  }
}
