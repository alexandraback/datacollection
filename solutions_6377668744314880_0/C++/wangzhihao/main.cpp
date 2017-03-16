#include <unordered_map>
#include <list>
#include <algorithm>
#include <memory>
#include <vector>
#include <queue>

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

using namespace std;


struct point {
  long long x, y;
  point() {}
  point(long long x, long long y): x(x), y(y) {}
};
long long det(point a, point b, point c) {
  return (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
}
long long dot(point a, point b, point c) {
  return (b.x - a.x) * (c.x - a.x) + (b.y - a.y) * (c.y - a.y);
}


int n;
point points[1024];

int main() {
  FILE* reader = fopen("./test.in", "r");
  FILE* writer = fopen("./ans.out", "w");

  int case_number;

  fscanf(reader, "%d", &case_number);
  for (int caseIndex = 1; caseIndex <= case_number; caseIndex++) {
    fscanf(reader, "%d", &n);
    for (int i = 0; i < n; i++) {
      fscanf(reader, "%lld %lld", &points[i].x, &points[i].y);
    }
    fprintf(writer, "Case #%d:\n", caseIndex);
    for (int i = 0; i < n; i++) {
      int result = n < 3 ? 0 : n - 3;
      for (int j = 0; j < n; j++) {
        if (i == j)continue;
        int pos = 0, neg = 0;
        for(int k = 0; k < n; k++){
          long long direction = det(points[i], points[k], points[j]);
          if(direction < 0)neg ++;
          if(direction > 0)pos ++;
        }
        result = min(result, min(neg, pos));
      }
      fprintf(writer, "%d\n", result);
    }
  }

  fclose(reader);
  fclose(writer);
  return 0;
}
