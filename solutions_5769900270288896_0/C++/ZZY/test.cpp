#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>
#include<stack>
#define oo 105
#define ll long long
using namespace std;  
int s[20][20];
int Run(int t,int n,int r,int c)
{
      int count=0,ans=0,i,j,x; 
      for (i=0;i<r;i++)
         for (j=0;j<c;j++)
         {
               x=i*c+j;
               if (t&(1<<x)) count++,s[i][j]=1;
                        else s[i][j]=0;
         }
      if (count!=n) return 1<<30;
      for (i=0;i<r;i++)
        for (j=0;j<c;j++)
        {
               if (!s[i][j]) continue;
               if (i<r && s[i+1][j]) ans++;
               if (j<c && s[i][j+1]) ans++;  
        }
      return ans;             
}
int main()
{  
      int T,R,C,N,cases,ans;
      freopen("B-small-attempt0.in","r",stdin);
      freopen("output.txt","w",stdout); 
      scanf("%d",&T);
      for (cases=1;cases<=T;cases++)
      {
             scanf("%d%d%d",&R,&C,&N),ans=1<<30;
             memset(s,0,sizeof(s));
             for (int t=0;t<(1<<(R*C));t++)
                ans=min(ans,Run(t,N,R,C));
             printf("Case #%d: %d\n",cases,ans);
      } 
      return 0;
}
