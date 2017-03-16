#include <cstdio>
#include <queue>

using namespace std;

void solve(int N) {
  // printf("sovle(%d) \n", N);
  int P[100];
  for (int i = 0; i < N; i++) scanf("%d", &P[i]);

  if (N == 2) {
    for (int i = 0; i < P[0]; i++) printf(" AB");
  }
  else {
    int no1 = -1, no2 = -1;
    for (int i = 0; i < N; i++) {
      if (no1 == -1 || P[i] > P[no1]) no1 = i;
    }
    for (int i = 0; i < N; i++) {
      if (i == no1) continue;
      if (no2 == -1 || P[i] > P[no2]) no2 = i;
    }

    if (P[no1] != P[no2]) {
      for (int i = 0; i < P[no1] - P[no2]; i++) {
        printf(" %c", 'A'+no1);
      }
      P[no1] = P[no2];
    }

    bool done = false;
    while (!done) {
      done = true;
      for (int i = 0; i < N; i++) {
        if (i == no1 || i == no2) continue;
        if (P[i] > 0) {
          done = false;
          P[i]--;
          printf(" %c", 'A'+i);
        }
      }
    }
    for (int i = 0; i < P[no1]; i++) {
      printf(" %c%c", 'A' + no1, 'A' + no2);
    }
  }
  puts("");
}

int main() {
  int T;
  scanf("%d", &T);
  int N;
  for (int i = 1; i <= T; i++) {
    scanf("%d", &N);
    printf("Case #%d:", i);
    solve(N);
  }
}
