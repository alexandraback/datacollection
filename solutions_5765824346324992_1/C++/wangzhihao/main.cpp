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

int B;
int barbers[1024];

long long service_number(long long time) {
  long long ans = B;
  for(int i = 0; i < B; i++){ 
    ans += time / barbers[i];
  }
  return ans;
}

int main() {
  FILE* reader = fopen("./test.in", "r");
  FILE* writer = fopen("./ans.out", "w");

  int case_number;
  int n;

  fscanf(reader, "%d", &case_number);
  for (int caseIndex = 1; caseIndex <= case_number; caseIndex++) {
    fscanf(reader, "%d %d", &B, &n);
    long long slowest = 0;
    for (int i = 0; i < B; i++) {
      fscanf(reader, "%d", &barbers[i]);
      slowest = max(slowest, (long long)barbers[i]);
    }
    long long left = 0, right = ( n / B + 1) * slowest, ans = 0, mid;
    while (left <= right) {
      mid = (left + right) / 2;
      if (service_number(mid) >= n) {
        right = mid - 1 ;
        ans = mid;
      } else {
        left = mid + 1;
      }
    }
    int result = 0;
    long long number_in_this_minute = n - service_number(ans-1);
    printf("time %lld\n", ans);
    for (int i = 0; i < B; i++) {
      if (ans % barbers[i] == 0) {
        number_in_this_minute --;
        if(number_in_this_minute == 0){
          result = i + 1;
          break;
        }
      }
    }
    fprintf(writer, "Case #%d: %d\n", caseIndex, result);
  }

  fclose(reader);
  fclose(writer);
  return 0;
}
