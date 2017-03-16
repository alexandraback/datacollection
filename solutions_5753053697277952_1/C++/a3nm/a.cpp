#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  int T;
  scanf("%d", &T);
  for (int ncase = 0; ncase < T; ncase++) {
    int N;
    vector<pair<int, int> > V;
    scanf("%d", &N);
    int ntot = 0;
    for (int i = 0; i < N; i++) {
      int buf;
      scanf("%d", &buf);
      V.push_back(make_pair(buf, i));
      ntot += buf;
    }
    printf("Case #%d:", ncase+1);
    while (ntot > 0) {
      putchar(' ');
      sort(V.rbegin(), V.rend());
      putchar('A' + V[0].second);
      V[0].first--;
      ntot--;
      sort(V.rbegin(), V.rend());
      if (V[0].first*2 > ntot) {
        putchar('A' + V[0].second);
        V[0].first--;
        ntot--;
      }
      sort(V.rbegin(), V.rend());
      if (V[0].first*2 > ntot)
        printf("PROBLEM!\n");
    }
    printf("\n");
  }
  return 0;
}
