#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

long long n_passed(int b, int m[], long long time) {
  long long n = 0;
  for (int i = 0; i < b; i++) {
    n += ceil((double)time / m[i]);
  }
  return n;
}

int main() {
  int n_cases;
  cin >> n_cases;

  for (int i_case = 0; i_case < n_cases; i_case++) {
    int b;
    long long n;
    cin >> b >> n;

    long long sum = 0;
    double sum_recip = 0;
    int m[b];
    vector<int> sorted;
    for (int i = 0; i < b; i++) {
      cin >> m[i];
      sorted.push_back(m[i]);
      sum += m[i];
      sum_recip += 1.0 / m[i];
    }

    sort(sorted.begin(), sorted.end());
    int max_index = b - 1;

    int ans = 0;
    if (n <= b) {
      ans = n;
    } else if (b == 1) {
      ans = 1;
    } else {
      int max_m = sorted[max_index];
      long long wtf = n / sum_recip;
      int n_after_wtf = n_passed(b, m, wtf);

      long long min_temp, max_temp;
      long long min_t, max_t;

      if (n > n_after_wtf) {
        min_temp = n_after_wtf;
        min_t = wtf;

        max_t = wtf + max_m;
        max_temp = n_passed(b, m, max_t);
      } else {
        max_temp = n_after_wtf;
        max_t = wtf;

        min_t = wtf - max_m;
        min_temp = n_passed(b, m, min_t);
      }

      //cout << min_temp << " " << max_temp << endl;
      //cout << min_temp << " " << max_temp << endl;

      /*
      while (n <= min_temp) {
      }
      while (n > max_temp) {
      }
      cout << "MULT FINAL: " << multiplier << endl;
      cout << min_temp << " " << max_temp << endl;
      */

      // Binary search
      while (true) {
        long long test = (min_t + max_t) / 2;
        if (test == min_t) {
          break;
        }

        long long temp_n = n_passed(b, m, test);

        if (n == temp_n) {
          max_t = test;
          max_temp = temp_n;
        } else if (n > temp_n) {
          min_t = test;
          min_temp = temp_n;
        } else {
          max_t = test;
          max_temp = temp_n;
        }
      }

      //cout << min_temp << " " << max_temp << endl;
      //cout << min_t << " " << max_t << endl;
      long long target = n - min_temp;
      for (int i = 0; i < b; i++) {
        if (min_t % m[i] == 0) {
          //cout << "TARGET! " << target << endl;
          target--;
          if (target == 0) {
            ans = i + 1;
            break;
          }
        }
      }
    }

    printf("Case #%d: %d\n", i_case + 1, ans);
  }

  return 0;
}
