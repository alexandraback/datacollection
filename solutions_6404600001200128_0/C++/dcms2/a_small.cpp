#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

typedef pair<int,int> ii;

const int N = 1005;

int arr[N];

int main() {
  int nt; scanf("%d", &nt);
  for (int _ = 1; _ <= nt; ++_) {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &arr[i]);
    }
    int taxa = 0;
    int a = 0, b = 0;
    for (int i = 1; i < n; ++i) {
      if (arr[i] <= arr[i-1]) {
        taxa = max(taxa, arr[i-1] - arr[i]);
        a += arr[i-1] - arr[i];
      }
    }
    for (int i = 1; i < n; ++i) {
      b += min(arr[i-1], taxa);
    }
    printf("Case #%d: %d %d\n", _, a, b);
    fprintf(stderr, ">>> caso %d\n", _);
  }
  return 0;
}