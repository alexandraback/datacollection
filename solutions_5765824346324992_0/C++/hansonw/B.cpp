#include <iostream>
using namespace std;

int barber[1001];
long long compute(long long x, int B) {
  long long sum = 0;
  for (int i = 0; i < B; i++) {
    sum += x / barber[i] + 1;
  }
  return sum;
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int B, N; cin >> B >> N;
    for (int i = 0; i < B; i++) {
      cin >> barber[i];
    }

    int ans = 0;
    if (N <= B) {
      ans = N;
    } else {
      long long low = 0, high = 1e14;
      while (low < high) {
        long long mid = (low + high) / 2;
        long long sum = compute(mid, B);
        if (sum >= N) {
          high = mid;
        } else {
          low = mid + 1;
        }
      }
      if (low == 0) throw;
      int rem = N - compute(low-1, B);
      for (int i = 0; i < B; i++) {
        if (low % barber[i] == 0) {
          if (--rem == 0) {
            ans = i+1;
            break;
          }
        }
      }
    }

    printf("Case #%d: %d\n", t, ans);
  }
}
