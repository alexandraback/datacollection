#include <iostream>
#include <numeric>
#include <vector>
#include <queue>
using namespace std;

#include "point.hpp"

typedef long double ld;

/*struct coord {
  int x, y;
};*/

/*struct graham_scanner {
  coord origin;

  graham_scanner(const coord& o) : origin(o) {}

  bool operator()(const coord& a, const coord& b) {
    ld angle_a 
  }
};*/

int main() {

  int T;
  int c = 1;
  cin >> T;
  while (T--) {
    //Get test case
    size_t N;
    cin >> N;
    vector<point<int>> trees(N);
    vector<int> results(N, -1);
    for (size_t i = 0; i < N; i++)
    {
      cin >> trees[i];
    }

    //Compute convex hull
    vector<point<int> > hull = convex_hull<int>(trees.begin(), trees.end());
    for (size_t i = 0; i < N; i++)
    {
      for (size_t j = 0; j < hull.size(); j++)
      {
        if (trees[i] == hull[j]) {
          results[i] = 0;
        }
      }
    }

    //Compute results
    for (size_t tree = 0; tree < N; tree++)
    {
      if (results[tree] == 0) { continue; }

      size_t best = N;
      for (size_t left = 0; left < hull.size(); left++)
      {
        /*if (on(trees[tree], hull[left], hull[(left + 1) % hull.size()])) {
          best = 0;
          break;
        }*/

        for (size_t right = left + 2; right < hull.size(); right++) {

          int t1 = point<int>::cross_product(trees[tree], hull[left], hull[right-1]);
          int t2 = point<int>::cross_product(trees[tree], hull[left], hull[right]);
          if (t1*t2 < 0 || t2 == 0) {
            best = min(best, right - left - 1);
          }
        }
      }
      results[tree] = best;
    }


    //Output result
    cout << "Case #" << c++ << ": " << endl;
    for (size_t i = 0; i < N; i++)
    {
      cout << results[i] << endl;
    }
  }

  return 0;
}