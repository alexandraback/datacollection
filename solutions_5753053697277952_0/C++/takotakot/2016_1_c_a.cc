#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iterator>

struct solver_2016_1_c_a {
  // use 0-origin
  std::vector<int> P;

  solver_2016_1_c_a() {
    return;
  }

  std::string run(std::vector<int> P_) {
    std::stringstream ss;
    P = P_;
    P_.clear();
    int size = P.size();
    int i_max, count_max, i_sec, count_sec;

    // decide two parties that remains
    if (P[0] >= P[1]) {
      i_max = 0;
      i_sec = 1;
    } else {
      i_max = 1;
      i_sec = 0;
    }
    count_max = P[i_max];
    count_sec = P[i_sec];

    for (int i = 2; i < size; ++i) {
      if (P[i] > count_max) {
        i_sec = i_max;
        i_max = i;
        count_max = P[i_max];
        count_sec = P[i_sec];
      } else if (P[i] > count_sec) {
        i_sec = i;
        count_sec = P[i_sec];
      }
    }

    // decrease max party to the second
    int diff_max_sec = count_max - count_sec;
    std::cerr << "max: " << i_max << " sec: " << i_sec << " diff: " << diff_max_sec << std::endl;

    for (int i = diff_max_sec; i > 0;) {
      if (i > 1) {
        ss << (char) ('A' + i_max) << (char) ('A' + i_max) << ' ';
        i -= 2;
      } else {
        ss << (char) ('A' + i_max) << ' ';
        --i;
      }
    }

    // escape others
    for (int i = 0; i < size; ++i) {
      if (i != i_max && i != i_sec) {
        for (int j = P[i]; j > 0;) {
          if (j > 1) {
            ss << (char) ('A' + i) << (char) ('A' + i) << ' ';
            j -= 2;
          } else {
            ss << (char) ('A' + i) << ' ';
            --j;
          }
        }
      }
    }

    // escape decided parties
    int remain = count_sec;
    std::string two;
    two += (char) ('A' + i_max);
    two += (char) ('A' + i_sec);
    ss << two;
    for(int i = 1; i < remain; ++i) {
      ss << ' ' << two;
    }

    return ss.str();
  }

};

int main(void) {
  solver_2016_1_c_a solver;

  int T, N, temp;
  std::vector<int> P;
  std::string S;

  std::cin >> T;
  for (int i = 0; i < T; ++i) {
    P.clear();
    std::cin >> N;
    std::cerr << N << std::endl;
    for (int j = 0; j < N; ++j) {
      std::cin >> temp;
      std::cerr << temp << "\t";
      P.push_back(temp);
    }
    std::cerr << std::endl;
    // std::cerr << "Case #" << (i + 1) << ": " << solver.run(S) << std::endl;
    std::cout << "Case #" << (i + 1) << ": " << solver.run(P) << std::endl;
  }

  return 0;
}
