#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>

using namespace std;

int main() {
  int n_tests;
  cin >> n_tests;
  for (int i_test = 0; i_test < n_tests; i_test++) {
    bool multiple = false;
    int ans = -1;
    set<int> first_row;

    for (int i = 0; i < 2; i++) {
      int row;
      cin >> row;

      for (int j = 0; j < 4; j++) {
        for (int k = 0; k < 4; k++) {
          int num;
          cin >> num;

          if (j + 1 != row) { continue; }

          if (i == 0) {
            first_row.insert(num);
          } else {
            if (first_row.count(num)) {
              if (ans >= 0) {
                multiple = true;
              } else {
                ans = num;
              }
            }
          }
        }
      }
    }

    printf("Case #%d: ", i_test+1);
    if (multiple) {
      printf("Bad magician!\n");
    } else if (ans < 0) {
      printf("Volunteer cheated!\n");
    } else {
      printf("%d\n", ans);
    }
  }
}
