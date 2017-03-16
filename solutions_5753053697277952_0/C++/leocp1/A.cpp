#include<algorithm>
#include<bitset>
#include<vector>
#include<stdio.h>
#include<iostream>

int main(void) {
  int T = 0;
  int N = 0;
  scanf("%d\n", &T);
  for (int k = 1; k <= T; k++) {
    scanf("%d\n", &N);
    std::vector<int> P(N);
    //get data
    for (int i = 0; i < N; i++) {
      scanf("%d", P.data() + i);
    }
    if (N == 2) {
      P.push_back(0);
      N = 3;
    }
    std::vector<int> ind(N);
    std::iota(ind.begin(), ind.end(), 0);
    std::sort(ind.begin(), ind.end(), [&P](int lhs, int rhs) {return P[lhs] > P[rhs];});

    //get indices in sorted order
    //std::sort(ind.begin(), ind.end(), [&P](int lhs, int rhs) {return P[lhs] > P[rhs];});

    printf("Case #%d:", k);

    while (P[ind[0]] > 0) {
      //generate indices
      /*
      printf("\n");
      for (int i = 0; i < N; i++) {
        printf("%d ", P[i]);
      }
      printf("\n");
      for (int i = 0; i < N; i++) {
        printf("%d ", ind[i]);
      }
      printf("\n");
      */
      printf(" ");
      if (P[ind[0]] == P[ind[1]] && P[ind[0]] != P[ind[2]]) {
        putchar('A' + ind[0]);
        putchar('A' + ind[1]);
        P[ind[0]]--;
        P[ind[1]]--;
      } else {
        putchar('A' + ind[0]);
        P[ind[0]]--;
      }
      std::iota(ind.begin(), ind.end(), 0);
      std::sort(ind.begin(), ind.end(), [&P](int lhs, int rhs) {return P[lhs] > P[rhs];});
    }

    //top three equal or first larger than second, take off from top
    //top two equal and top three not equal

    printf("\n");
  }
  return 0;
}
