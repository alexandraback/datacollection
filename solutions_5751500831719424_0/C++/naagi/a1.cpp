#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MaxN = 111, MaxL = 111;
char s[MaxN][MaxL];
char f[MaxL];
int cnt[MaxN][MaxL];
              
int main (void)
{
  int test, tests;

  freopen ("a.in", "rt", stdin);
  freopen ("a.out", "wt", stdout);

  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int res = 0, i, j, l, k, n;
    scanf ("%d", &n);
    for (i = 0; i < n; i++)
      scanf ("%s", s[i]);
    f[0] = s[0][0];
    k = 1;
    for (i = 1; i < strlen(s[0]); i++)
      if (s[0][i] != s[0][i-1])
        f[k++] = s[0][i];
    memset (cnt, 0, sizeof (cnt));
    for (i = 0; i < n; i++)
    {
      for (j = 0, l = 0; j < k; j++)
      {
        if (s[i][l] != f[j])
          res = -1;
        while (s[i][l] == f[j])
        {
          l++;
          cnt[i][j]++;
        }
      }
      if (s[i][l] != 0)
        res = -1;
    }   
    if (res == -1)
      printf ("Case #%d: Fegla Won\n", test + 1);
    else
    {

      for (j = 0; j < k; j++)
      {
        int tres = 100000;
        for (l = 1; l <= 100; l++)
        {
          int ttres = 0;
          for (i = 0; i < n; i++)
            ttres += abs(cnt[i][j] - l);
          if (tres > ttres)
            tres = ttres;
        }
        res += tres;
      }
        
      printf ("Case #%d: %d\n", test + 1, res);

    }
  }
  return 0;
}
