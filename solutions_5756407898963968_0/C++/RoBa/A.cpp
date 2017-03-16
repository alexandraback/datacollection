#include <cstdio>
#include <vector>
using namespace std;

int a[10][10], b[10][10];

int main() {
  int T, r1, r2;
  scanf("%d", &T);
  for (int ca = 1 ; ca <= T ; ++ca) {
    scanf("%d", &r1);
    --r1;
    for (int i = 0 ; i < 4 ; ++i)
      for (int j = 0 ; j < 4 ; ++j)
        scanf("%d", &a[i][j]);
    scanf("%d", &r2);
    --r2;
    for (int i = 0 ; i < 4 ; ++i)
      for (int j = 0 ; j < 4 ; ++j)
        scanf("%d", &b[i][j]);

    vector<int> ans;    
    for (int j = 0 ; j < 4 ; ++j) {
      for (int j2 = 0 ; j2 < 4 ; ++j2)
        if (b[r2][j2] == a[r1][j]) {
          ans.push_back(a[r1][j]);
          break;
        }
    }
    printf("Case #%d: ", ca);
    if (ans.size() == 1) printf("%d\n", ans[0]);
    else if (ans.size() == 0) printf("Volunteer cheated!\n");
    else printf("Bad magician!\n");
  }
  return 0;
}

