#include <cstdio>

using namespace std;

int T;
int N;
int m[10005];

int main(void) {
  scanf("%d", &T);
  for(int t = 1; t <= T; t++) {
    int y = 0, z = 0, mr = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
      scanf("%d", &m[i]);
      if(i > 0 && m[i] < m[i - 1]) {
        int r = m[i - 1] - m[i];
        y += r;
        if(r > mr) mr = r;
      }
    }
    for(int i = 0; i < N - 1; i++) {
      if(m[i] > mr) z += mr;
      else z += m[i];
    }
    printf("Case #%d: %d %d\n", t, y, z);
  }
  return 0;
}
