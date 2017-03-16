#include <cstdio>

void treatCase()
{
  bool poss[17];
  for (int i = 1; i <= 16; ++i)
    poss[i] = true;
  for (int l = 0; l < 2; ++l)
  {
    int j;
    scanf("%d", &j);
    for (int i = 1; i <= 4; ++i)
    {
      for (int r = 1; r <= 4; ++r)
      {
        int td;
        scanf("%d", &td);
        if (i != j)
          poss[td] = false;
      }
    }
  }
  int ok = -1;
  for (int i = 1; i <= 16; ++i)
    if (poss[i])
    {
      if (ok != -1)
      {
        printf("Bad magician!");
        return;
      }
      ok = i;
    }
  if (ok == -1)
    printf("Volunteer cheated!");
  else
    printf("%d", ok);
}

int main()
{
  int nbCases;
  scanf("%d", &nbCases);
  for (int iCase = 1; iCase <= nbCases; ++iCase)
  {
    printf("Case #%d: ", iCase);
    treatCase();
    printf("\n");
  }
  return 0;
}
