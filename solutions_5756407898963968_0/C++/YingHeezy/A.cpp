#include <cstdio>
using namespace std;

int main() {
  int T, tmp, ans, R;
  int A[5];
  scanf("%d\n", &T);
  for(int iii = 1; iii <= T; ++iii) {
    ans = -1;
    scanf("%d", &R);
    R--;
    for(int i = 0; i < 4; ++i) {
      for(int j = 0; j < 4; ++j) {
        scanf("%d", &tmp);
        if (i == R) A[j] = tmp;
      }
    }
    scanf("%d", &R);
    R--;
    for(int i = 0; i < 4; ++i) {
      for(int j = 0; j < 4; ++j) {
        scanf("%d", &tmp);
        if (i == R) {
          for(int k = 0; k < 4; ++k) {
            if (tmp == A[k]) {
              if (ans > 0) ans = 17;
              else ans = tmp;
            }
          }
        }
      }
    }
    printf("Case #%d: ", iii);
    switch(ans) {
      case -1:
        printf("Volunteer cheated!\n");
        break;
      case 17:
        printf("Bad magician!\n");
        break;
      default:
        printf("%d\n", ans);
    }
  }
}
