#include <iostream>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <algorithm>
#include <math.h>
using namespace std;

int gcd (int a, int b) {
  return a%b == 0 ? b : gcd (b, a%b);
}
void solve (int tmp) {
  int a[5000], b[5000], n, m, ans = 0;
  cin >> m >> n;
  for (int i=1; i<=m; i++) cin >> a[i];
  for (int i=1; i<=m; i++) b[i] = 0;
  long long tot1 = 1, tot2 = 0;
  for (int i=1; i<=m; i++)
    tot1 = tot1*a[i]/gcd(tot1, a[i]);
  for (int i=1; i<=m; i++)
    tot2 += tot1/a[i];
  //cout << tot1 << " " << tot2 << endl;
  //cout << n << endl;
  n = n%tot2;
  //cout << n << endl;
  if (n == 0) n = tot2;
  int now = 1;
  while (now < n) {
    int f = 0;
    for (int i=1; i<=m; i++)
      if (b[i] == 0) {
	b[i] = a[i];
	f = 1;
	break;
      }
    if (f==1) 
      {now++; continue;}
    int mi = 2147000000;
    for (int i=1; i<=m; i++)
      if (b[i] < mi) mi = b[i];
    for (int i=1; i<=m; i++) b[i] -= mi;
  }
 
  int mi = 2147000000;
  for (int i=1; i<=m; i++)
    if (b[i] < mi) 
      {mi = b[i]; ans = i;}

  cout << "Case #" << tmp << ": " << ans << endl;
  
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
