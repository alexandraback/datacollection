#include<cstdio>
using namespace std;

int t, id, ans;
bool ok[17];

int main()
{
  freopen("A-small-attempt1.in", "r", stdin);
  freopen("A-small-attempt1.out", "w", stdout);
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    for (int p = 1; p <= 16; p++) ok[p] = 1;
    for (int p = 0; p < 2; p++) {
      scanf("%d", &ans);
      for (int j = 1; j <= 4; j++)
        for (int k = 1; k <= 4; k++) {
          scanf("%d", &id);
          if (j != ans) ok[id] = 0; 
        }
    }
    int num = 0;
    for (int p = 1; p <= 16; p++)
      if (ok[p]) {
        ans = p;
        num++;
      }
    printf("Case #%d: ", i);
    if (num == 0) printf("Volunteer cheated!\n");
    if (num == 1) printf("%d\n", ans);
    if (num > 1) printf("Bad magician!\n");
  }
}
