#include <iostream>
#include <vector>

int main() {
  int T;
  std::cin >> T;

  for (int casenum = 1; casenum <= T; ++casenum) {
    int choice1;
    std::cin >> choice1;
    int arr1[4][4];
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
	std::cin >> arr1[i][j];
      }
    }

    int choice2;
    std::cin >> choice2;
    int arr2[4][4];
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
	std::cin >> arr2[i][j];
      }
    }

    --choice1;
    --choice2;

    std::vector<int> common;
    for (int c1 = 0; c1 < 4; ++c1) {
      for (int c2 = 0; c2 < 4; ++c2) {
	if (arr1[choice1][c1] == arr2[choice2][c2]) {
	  common.push_back(arr1[choice1][c1]);
	}
      }
    }

    std::cout << "Case #" << casenum << ": ";
    if (common.empty()) {
      std::cout << "Volunteer cheated!" << std::endl;
    } else if (common.size() == 1) {
      std::cout << common[0] << std::endl;
    } else {
      std::cout << "Bad magician!" << std::endl;
    }
  }
}

