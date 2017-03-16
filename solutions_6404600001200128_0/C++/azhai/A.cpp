#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

const int N_MAX = 1024;
int N;
int mushrooms[N_MAX];

void init() {
  cin >> N;
  for (int i = 0; i < N; i++)
    cin >> mushrooms[i];
}

void solve_case(int t) {
  init();

  int first_way = 0;
  for (int i = 1; i < N; i++) {
    if (mushrooms[i] < mushrooms[i - 1])
      first_way += mushrooms[i - 1] - mushrooms[i];
  }

  int second_way = 0;
  int max_diff = 0;
  for (int i = 1; i < N; i++) {
    int diff = mushrooms[i - 1] - mushrooms[i];
    max_diff = max(diff, max_diff);
  }
  for (int i = 0; i < N - 1; i++) {
    second_way += min(max_diff, mushrooms[i]);
  }

  cout << "Case #" << t << ": " << first_way << " " << second_way << "\n";
}

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    solve_case(i + 1);
  }

  return 0;
}
