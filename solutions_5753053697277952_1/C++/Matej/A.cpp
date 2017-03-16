#include <cstdio>
#include <algorithm>
using namespace std;

const int infinity = 1e9 + 9;

int N;
int P[1009];

int main()
{
  int T;
  scanf("%d", &T);
  for (int Ti = 1; Ti <= T; Ti++)
  {
    // input
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf(" %d", &P[i]);
    }
    
    // output
    printf("Case #%d:", Ti);
    while (true) {
      // find maximum and 2nd largest index and sum
      int sum = 0;
      int maxval = 0;
      int maxind = -1;
      for (int i = 0; i < N; ++i) {
        sum += P[i];
        if (P[i] > maxval) {
          maxval = P[i];
          maxind = i;
        }
      }
      if (sum == 0)
        break;
      
      int maxval2 = 0;
      int maxind2 = -1;
      for (int i = 0; i < N; ++i) {
        if (i != maxind && P[i] > maxval2) {
          maxval2 = P[i];
          maxind2 = i;
        }
      }
      char a = 'A' + maxind;
      char b = 'A' + maxind2;
      if (sum == 0)
        break;
      else if (maxval == sum / 2 && maxval2 == sum / 2 && sum % 2 == 0) {
        printf(" %c%c", a, b);
        P[maxind]--;
        P[maxind2]--;
      }
      else {
        printf(" %c", a);
        P[maxind]--;
      }
    }
    printf("\n");
  }
  return 0;
}
