#include <bits/stdc++.h>
using namespace std;

int main() {
  int t, n, m, k;
  scanf("%d", &t);
  int cs =0;
  while (t--) {
    scanf("%d %d %d", &n, &m, &k);
    ++cs;
    if (n > m) swap(n, m);
    if (n == 1) {
      int arr[4];
      arr[0] = (m+1)/2;
      arr[1] = 0;
      arr[2] = 0;
      arr[1] = m%2==0?1:0;
      arr[2] = (m-1)/2;
      int now = k;
      int res = 0;
      for (int i = 0; i <= 2; i++) {
        int diff = min(arr[i], now);
        res += diff * i;
        now -= diff;
      }
      printf("Case #%d: %d\n", cs, res);
    } else if (n % 2 == 0 && m % 2 == 0) {
      int arr[5];
      arr[0] = ((n*m)/2);
      arr[1] = 0;
      arr[2] = 2;
      arr[3] = 2*(n/2 - 1) + 2*(m/2 - 1);
      arr[4] = ((n-1)*(m-1)/2);
      int now = k;
      int res = 0;
      for (int i = 0; i <= 4; i++) {
        int diff = min(arr[i], now);
        res += diff * i;
        now -= diff;
      }
      printf("Case #%d: %d\n", cs, res);
    } else if (n%2 == 1 && m%2 == 1) {
      int arr[5];
      arr[0] = ((n*m)/2 + 1);
      arr[1] = 0;
      arr[2] = 0;
      arr[3] = 2*(n/2) + 2*(m/2);
      arr[4] = ((n-2)*(m-2)/2);
      int now = k;
      int res = 0;
      for (int i = 0; i <= 4; i++) {
        int diff = min(arr[i], now);
        res += diff * i;
        now -= diff;
      }

      int mini = res;
      arr[0] = n*m/2;
      arr[1] = 0;
      arr[2] = 4;
      arr[3] = n-3 + m-3;
      arr[4] = ((n-2)*(m-2))/2 + 1;
      now = k;
      res = 0;
      for (int i = 0; i <= 4; i++) {
        int diff = min(arr[i], now);
        res += diff * i;
        now -= diff;
      }

      mini = min(mini, res);
      printf("Case #%d: %d\n", cs, mini);
    } else {
      int arr[5];
      arr[0] = ((n*m)/2);
      arr[1] = 0;
      arr[2] = 2;
      arr[3] = n-2  + m-2;
      arr[4] = ((n-2)*(m-2)/2);
      int now = k;
      int res = 0;
      for (int i = 0; i <= 4; i++) {
        int diff = min(arr[i], now);
        res += diff * i;
        now -= diff;
      }
      printf("Case #%d: %d\n", cs, res);
    }
  }
}
