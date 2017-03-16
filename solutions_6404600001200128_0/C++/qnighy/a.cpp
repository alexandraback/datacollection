// C++11
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int T; scanf("%d", &T);
  for(int tci = 0; tci < T; ++tci) {
    int N; scanf("%d", &N);
    static int M[1000];
    for(int i = 0; i < N; ++i) scanf("%d", &M[i]);
    int count1 = 0;
    int count2max = 0;
    for(int i = 1; i < N; ++i) {
      count1 += max(0, M[i-1]-M[i]);
      count2max = max(count2max, M[i-1]-M[i]);
    }
    int count2 = 0;
    for(int i = 1; i < N; ++i) {
      count2 += min(M[i-1], count2max);
    }
    printf("Case #%d: %d %d\n", tci+1, count1, count2);
  }
  return 0;
}
