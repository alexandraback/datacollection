#include <iostream>
#include <string>
#include <vector>
typedef std::vector<unsigned int> VU;
typedef std::vector<VU> VVU;
#include <algorithm>

int main() {
  unsigned int T; std::cin >> T;
  for (unsigned int test_case = 1; test_case <= T; ++test_case) {
    unsigned int N; std::cin >> N;
    std::vector<std::string> strings(N);
    std::string previous_gist;
    bool fegla_won(false);
    VVU gist_counts(N);
    VU m1, m2;
    for (unsigned int i1 = 1; i1 <= N; ++i1) {
      std::cin >> strings[i1 - 1];
      if (!fegla_won) {
        std::string current_gist;
        for (unsigned int i2 = 1; i2 <= strings[i1 - 1].size(); ++i2) {
          current_gist += strings[i1 - 1][i2 - 1];
          gist_counts[i1 - 1].push_back(1);
          for (;
               (i2 + 1 <= strings[i1 - 1].size()) &&
                 (strings[i1 - 1][i2 + 1 - 1] == strings[i1 - 1][i2 - 1]);
               ++i2)
            ++gist_counts[i1 - 1][gist_counts[i1 - 1].size() - 1];
        }
        if (i1 <= 1) {
          previous_gist = current_gist;
          m1 = gist_counts[i1 - 1];
          m2 = gist_counts[i1 - 1];
        }
        else if (previous_gist != current_gist) 
          fegla_won = true;
        else {
          for (unsigned int i2 = 1; i2 <= previous_gist.size(); ++i2) {
            m1[i2 - 1] = std::min(m1[i2 - 1], gist_counts[i1 - 1][i2 - 1]);
            m2[i2 - 1] = std::max(m2[i2 - 1], gist_counts[i1 - 1][i2 - 1]);
          }
        }
      }
    }
    if (!fegla_won) {
      unsigned int moves(0);
      for (unsigned int i2 = 1; i2 <= previous_gist.size(); ++i2) {
        unsigned int min;
        for (unsigned int target = m1[i2 - 1]; target <= m2[i2 - 1]; ++target) {
          unsigned int sum(0);
          for (unsigned int i1 = 1; i1 <= N; ++i1)
            sum +=
              target >= gist_counts[i1 - 1][i2 - 1] ?
              target - gist_counts[i1 - 1][i2 - 1] :
              gist_counts[i1 - 1][i2 - 1] - target;
          if (target <= m1[i2 - 1] || sum < min) min = sum;
        }
        moves += min;
      }
      std::cout << "Case #" << test_case << ": " << moves << std::endl;
    } else
      std::cout << "Case #" << test_case << ": Fegla Won" << std::endl;
  }

  return 0;
}
