#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int T, B, M[1024], working[1024];
ll N;

ll taken(ll tm) {
  ll r = 0;
  for (int i=1; i<=B; i++)
    r += tm / M[i] + 1;
  return r;
}

int main() {
  cin >> T;
  for (int t=1; t<=T; t++) {
    int lcm=1;
    cin >> B >> N;
    for (int i=1; i<=B; i++)
      cin >> M[i];

    int index = 0, ans = 0;

    if (N <= B)
      ans = N;
    else {
      ll lo=0, hi=1000000000;
      hi*=102400;
      while (hi > lo) {
        ll mid = (lo+hi)/2;
        if (mid == lo) mid++;
        if (taken(mid) < N)
          lo = mid;
        else
          hi = mid-1;
      }
      N -= taken(hi);

      for (int i=1; i<=B; i++)
        working[i] = M[i] - hi % M[i];
    
      while (index < N) {
        for (int i=1; i<=B; i++) 
          if (working[i] == 0) {
            working[i] = M[i];
            if (++index == N) {
              ans = i;
              break;
            }
          }
        for (int i=1; i<=B; i++) 
          working[i]--;
      }
    }

    cout << "Case #" << t << ": " << ans << endl;
 }
}
