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
#include <cmath>
#include <string.h>
using namespace std;

int Process1(const vector<int>& data) {
  int res = 0;
  for (int i = 1; i < data.size(); ++i) {
    if (data[i] > data[i - 1]) {
      continue;
    } else {
      res += data[i - 1] - data[i];
    }
  }
  return res;
}

int Process2(const vector<int>& data) {
  double max_rate = 0;
  for (int i = 1; i < data.size(); ++i) {
    if (data[i] > data[i - 1]) {
      continue;
    } else {
      double rate = (data[i - 1] - data[i]) / 10.0;
      if (rate > max_rate) {
        max_rate = rate;
      }
    }
  }
  double res = 0;
  //cout << max_rate << "====" << endl;
  
  for (int i = 0; i < data.size() - 1; ++i) {
    if (data[i] < max_rate * 10) {
      res += data[i];
    } else {
      res += max_rate * 10;
    }
  }
  return int(res + 0.000001);
}

int main() {
  freopen("//Users/zxj//Desktop//poj_input.txt", "r", stdin);
  int cases = 0;
  scanf("%d", &cases);
  for (int i = 0; i < cases; ++i) {
    vector<int> data;
    int N;
    scanf("%d", &N);
    data.resize(N);
    for (int j = 0; j < N; ++j) {
      scanf("%d", &data[j]);
    }
    int res1 = Process1(data);
    int res2 = Process2(data);
    printf("Case #%d: %d %d\n", i + 1, res1, res2);
  }

}
