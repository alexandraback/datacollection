#include <stdio.h>

#include <vector>
#include <algorithm>


typedef long long lnt;


struct Vector2D {
  lnt x, y;

  Vector2D() : x(0), y(0) {}

  Vector2D(lnt x, lnt y) : x(x), y(y) {}

  Vector2D operator-(const Vector2D &v) const {
    return Vector2D(x - v.x, y - v.y);
  }

  lnt Cross(const Vector2D &v) const { return x * v.y - y * v.x; }

  lnt Dot(const Vector2D &v) const { return x * v.x + y * v.y; }

  int Place() const {
    if (x == 0 && y == 0) return 0;
    if (x  > 0 && y == 0) return 1;
    if (x  > 0 && y  > 0) return 2;
    if (x == 0 && y  > 0) return 3;
    if (x  < 0 && y  > 0) return 4;
    if (x  < 0 && y == 0) return 5;
    if (x  < 0 && y  < 0) return 6;
    if (x == 0 && y  < 0) return 7;
    if (x  > 0 && y  < 0) return 8;
  }

  lnt Length2() const { return Dot(*this); }

  bool operator<(const Vector2D &v) const {
    if (Place() != v.Place()) {
      return (Place() < v.Place());
    }
    if (Cross(v) != 0) {
      return (Cross(v) > 0);
    }
    return (Length2() < v.Length2());
  }
};


int main() {
  int z, zzz;
  for (scanf("%d", &zzz), z = 1; z <= zzz; ++z) {
    int n;
    scanf("%d", &n);

    std::vector<Vector2D> trees(n);
    for (int i = 0; i < n; ++i) {
      scanf("%lld %lld", &(trees[i].x), &(trees[i].y));
    }

    printf("Case #%d:\n", z);
    for (int i = 0; i < n; ++i) {
      std::vector<Vector2D> tmp(n - 1);
      for (int j = 0; j < i; ++j) {
        tmp[j] = trees[j] - trees[i];
      }
      for (int j = i + 1; j < n; ++j) {
        tmp[j - 1] = trees[j] - trees[i];
      }

      std::sort(tmp.begin(), tmp.end());

      bool good = (n <= 3);
      if (!good) {
        for (int j = 0; j < n - 1; ++j) {
          int nxt = (j + 1) % (n - 1);
          if (tmp[j].Cross(tmp[nxt]) < 0 ||
              tmp[j].Cross(tmp[nxt]) == 0 && tmp[j].Dot(tmp[nxt]) < 0) {
            good = true;
            break;
          }
        }
        if (!good) {
          if (tmp[n - 2].Cross(tmp[0]) == 0 && tmp[n - 2].Dot(tmp[0]) > 0) {
            good = true;
          }
        }
      }
      if (good) {
        printf("%d\n", 0);
        continue;
      }
      
      /*
      int fuck_ans = n - 1;
      for (int j = 0; j < n - 1; ++j) {
        int ct = 0;
        for (int k = 0; k < n - 1; ++k) {
          if (tmp[j].Cross(tmp[k]) > 0) {
            ++ct;
          }
        }
        fuck_ans = std::min(fuck_ans, ct);
      }
      // */

      int ans = n - 1;
      for (int diff = 1, j = 0; j < n - 1; ++j, diff = std::max(1, diff - 1)) {
        int nxt = (j + 1) % (n - 1);
        if (tmp[j].Cross(tmp[nxt]) == 0) {
          continue;
        }
        while (tmp[j].Cross(tmp[(j + diff + 1) % (n - 1)]) > 0) {
          ++diff;
        }
        ans = std::min(ans, diff);
      }
      printf("%d\n", ans);
//      if (fuck_ans != ans) {
//        fprintf(stderr, "fuck!!!!\n");
//      }
//      if (fuck_ans != ans) {
//        printf("n = %d fuck = %d, ans = %d\n", n, fuck_ans, ans);
//        printf("org = %lld %lld\n", trees[i].x, trees[i].y);
//        for (int j = 0; j < n - 1; ++j) {
//          printf(">>> %lld %lld\n", tmp[j].x, tmp[j].y);
//        }
//        break;
//      }
    }
  }
  return 0;
}
