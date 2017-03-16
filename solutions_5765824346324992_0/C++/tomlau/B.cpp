#include <iostream>
#include <algorithm>
using namespace std;

int T, i;

int main() {
  cin >> T;
  for (int t=1; t<=T; t++) {
    int B, N, M[1024], working[1024];
    int lcm=1;
    cin >> B >> N;
    for (int i=1; i<=B; i++) {
      cin >> M[i];
      working[i] = 0;
      lcm = max(lcm, M[i]);
    }

    // bruteforce LCM :)
    bool found = false;
    while (!found) {
      found = true;
      for (int i=1; i<=B; i++)
        if (lcm % M[i] > 0) {
          found = false;
          break;
        }
      if (!found)
        lcm++;
    }

    int period = 0;
    for (int i=1; i<=B; i++)
      period += lcm / M[i];

    N = N % period;
    if (N == 0) N = period;

    int index = 0, ans = 0;
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

    cout << "Case #" << t << ": " << ans << endl;
 }
}
