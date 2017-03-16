#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

void read(vector<int> &f)
{
  int r;
  scanf("%d", &r);
  r--;
  for(int i = 0; i < 4; i++)
  {
    int x;
    for(int j = 0; j < 4; j++)
    {
      scanf("%d", &x);
      if (i != r) f[x-1] = 0;
    }
  }
}

int main(void)
{
  int T;

  scanf("%d", &T);
  for(int caso = 1; caso <= T; caso++)
  {
    vector<int> f(16, 1);
    read(f);
    read(f);

    int r = -1;
    for(int i = 0; i < 16; i++)
      if (f[i])
      {
        if (r < 0) r = i+1;
        else if (r <= 16) r = 1000;
      }

    printf("Case #%d: ", caso);
    if (r < 0) printf("Volunteer cheated!\n");
    else if (r > 16) printf("Bad magician!\n");
    else printf("%d\n", r);
  }
}
