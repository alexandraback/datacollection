#include<cstdio>

using namespace std;

int f[20];

int main()
{
  int t, i, j, k, rez, ans, val;
  scanf("%d", &t);
  for(k = 1; k <= t; ++ k)
  {
    scanf("%d", &ans);
    for(i = 1; i <= 4; ++ i)
      for(j = 1; j <= 4; ++ j)
      {
        scanf("%d", &val);
        if(i == ans)
          ++ f[val];
      }
    scanf("%d", &ans);
    for(i = 1; i <= 4; ++ i)
      for(j = 1; j <= 4; ++ j)
      {
        scanf("%d", &val);
        if(i == ans)
          ++ f[val];
      }
    rez = 0;
    for(i = 1; i <= 16; ++ i)
      if(f[i] == 2)
      {
        if(rez == 0)
          rez = i;
        else
          rez = 17;
      }
    if(rez == 0)
      printf("Case #%d: Volunteer cheated!\n", k);
    else
    {
      if(rez == 17)
        printf("Case #%d: Bad magician!\n", k);
      else
        printf("Case #%d: %d\n", k, rez);
    }
    for(i = 1; i <= 16; ++ i)
      f[i] = 0;
  }
  return 0;
}
