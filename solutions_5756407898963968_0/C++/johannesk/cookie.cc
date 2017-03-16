#include <iostream>
#include <vector>
#include <map>
#include <limits>
#include <iomanip>

int main()
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);

  int num_of_testcases; std::cin >> num_of_testcases;
  for (int testcase=1; testcase<=num_of_testcases; ++testcase) {
    std::cout << "Case #" << testcase << ": ";

    double c, f, x; std::cin >> c >> f >> x;
    double cps = 2.0, total_time = 0,
      best_time = std::numeric_limits<double>::max();
    for (;;) {
      double won = total_time + x/cps;
      if (won < best_time)
        best_time = won;
      else
        break;
      total_time += c/cps;
      cps += f;
    }

    std::cout << std::setprecision(100) << best_time << '\n';
  }
}

/*
 * Local variables:
 * mode:c++
 * compile-command:"g++ -D_GLIBCXX_DEBUG -g -ggdb3 -O0 -Wall -Wextra -Wno-long-long -std=c++11 cookie.cc -o cookie && for f in *.in; do echo \"--- $f -------------\"; ./cookie <$f; done"
 * end:
 */

