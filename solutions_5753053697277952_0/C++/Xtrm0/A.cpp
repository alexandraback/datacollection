#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;


int main() {_;
  int T;
  int S[30];
  int N, tot;
  int ma, mi, ih, il;
  scanf("%d", &T);

  for (int t=1; t<=T; t++) {
    tot = 0;
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
      scanf("%d", &S[i]);
      tot += S[i];
    }
    printf("Case #%d:", t);
    while (tot > 0) {
      ma = 0;
      mi = 0;
      ih = 0;
      il = 0;
      for (int i=0; i<N; i++) {
        if (S[i] >= ma) {
          mi = ma;
          il = ih;
          ma = S[i];
          ih = i;
        }
      }
      if (tot == 2) {
        printf(" %c%c", 'A'+ih, 'A'+il);
        S[ih]--;
        S[il]--;
        tot-=2;
      } else if (tot > 3 && ma == mi){
        printf(" %c%c", 'A'+ih, 'A'+il);
        S[ih]--;
        S[il]--;
        tot-=2;
      } else {
        printf(" %c", 'A' + ih);
        S[ih]--;
        tot--;
      }
    }
    printf("\n");
  }
  return 0;
}
