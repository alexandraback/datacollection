#include <stdio.h>
#define MAX_N 30

int main() {
  int T, n, p[MAX_N], two_parties[2];
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &p[i]);
    }

    printf("Case #%d:", t);

    int party_left = n;
    while (party_left > 2) {
      int max = p[0], max_index = 0;
      for (int i = 1; i < n; i++) {
        if (p[i] > max) {
          max = p[i];
          max_index = i;
        }
      }
      --p[max_index];
      if (p[max_index] == 0) {
        --party_left;
      }
      printf(" %c", 'A' + max_index);
    }

    int j = 0;
    for (int i = 0; i < n && j < 2; i++) {
      if (p[i]) {
        two_parties[j++] = i;
      }
    }

    for (int i = 0; i < p[two_parties[0]]; i++) {
      printf(" %c%c", 'A' + two_parties[0], 'A' + two_parties[1]);
    }

    printf("\n");
  }
  return 0;
}