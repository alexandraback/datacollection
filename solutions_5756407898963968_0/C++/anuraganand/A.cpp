#include <bits/stdc++.h>

using namespace std;

int a[5][5], b[5][5];

int main() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int tests;
  scanf("%d", &tests);
  for(int testNo = 1; testNo <= tests; testNo++) {
    int aRow, bRow;
    scanf("%d", &aRow);
    for(int i = 1; i <= 4; i++)
      for(int j = 1; j <= 4; j++)
        scanf("%d", &a[i][j]);

    scanf("%d", &bRow);
    for(int i = 1; i <= 4; i++)
      for(int j = 1; j <= 4; j++)
        scanf("%d", &b[i][j]);

    set <int> candidates;
    for(int i = 1; i <= 4; i++)
      for(int j = 1; j <= 4; j++)
        if(a[aRow][i] == b[bRow][j]) candidates.insert(a[aRow][i]);

    printf("Case #%d: ", testNo);

    if(candidates.size() == 0) puts("Volunteer cheated!");
    else if(candidates.size() > 1) puts("Bad magician!");
    else printf("%d\n", *candidates.begin());

  }
  return 0;
}