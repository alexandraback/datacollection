#include <iostream>
#include <vector>

int main() {
  int number_of_tests;
  std::cin >> number_of_tests;
  for (int test_index = 0; test_index < number_of_tests; ++test_index) {
    int number_of_parties;
    std::cin >> number_of_parties;
    std::vector<int> parties(number_of_parties);
    int total_left = 0;
    for (int& party_count : parties) {
      std::cin >> party_count;
      total_left += party_count;
    }
    std::cout << "Case #" << test_index + 1 << ": ";
    while (total_left > 0) {
      int max_index = 0;
      int previous = 0;
      int number_of_nonzero = 0;
      for (int i = 0; i < number_of_parties; ++i) {
        if (parties[i] > 0) {
          number_of_nonzero++;
        }
        if (parties[i] >= parties[max_index]) {
          previous = max_index;
          max_index = i;
        }
      }
      parties[max_index]--;
      if (number_of_nonzero == 2) {
        std::cout << (char)('A' + previous) << (char)('A' + max_index) << ' ';
        parties[previous]--;
        total_left -= 2;
      } else {
        std::cout << (char)('A' + max_index) << ' ';
        total_left --;
      }
    }
    std::cout << std::endl;
  }
  return 0;
}
