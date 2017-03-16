#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;
#define mo 321555123
#define eps 1e-6
#define inf 1000000
struct hammer
{
    char let;
    int num;
}aox[111][112];
int li;
int t,n;
char box[111][111];
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("ans.txt","w",stdout);
    scanf("%d",&t);
    int cac=0;
    while(t--)
    {
      scanf("%d",&n);
      for(int i=1;i<=n;i++)
        scanf("%s",box[i]);
      char a='1';
      li=0;
      cac++;
      printf("Case #%d: ",cac);
      memset(aox,0,sizeof(aox));
      for(int i=0;i<strlen(box[1]);i++)
      {
        if(a!=box[1][i])
        {
          li++;
          aox[1][li].let=box[1][i];
          aox[1][li].num=1;
          a=box[1][i];
        }
        else
        {
          aox[1][li].num++;
        }
      }
      bool con=0;
      for(int i=2;i<=n;i++)
      {
          int a=1;
          for(int j=0;j<strlen(box[i]);j++)
          {
            while(box[i][j]!=aox[1][a].let)
            {
              if(aox[i][a].num==0) {con=1;break;}
              a++;
              if(a>li) {con=1;break;}
            }
            if(con) break;
            aox[i][a].num++;
            if(j==strlen(box[i])-1 && a!=li)
              con=1;
          }
          if(con) {printf("Fegla Won\n");break;}
      }
      if(!con)
      {
        int ans=0;
        for(int i=1;i<=li;i++)
        {
          int minn=inf;
          for(int j=1;j<=n;j++)
          {
            int sum=0;
            for(int u=1;u<=n;u++)
                sum+=abs(aox[u][i].num-aox[j][i].num);
            minn=min(minn,sum);
          }
          ans+=minn;
        }
        printf("%d\n",ans);
      }
    }
    return 0;
}
