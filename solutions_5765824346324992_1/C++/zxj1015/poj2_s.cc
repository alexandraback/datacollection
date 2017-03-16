//
//  main.cpp
//  pojcode
//
//  Created by zxj on 15/02/21.
//  Copyright (c) 2015??? Shanghai Jiao Tong University. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string.h>
using namespace std;

int N, B;

typedef long long LL;
const LL high_high = 100000LL * 1000000000LL;

int Process(const vector<int>& bars) {
  LL low = -1;
  LL high = high_high;
  while (high - low > 1) {
    LL mid = (high + low) / 2;
    LL num = 0;
    for (int i = 0; i < B; ++i) {
      num += mid / (LL)(bars[i]) + (mid % (LL)(bars[i]) > 0);
    }
    if (num >= (LL)(N)) {
      high = mid;
    } else {
      low = mid;
    }
  }
  LL num = 0;
 // cout << high << "===" << endl;
  for (int i = 0; i < B; ++i) {
    num += (high - 1) / (LL)(bars[i]) + ((high - 1) % (LL)(bars[i]) > 0);
  }
  //cout << high << endl;
  for (int i = 0; i < B; ++i) {
    num += high / (LL)(bars[i]) + (high % (LL)(bars[i]) > 0) -
           (high - 1) / (LL)(bars[i]) - ((high - 1) % (LL)(bars[i]) > 0);
    if (num >= N) {
      return i + 1;
    }
  }
  return -1;
}

int main() {
  freopen("//Users/zxj//Desktop//poj_input.txt", "r", stdin);
  int cases = 0;
  scanf("%d", &cases);
  for (int i = 0; i < cases; ++i) {
    scanf("%d %d", &B, &N);
    vector<int> bars;
    bars.resize(B);
    for (int j = 0; j < B; ++j) {
      scanf("%d", &bars[j]);
    }
    int res = Process(bars);
    printf("Case #%d: %d\n", i + 1, res);
  }

}
