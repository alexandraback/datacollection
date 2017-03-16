#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

typedef pair<int,int> ii;

int m[10];
int arr[10000000];

int lcm(int a, int b) {
  return a * (b / __gcd(a,b));
}

int main() {
  int nt; scanf("%d", &nt);
  for (int _ = 1; _ <= nt; ++_) {
    int b, n; scanf("%d %d", &b, &n);
    int mmc = 1;
    for (int i = 0; i < b; ++i) {
      scanf("%d", &m[i]);
      mmc = lcm(mmc, m[i]);
    }
    //fprintf(stderr, ">>> lcm: %d\n", mmc);
    int cliente = 0;
    for (int tempo = 0; tempo < mmc; ++tempo) {
      for (int i = 0; i < b; ++i) {
        if (tempo % m[i] == 0) {
          arr[cliente++] = i;
        }
      }
    }
    printf("Case #%d: %d\n", _, arr[(n-1) % cliente] + 1);
  }
  return 0;
}