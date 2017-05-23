#include <vector> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <ctime> 
#include <string.h> 
using namespace std;
int mat[2],rr[2],now,cnt,ans;
int main()
{
    freopen("debug\\input.txt","r",stdin);
    freopen("debug\\output.txt","w",stdout);
    int i,j,s,p,q,t,tst=0;
    scanf("%d",&t);
    while(t--)
    {
       tst++;
       for(i=0;i<2;i++)
       {
          scanf("%d",&rr[i]);
          rr[i]--; 
          mat[i]=0;
          for(j=0;j<4;j++)
          {
              for(s=0;s<4;s++)
              {
                 int v;
                 scanf("%d",&v);
                 if(j==rr[i])
                    mat[i]|=(1<<v);
              }
          }
       }
       now=(mat[0]&mat[1]);
       cnt=ans=0;
       for(i=1;i<=16;i++)
       {
          if(now&(1<<i))
          {
              cnt++;
              ans=i;
          }
       }
       printf("Case #%d: ",tst);
       if(cnt==0)
          puts("Volunteer cheated!");
       else if(cnt>1)
          puts("Bad magician!");
       else
          printf("%d\n",ans);
    }
    return 0;
}
