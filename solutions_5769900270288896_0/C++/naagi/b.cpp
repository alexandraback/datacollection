#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
              
int main (void)
{
  int test, tests;
  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int i, j, k, n, r, c, res = 1000, tres;
    scanf ("%d %d %d", &r, &c, &n);
    for (i = 0; i < 1 << (r * c); i++)
    {
      tres = 0;
      if (__builtin_popcount(i) == n)
      {
        for (j = 1; j < r; j++)
          for (k = 0; k < c; k++)
            tres += (i & (1 << (j * c + k))) && (i & (1 << ((j-1) * c + k )));
          
        for (j = 0; j < r; j++)
          for (k = 1; k < c; k++)
            tres += (i & (1 << (j * c + k))) && (i & (1 << (j * c + k - 1)));
        if (res > tres)
          res = tres;                
      }
    }
    printf ("Case #%d: %d\n", test + 1, res);
  }
  return 0;
}
