#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0
int comparator(const void *p, const void *q) {
  // Get the values at given addresses
  int l = *(const int *)p;
  int r = *(const int *)q;

  return l - r;
}

int magic(void) {
  int num;
  scanf("%d\n", &num);
  char ** strings = malloc(sizeof (char *)* num);
  int action_sum = 0;
  int target_val;
  for (int i = 0; i < num; i++) {
    strings[i] = malloc(sizeof(char) *102);
    fgets(strings[i], 102, stdin);
    //printf("Strings %d is %s\n", i, strings[i]);
  }

  int * curptr = calloc(sizeof(int) , num);
  int * curcount = calloc(sizeof(int) , num);

  char cur = strings[0][0];
  while (cur != '\n' && cur != '\0') {
    //printf("Cur is %c\n", cur);
    int changed = true;
    while (changed == true) {
      changed = false;
      for (int i = 0; i < num; i++) {
        //printf("Cur %c matching for %d? %c!\n", cur, i, strings[i][curptr[i]]);
        if (strings[i][curptr[i]] == cur) {
          changed = true;
          curcount[i]++;
          curptr[i]++;
        } else if (curcount[i] == 0 ) {
          return -1;
        }
      }
    }
    qsort(curcount, num, sizeof(int), comparator);
    target_val = curcount[num/2];
    for (int i = 0; i< num; i++) {
      if (target_val < curcount[i]) {
        action_sum += curcount[i]-target_val;
      } else {
        action_sum += target_val - curcount[i];
      }
      curcount[i] = 0;
    }
    cur = strings[0][curptr[0]];
  }
  free(curcount);
  for (int i = 0; i < num; i++) {
    if (strings[i][curptr[i]] != '\n') {
      free(curptr);
      return -1;
    }
  }
  free(curptr);
  return action_sum;
}

int main(void) {
  int cases;
  scanf("%d", &cases);
  for (int i = 1; i <= cases; i++) {
    int answer = magic();
    printf("Case #%d: ", i);
    if (answer == -1) {
      printf("Fegla Won\n");
    } else {
      printf("%d\n", answer);
    }
  }
}
