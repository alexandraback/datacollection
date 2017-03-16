#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <map>
#include <set>

#define double long double

using namespace std;



int main() {
  ios::sync_with_stdio(false);
  freopen("test.in", "r", stdin);
  freopen("output.txt", "w", stdout);

  int cnt_tests;
  cin >> cnt_tests;

  for (int test = 1; test <= cnt_tests; ++test) {
    int n;
    int sum = 0;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
      cin >> p[i];
      sum += p[i];
    }

    printf("Case #%d: ", test);

    if (n == 2) {
      for (int i = 0; i < p[0]; ++i) {
        cout << "AB ";
      }
      cout << endl;
      continue;
    }

    bool two = false;
    while (sum) {
      int ind = 0;

      if (sum == 2) {
        two = true;
      }

      for (int i = 1; i < n; ++i) {
        if (p[ind] < p[i]) {
          ind = i;
        }
      }

      cout << (char)('A' + ind);
      cout << (two ? "" : " ");
      --p[ind];
      --sum;
    }
    cout << endl;

  }

  return 0;
}