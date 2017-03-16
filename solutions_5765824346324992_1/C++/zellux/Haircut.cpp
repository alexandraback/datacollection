#include <iostream>

using namespace std;

long numServed(long *duration, long *count, long num, long minutes) {
  long sum = 0;
  for (int i = 0; i < num; i++) {
    count[i] = (minutes + duration[i] - 1) / duration[i];
    sum += count[i];
  }
  return sum;
}


int main() {
  long t, n, b;
  long duration[1000];
  long count[1000];
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> b >> n;
    for (int j = 0; j < b; j++) {
      cin >> duration[j];
    }

    long p = 0;
    long q = duration[0] * n;
    long served;
    while (p < q) {
      long mid = (p + q) / 2;
      served = numServed(duration, count, b, mid);
      if (served > n) {
        q = mid - 1;
      } else if (served < n) {
        p = mid + 1;
      } else {
        break;
      }
    }
    while ((served = numServed(duration, count, b, p)) >= n) {
      p--;
    }
    // cout << served << " served at minute " << p << endl;;

    // memset(&count, 0, sizeof(count));
    // served = 0;
    
    for (int j = served + 1; j <= n; j++) {
      int min = 0;
      for (int k = 0; k < b; k++) {
        if (count[min] * duration[min] > count[k] * duration[k]) {
          // cout << "replacing " << min << " with " << k << endl;;
          min = k;
        }
      }
      count[min] ++;
      if (j == n) {
        cout << "Case #" << i << ": " << min + 1 << endl;
      }
    }
  }
  return 0;
}
