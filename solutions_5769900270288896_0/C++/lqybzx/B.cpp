#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int map[17][17];
int b[1001];
int main()
{
	 freopen("B-small-attempt0.in","r",stdin);
	 freopen("B-small-attempt0.out","w",stdout);
	 int T;
	 scanf("%d",&T);
	 int tx=0;
     while(T>0)
     {
     	  tx++;
          T--;
          int r,c,k;
          scanf("%d%d%d",&r,&c,&k);
          int i,j;
          memset(b,0,sizeof(b));
          for(i=r*c-k+1;i<=r*c;i++)
               b[i]=1;
          int ans=2100000000;
          do
          {
          	   memset(map,0,sizeof(map));
               for(i=1;i<=r*c;i++)
               {
               	    if(b[i]==1)
               	    {
               	         int x=(i-1)/c+1,y=i-(x-1)*c;
                         map[x][y]=1;
                    }
               }
               int s=0;
               for(i=1;i<=r;i++)
                    for(j=1;j<=c;j++)
                         if(map[i][j]==1)
                              s+=((map[i][j]==map[i+1][j])+(map[i][j]==map[i-1][j])+(map[i][j]==map[i][j+1])+(map[i][j]==map[i][j-1]));
               s=s/2;
               ans=min(s,ans);
          }
          while(next_permutation(b+1,b+1+r*c));
          printf("Case #%d: %d\n",tx,ans);
     }
     return 0;
}
