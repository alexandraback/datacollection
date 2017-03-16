#include <iostream>
#include <vector>

int main() {
  int T, guess1, guess2;
  int cards1[16], cards2[16];
  int answer;

  std::cin >> T;
  for (int t = 1; t <= T; t++) {
    answer = 0;

    std::cin >> guess1;   
    for (int ii = 0; ii < 16; ii++) {
      std::cin >> cards1[ii];
    }
    std::cin >> guess2;
    for (int ii = 0; ii < 16; ii++) {
      std::cin >> cards2[ii];
    }

    std::vector<int> answers;
    for (int ii = 0; ii < 4; ii++) {
      for (int jj = 0; jj < 4; jj++) {
        if (cards1[(guess1-1)*4+ii] == cards2[(guess2-1)*4+jj]) {
          answers.push_back(cards1[(guess1-1)*4+ii]);
        }
      }
    }

    std::cout << "Case #" << t << ": ";
    switch (answers.size()) {
      case 0: std::cout << "Volunteer cheated!"; break;
      case 1: std::cout << answers[0]; break;
      default: std::cout << "Bad magician!";
    }
    std::cout << std::endl;
  }

}
