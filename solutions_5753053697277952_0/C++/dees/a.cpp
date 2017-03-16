#include <cstdio>
#include <string>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#include <array>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <utility>
#include <cinttypes>

void solve()
{
  int num;
  scanf("%d",&num);
  std::vector<int> v(num);
  for ( int i=0;i<num;++i)
  {
    scanf("%d",&v[i]);
  }
  while (true)
  {
    int secpos = -1;
    bool mulsecpos = false;
    int largest = v[0];
    int pos = 0;
    for (int i=1;i<num;++i)
    {
      if (v[i]>largest)
      {
        secpos = -1;
        largest=v[i];
        pos = i;
        mulsecpos = false;
      }
      else if (v[i]==largest)
      {
        if ( secpos != -1 )
          mulsecpos = true;
        secpos = i;
      }
    }
    if ( largest == 0 )
      break;
    printf(" %c",pos+'A');
    if ( !mulsecpos && secpos != -1 )
    {
      printf("%c",secpos+'A');
      --v[secpos];
    }
    --v[pos];
  }
  printf("\n");
}

int main(int arng, char**argv)
{
  int ncase;
  scanf("%d",&ncase);
  for (int icase=0;icase<ncase;++icase)
  {
    printf("Case #%d:",icase+1);
    solve();
  }
  return 0;
}
