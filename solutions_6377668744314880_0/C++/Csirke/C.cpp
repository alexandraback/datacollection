#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long lglg;

struct Point {
  int x, y;
};

//bool inside(Point x, Point a, Point b, Point c) {

//}

lglg prod(Point from, Point a, Point b) {
  return lglg(a.x - from.x) * lglg(b.y - from.y) - lglg(a.y - from.y) * lglg(b.x - from.x);
}

bool between(Point quest, Point a, Point b) {
  return (quest.x > a.x && quest.x < b.x) ||
         (quest.x < a.x && quest.x > b.x) ||
         (quest.y > a.y && quest.y < b.y) ||
         (quest.y < a.y && quest.y > b.y);
}

int main()
{
  int T;
  scanf("%d", &T);

  for(int t = 0; t < T; ++t) {
    printf("Case #%d:\n", t+1);

    int n;
    scanf("%d", &n);

    vector<Point> P(n);

    for(int i = 0; i < n; ++i) {
      scanf("%d%d", &(P[i].x), &(P[i].y));
    }

    if(n == 1) {
      printf("0\n");
      continue;
    }

    for(int i = 0; i < n; ++i) {
      vector<int> lefts, rights;
      int start = (i == 0) ? 1 : 0;
      bool isleft = false, isright = false;
      for(int j = 0; j < n; ++j) {
        if(j != i) {

          lglg pp = prod(P[i], P[start], P[j]);
          if(pp > 0) {
            lefts.push_back(j);
            isleft = true;
          } else if(pp < 0) {
            rights.push_back(j);
            isright = true;
          } else if(between(P[i], P[start], P[j])) {
            rights.push_back(j);
          } else {
            lefts.push_back(j);
          }
        }
      }

      if(!isleft || !isright) {
        printf("0\n");
        continue;
      }

      auto sorter = [&](int a, int b) {
        lglg pp = prod(P[i], P[a], P[b]);
        return pp > 0;
      };

      sort(lefts.begin(), lefts.end(), sorter);
      sort(rights.begin(), rights.end(), sorter);

      int best = n;

      int num = lefts.size();

      size_t lit = 0;
      size_t rit = 0;
      for(size_t j = 0; j < lefts.size(); ++j) {
        while(lit < lefts.size() && prod(P[i], P[lefts[j]], P[lefts[lit]]) <= 0ll) {
          --num;
          ++lit;
        }

        while(rit < rights.size() && prod(P[i], P[lefts[j]], P[rights[rit]]) > 0ll) {
          ++num;
          ++rit;
        }

        best = min(best, num);
      }


      num = rights.size();

      lit = 0;
      rit = 0;
      for(size_t j = 0; j < rights.size(); ++j) {
        while(rit < rights.size() && prod(P[i], P[rights[j]], P[rights[rit]]) <= 0ll) {
          --num;
          ++rit;
        }

        while(lit < lefts.size() && prod(P[i], P[rights[j]], P[lefts[lit]]) > 0ll) {
          ++num;
          ++lit;
        }

        best = min(best, num);
      }

      printf("%d\n", best);


    }


  }

  return 0;
}
