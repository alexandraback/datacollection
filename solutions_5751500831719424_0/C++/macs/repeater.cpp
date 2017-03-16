#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define p(x) cerr<<#x<<":"<<x<<"\n"
#define lim 101
int cs,c,n,i,j,f,res,s,mn,k;
char C[lim][lim],str[lim];
int S[lim][lim],Z[lim];
int main()
{
  scanf("%d",&cs);
  for(c=1;c<=cs;c++)
  {
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
      Z[i]=0;
      scanf("%s",str);
      for(j=0;j<strlen(str);j++)
        if(!j || str[j]!=str[j-1])
        {
          S[i][Z[i]]=1;
          C[i][Z[i]++]=str[j];
        }
        else
          S[i][Z[i]-1]++;
    }
    f=1;
    for(i=1;i<n;i++)
      if(Z[i]!=Z[0])
        f=0;
      else
        for(j=0;j<Z[0];j++)
          if(C[i][j]!=C[0][j])
            f=0;
    printf("Case #%d: ",c);
    if(f)
    {
      res=0;
      for(i=0;i<Z[0];i++)
      {
        mn=1000000000;
        for(j=1;j<=100;j++)
        {
          for(k=s=0;k<n;k++)
            s+=abs(j-S[k][i]);
          mn=min(mn,s);
        }
        res+=mn;
      }
      printf("%d\n",res);
    }
    else
      printf("Fegla Won\n");
  }
	return 0;
}
