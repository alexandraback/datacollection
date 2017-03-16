#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define OUT(var) ' ' << #var "=" << var


class Task {
 public:
  friend std::istream &operator>> (std::istream &in, Task &t) {
    int size;
    in >> size;

    t.senate.resize(size);

    for (int &party: t.senate) {
      in >> party;
    }

    return in;
  }

  friend std::ostream &operator<< (std::ostream &out, Task &t) {
    // for (auto &rec: t.plan) {
    //   out << ' ' << rec;
    // }

    vector<int> &senate = t.senate;
    int max = senate[0];

    for (int i = 1; i < senate.size(); ++i) {
      if (max < senate[i]) {
        max = senate[i];
      }
    }

    for (; max > 0; --max) {
      int prev = -1, curr = -1;

      for (int i = 0; i < senate.size(); ++i) {
        if (senate[i] == max) {
          if (prev == -1) {
            prev = i;
          }
          else if (curr == -1) {
            curr = i;
          }
          else {
            out << ' ' << (char)('A' + prev);
            prev = curr;
            curr = i;
          }

          senate[i] -= 1;
        }
      }

      if (prev >= 0) {
        out << ' ' << (char)('A' + prev);

        if (curr >= 0) {
          out << (char)('A' + curr);
        }
      }
    }

    return out;
  }

  void solve () {
  }

 private:
  vector<int> senate;
};


int main () {
  std::ios_base::sync_with_stdio(false);

  int T;
  std::cin >> T;

  for (int t = 1; t <= T; ++t) {
    Task task;
    std::cin >> task;

    task.solve();

    std::cout << "Case #" << t << ":" << task << '\n';
  }
}
