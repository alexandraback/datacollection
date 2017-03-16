#include <bits/stdc++.h>

using namespace std;

int arr[30];

int main() {
  int nt; scanf("%d", &nt);
  for (int caso = 1; caso <= nt; ++caso) {
    int n; scanf("%d", &n);
    int qnt = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", &arr[i]);
      qnt += arr[i];
    }

    printf("Case #%d:", caso);

    while (qnt > 0) {
      int maj = (qnt - 1) / 2;
      int a = -1;
      for (int i = 0; i < n; ++i) {
        if (arr[i] > maj) {
          if (a == -1) a = i;
          else goto try_two;
        }
      }

      if (a == -1) {
        for (int i = 0; i < n; ++i) {
          if (arr[i] > 0) {
            a = i;
            break;
          }
        }
      }

      arr[a]--;
      qnt--;
      printf(" %c", a + 'A');

      continue;

      try_two:;
      maj = (qnt - 2) / 2;
      a = -1;
      int b = -1;
      for (int i = 0; i < n; ++i) {
        if (arr[i] > maj) {
          if (a == -1) a = i;
          else if (b == -1) b = i;
          else assert(false);
        }
      }
      if (a == -1) {
        for (int i = 0; i < n; ++i) {
          if (arr[i] > 0) {
            a = i; break;
          }
        }
      }
      if (b == -1) {
        b = a;
      }
      arr[a]--;
      arr[b]--;
      qnt -= 2;
      printf(" %c%c", a + 'A', b + 'A');
    }

    puts("");
    cerr << "done " << caso << endl;
  }
  return 0;
}