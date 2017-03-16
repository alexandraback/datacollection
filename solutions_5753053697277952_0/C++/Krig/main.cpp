#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main() {
  int Z;
  scanf("%d", &Z);
  for (int z=1;z<=Z;z++) {
    printf("Case #%d: ", z);
    int n;
    scanf("%d", &n);
    vector<pair<int, int>> T(n);
    for (int i=0;i<n;i++) {
      scanf("%d", &T[i].first);
      T[i].second = i;
    }
    sort(T.begin(), T.end());
    reverse(T.begin(), T.end());
    while (T[0].first > T[1].first) {
      printf("%c ", T[0].second + 'A');
      T[0].first--;
    }
    for (int i=2;i<n;i++)
      while (T[i].first--)
        printf("%c ", T[i].second + 'A');
    while (T[0].first--)
      printf("%c%c ", T[0].second + 'A', T[1].second + 'A');
    printf("\n");
  }
  return 0;
}
