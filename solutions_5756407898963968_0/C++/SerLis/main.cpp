#pragma comment(linker, "/STACK:256000000")
#include <stdio.h>
#include <iostream>
#include <cmath>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

using namespace std;

  long long k, n, m, p;
  string s1, s2; 
  long long a[21];

void read() {
  int row, cur;
  cin >> row;
  row--;
  for (int i = 0; i < 16; ++i) {
    cin >> cur;
    if (i / 4 == row) {
      a[cur]++;
    }
  }
}

int main() {
  freopen("input", "r+", stdin);
  freopen("output", "w+", stdout);
  std::ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    for (int i = 0; i < 20; ++i) {
      a[i] = 0;
    }
    read();
    read();
    int num_answ = 0, answ = 0;;
    for (int i = 0; i < 20; ++i) {
      if (a[i] == 2) {
        num_answ++;
        answ = i;
      }
    }
    cout << "\nCase #" << t << ": ";
    if (num_answ == 0) {
      cout << "Volunteer cheated!";
    }
    if (num_answ == 1) {
      cout << answ;
    }
    if (num_answ > 1) {
      cout << "Bad magician!";
    }
  }
}
