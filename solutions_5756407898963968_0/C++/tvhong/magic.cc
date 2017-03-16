#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 17;
int T, t, h[N], r, num;
int main() {
  scanf("%d", &T);
  for (int t=1; t<=T; t++) {
    memset(h, 0, sizeof h);
    scanf("%d", &r);
    for (int i=1; i<=4; i++)
      for (int j=1; j<=4; j++) {
        scanf("%d", &num);
        if (i != r) continue;
        //printf("%d\n", num);
        h[num] = 1;
      }
    scanf("%d", &r);
    vector<int> results;
    for (int i=1; i<=4; i++) 
      for (int j=1; j<=4; j++) {
        scanf("%d", &num);
        if (i != r) continue;
        //printf("%d\n", num);
        if (h[num]) results.push_back(num);
      }
    printf("Case #%d: ", t);
    if (results.size() == 0)
      printf("Volunteer cheated!\n");
    else if (results.size() == 1)
      printf("%d\n", results[0]);
    else 
      printf("Bad magician!\n");
  }
  return 0;
}
