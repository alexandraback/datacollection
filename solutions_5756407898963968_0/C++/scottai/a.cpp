#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <deque>
#include <bitset>
#include <string>
#include <vector>
#include <sstream>
#define zero(a) (abs(a)<eps)
#define lowbit(a) ((a)&(-(a)))
#define abs(a) ((a)>0?(a):(-(a)))
#define dj(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define cj(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define dis(x1,y1,x2,y2) (((x2)-(x1))*((x2)-(x1))+((y2)-(y1))*((y2)-(y1)))
const double eps = 1e-9;
const double pi = acos(-1);
const int oo = 1000000000;
const int mod = 1000000007;
const double E = 2.7182818284590452353602874713527;
using namespace std;

int a[5][5],s[17];

int main()
{
   freopen("a.in","r",stdin);
   freopen("a.out","w",stdout);
   int q;
   cin>>q;
   for (int t=1;t<=q;t++)
   {
      printf("Case #%d: ",t);
      int x;
      memset(s,0,sizeof(s));
      cin>>x;
      for (int i=1;i<=4;i++)
         for (int j=1;j<=4;j++)
            cin>>a[i][j];
      for (int i=1;i<=4;i++)
         s[a[x][i]]++;
      cin>>x;
      for (int i=1;i<=4;i++)
         for (int j=1;j<=4;j++)
            cin>>a[i][j];
      for (int i=1;i<=4;i++)
         s[a[x][i]]++;
      int t,v=0;
      for (int i=1;i<=16;i++)
         if (s[i]==2)
         {
            v++;
            t=i;
         }
      if (v==1)
         printf("%d\n",t);
      else if (v>1)
         printf("Bad magician!\n",t);
      else
         printf("Volunteer cheated!\n",t);   
   }
   return 0;
}
