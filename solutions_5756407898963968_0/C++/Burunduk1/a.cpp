/**
 * Author: Sergey Kopeliovich (Burunduk30@gmail.com)
 * Date: 2014.04.12
 */

#include <cstdio>
#include <cassert>
#include <algorithm>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

void solve( int tn )
{
  int is[16] = {0};
  forn(t, 2)
  {
    int row, a;
    scanf("%d", &row), row--;
    forn(i, 4)
      forn(j, 4)
        scanf("%d", &a), is[a - 1] += (i == row);
  }
  int res = -1, cnt = 0;
  forn(t, 16)
    if (is[t] == 2)
      res = t, cnt++;
  printf("Case #%d: ", tn);
  if (cnt == 0)
    puts("Volunteer cheated!");
  else if (cnt > 1)
    puts("Bad magician!");
  else
    printf("%d\n", res + 1);
}

int main()
{
  int tn;
  scanf("%d", &tn);
  forn(t, tn)
    solve(t + 1);
  return 0;
}
