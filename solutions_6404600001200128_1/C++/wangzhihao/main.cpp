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


int main() {
  FILE* reader = fopen("./test.in", "r");
  FILE* writer = fopen("./ans.out", "w");

  int case_number;
  int n;
  int mushrooms[1024];

  fscanf(reader, "%d", &case_number);
  for (int caseIndex = 1; caseIndex <= case_number; caseIndex++) {
    fscanf(reader, "%d", &n);
    for (int i = 0; i < n; i++) {
      fscanf(reader, "%d", &mushrooms[i]);
    }
    int ans1 = 0, ans2 = 0;
    double rate = 0;
    for (int i = 1; i < n; i++) {
      if (mushrooms[i] < mushrooms[i - 1])ans1 += mushrooms[i - 1] - mushrooms[i];
      rate = max(rate, (mushrooms[i-1] - mushrooms[i] )/10.0 );
    }
    for(int i = 1; i < n; i++){
      ans2 += min(mushrooms[i-1], (int)(rate*10));
    }
   // printf("%d\n", rate);
    fprintf(writer, "Case #%d: %d %d\n", caseIndex, ans1, ans2);
  }

  fclose(reader);
  fclose(writer);
  return 0;
}
