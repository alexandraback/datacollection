#include <bits/stdc++.h>
using namespace std;

int T, N, P[30];

int main() {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w+", stdout);
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &N);
    int b = 0;
    for (int i = 0; i < N; i++) {
      scanf("%d", &P[i]);
      b += P[i];
    }
    vector<char> ans;
    for (int j = 0, k; j < b; j++) {
      k = -1;
      for (int i = 0; i < N; i++) {
        if ((P[i] && k == -1) || (P[i] > P[k])) k = i;
      }
      P[k]--;
      ans.push_back(k+'A');
    }
    printf("Case #%d: ", t);
    int c = ans.size();
    for (int i = 0; i < c; i++) {
      printf("%c", ans[i]);
      if (i % 2 != c % 2) printf(" ");
    }
    printf("\n");
  }
  return 0;
}

