#include <stdio.h>

//methOne: sum of all points where there is a decrease
//methTwo: largest drop, but can't go negative

int pieces[10001];

int main() {
  int T, N, i, j, prev, curr, methOne, largestDrop, methTwo, diff;
  FILE *fin = fopen("A.in", "r");
  FILE *fout = fopen("A.out", "w");
  fscanf(fin, "%d\n", &T);
  for (i = 1; i <= T; i++) {
    methOne = 0, methTwo = 0, largestDrop = 0;
    fscanf(fin, "%d\n", &N);
    fscanf(fin, "%d ", &pieces[0]);
    for (j = 1; j < N; j++) {
      fscanf(fin, "%d ", &pieces[j]);
      diff = pieces[j-1] - pieces[j];
      if (diff > 0) {
        methOne += diff;
        largestDrop = largestDrop < diff ? diff : largestDrop;
      }
    }
    for (j = 0; j < N-1; j++) {
      if (pieces[j] < largestDrop) methTwo += pieces[j];
      else methTwo += largestDrop;
    }
    fprintf(fout, "Case #%d: %d %d\n", i, methOne, methTwo);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
