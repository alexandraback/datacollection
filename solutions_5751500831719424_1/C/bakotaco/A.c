#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

void solve() {
  int n; // number of strings
  char s[100][100] = { { 0 } };
  char string[100] = { 0 };
  int len;
  int j;
  bool lost = false;
  scanf("%d\n", &n);

  for (int i = 0; i < n; i++) {

    int c = 0; // cur char
    int prev = -1; // prev char
    j  = -1; // col

    while (c != '\n') {
      c = getchar();
      if (c != prev) {
	j++;
      }
      s[i][j]++;
      if (i == 0) {
	string[j] = c;
      } else {
	if (c != string[j]) {
	  lost = true;
	}
      }
      prev = c;
    }

    if (i == 0) {
      len = j;
    }

    if (j != len) {
      lost = true;
    }

  }

  if (lost) {
    printf("Fegla Won\n");
  } else {
    /* printf("%s\n", string); */
    /* for (int k=0; k<n; k++) { */
    /*   for (int l=0; l<len; l++) { */
    /* 	printf("%d ", s[k][l]); */
    /*   } */
    /*   printf("\n"); */
    /* } */
    int total_actions = 0;
    for (int k=0; k<len; k++) {
      int best = INT_MAX;
      for (int l=1; l<=100; l++) {
	int nactions = 0;
	for (int m=0; m<n; m++) {
	  nactions += abs(s[m][k] - l);
	}
	if (nactions < best) {
	  best = nactions;
	} else {
	  break;
	}
      }
      total_actions += best;
    }
    printf("%d\n", total_actions);
  }
}

int main() {
  int t;
  scanf("%d\n", &t);
  for (int i = 1; i <= t; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}
