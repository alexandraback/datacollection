#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
using std::vector;

int square[4][4];

void Work() {
  int n;
  assert(scanf("%d", &n) == 1);
  --n;
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      assert(scanf("%d", square[i] + j) == 1);;
  int set1 = 0;
  for (int j = 0; j < 4; ++j)
    set1 |= 1 << square[n][j];
  int m;
  assert(scanf("%d", &m) == 1);
  --m;
  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < 4; ++j)
      assert(scanf("%d", square[i] + j) == 1);
  int set2 = 0;
  for (int j = 0; j < 4; ++j)
    set2 |= 1 << square[m][j];
  int setinter = set1 & set2;
  if (!setinter) {
    puts("Volunteer cheated!");
  } else {
    if (setinter == (setinter & -setinter)) {
      for (int i = 1; i <= 16; ++i)
        if (setinter & (1 << i))
          printf("%d\n", i);
    } else {
      puts("Bad magician!");
    }
  }
}

int main() {
  int cases;
  assert(scanf("%d", &cases) == 1);
  for (int i = 1; i <= cases; ++i) {
    printf("Case #%d: ", i);
    Work();
  }
  return 0;
}
