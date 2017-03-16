#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
#include <iostream>
using namespace std;

bool lived[16];

int main() {
  freopen("//Users//zxj//Desktop//poj_input.txt", "r", stdin);
  //freopen("//Users//zxj//Desktop//poj_output1_s.txt", "w", stdout);
  int cases;
  scanf("%d", &cases);
  for (int i = 0; i < cases; ++i) {
    int r, c, n;
    scanf("%d %d %d", &r, &c, &n);
    memset(lived, 0, sizeof(lived));
    if (n == 0) {
      printf("Case #%d: %d\n", i + 1, 0);
      continue;
    }
    int my_min = 1000000;
    int comb = (1 << n) - 1;
    while (comb < (1 << (r * c))) {
      memset(lived, 0, sizeof(lived));
      for (int j = 0; j < (r * c); ++j) {
        if (((comb >> j) & 1) == 1) {
          lived[j] = 1;
        }
      }
      int temp_res = 0;
      for (int j = 0; j < r * c; ++j) {
        int row = j / c;
        int col = j % c;
        if (!lived[j]) {
          continue;
        }
        if (col < c - 1) {
          int right = j + 1;
          if (lived[right]) {
            ++temp_res;
          }
        }
        if (row < r - 1) {
          int down = j + c;
          if (lived[down]) {
            ++temp_res;
          }
        }
      }
      if (temp_res < my_min) {
        my_min = temp_res;
      }
      int x = comb & -comb;
      //cout << x << "========" << endl;
      int y = comb + x;
      comb = ((comb & ~y) / x >> 1) | y;
    //  cout << comb << "====" << endl;
    }
    printf("Case #%d: %d\n", i + 1, my_min);
  }
}