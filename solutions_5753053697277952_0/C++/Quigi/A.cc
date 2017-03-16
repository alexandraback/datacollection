// 2016 Round 1C, Problem A
// Copyright 2016 Christian Brechbuehler alias Quigi
// using gcc version 4.8.2 (Ubuntu 4.8.2-19ubuntu1)

#include <iostream>
#include <vector>
#include <algorithm>

static int read_int() {         // convenience function
  int i;
  std::cin >> i;
  return i;
}

typedef std::vector<int> VI;

static void do_case() {
  const int N = read_int();
  VI p(N);
  int n_left = 0;
  for (int &n : p) {
    std::cin >> n;
    n_left += n;
  }
  for (; n_left > 2; --n_left) {
    VI::iterator party = std::max_element(p.begin(), p.end());
    if (2* *party <= n_left) std::cout << " ";
    std::cout << char('A'+ (party-p.begin()));
    --*party;
  }
  std::cout << " ";
  for (int j = N; j--; )
    if (p[j]) std::cout << char('A'+ j);
}

int main() {
  const int T = read_int();
  for (int j = 1; j <= T; ++j) {
    std::cout << "Case #" << j << ": ";
    do_case();
    std::cout << std::endl;
  }
  return 0;
}
