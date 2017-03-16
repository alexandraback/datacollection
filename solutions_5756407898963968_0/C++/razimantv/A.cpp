# include <cstdio>
# include <iostream>
# include <vector>
# include <queue>
# include <algorithm>
# include <cstring>
# include <cmath>
# include <cctype>
# include <set>
# include <map>

using namespace std;

int main()
{
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;t++)
  {
    set<int> first;

    int r;

    scanf("%d",&r);
    for(int i=1;i<=4;i++)
    {
      for(int j=0;j<4;j++)
      {
        int a;
        scanf("%d",&a);
        if(i==r)first.insert(a);
      }
    }

    int ans=0;
    scanf("%d",&r);
    for(int i=1;i<=4;i++)
    {
      for(int j=0;j<4;j++)
      {
        int a;
        scanf("%d",&a);
        if(i==r)
        {
          if(first.count(a))
          {
            if(ans==0)ans=a;
            else ans=-1;
          }
        }
      }
    }

    if(ans==0)printf("Case #%d: Volunteer cheated!\n",t);
    else if(ans==-1)printf("Case #%d: Bad magician!\n",t);
    else printf("Case #%d: %d\n",t,ans);
  }
  return 0;
}

