#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool Check(std::vector<size_t> &v) {
  size_t sum = 0;
  for (size_t n : v) {
    sum += n;
  }
  for (size_t n : v) {
    if (n * 2 > sum) {
      return false;
    }
  }
  return true;
}

int main() {
  size_t T;
  std::cin >> T;
  for (size_t t = 1; t <= T; ++t) {
    size_t N;
    std::cin >> N;
    std::vector<size_t> count(N);
    size_t total_count = 0;
    for (size_t i = 0; i < N; ++i) {
      std::cin >> count[i];
      total_count += count[i];
    }
    std::cout << "Case #" << t << ":";
    while (total_count > 0) {
      bool found = false;
      for (size_t i = 0; i < N && !found; ++i) {
        if (count[i]) {
          --count[i];
          if (Check(count)) {
            std::cout << " " << (char)('A' + i);
            --total_count;
            found = true;
          } else {
            ++count[i];
          }
        }
      }
      if (!found) {
        for (size_t i = 0; i < N && !found; ++i) {
          for (size_t j = i; j < N && !found; ++j) {
            if (count[i] && count[j]) {
              if (!(i == j) || count[i] >= 2) {
                --count[i];
                --count[j];
                if (Check(count)) {
                  std::cout << " " << (char)('A' + i) << (char)('A' + j);
                  --total_count;
                  --total_count;
                  found = true;
                } else {
                  ++count[i];
                  ++count[j];
                }
              }
            }
          }
        }
      }
    }
    std::cout << "\n";
  }
  return 0;
}
