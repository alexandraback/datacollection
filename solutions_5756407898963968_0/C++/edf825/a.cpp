#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {

  int n;
  scanf("%d", &n);

  for (int t = 0; t < n; t++) {
    int r;
    int cards1[4], cards2[4];

    scanf("%d", &r);
    for (int i = 0; i < 4; i++) {
      if (r == i + 1) {
        scanf("%d%d%d%d", &cards1[0], &cards1[1], &cards1[2], &cards1[3]);
      } else {
        scanf("%*d%*d%*d%*d");
      }
    }

    scanf("%d", &r);
    for (int i = 0; i < 4; i++) {
      if (r == i + 1) {
        scanf("%d%d%d%d", &cards2[0], &cards2[1], &cards2[2], &cards2[3]);
      } else {
        scanf("%*d%*d%*d%*d");
      }
    }

    sort(cards1, cards1 + 4);
    sort(cards2, cards2 + 4);

    int ans = 0;
    int num = 0;

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (cards1[i] == cards2[j]) {
          ans = cards1[i];
          num++;
        }
      }
    }

    printf("Case #%d: ", t + 1);
    if (num == 0) {
      printf("Volunteer cheated!\n");
    } else if (num == 1) {
      printf("%d\n", ans);
    } else {
      printf("Bad magician!\n");
    }
  }

  return 0;
}
