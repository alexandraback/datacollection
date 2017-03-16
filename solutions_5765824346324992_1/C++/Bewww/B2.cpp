#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int T;
long long b,n;
long long a[1011];
long long ans;
int f(long long M)
{
  if(M==0)
   {
     if(n<=b+1)
      {
        ans = n;
        return 1;
      }
     return 0;
   }
  int i,j;
  long long p,q,k;
  k=0;
  for(i=0;i<b;i++)
   {
     k+=((M-1)/a[i])+1;
   }
  if(k >= n)return 0;
  
  for(i=0;i<b;i++)
   {
     if(M%a[i]==0)
      {
        k++;
        if(k==n)
         {
           ans=i+1;
           return 1;
         }
      }
   }
  return  2;
  
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-largeout.txt","w",stdout);
    int i,j,k;
    int p,q;
    int t,tt,ttt;
    long long L,R,M;
    long long maxx;
    
    scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
  scanf("%I64d %I64d",&b,&n);
  maxx=0;
  for(i=0;i<b;i++)
    {
      scanf("%I64d",&a[i]);
      if((long long)a[i]>maxx)maxx=(long long)a[i];
    }
  L=0;R=maxx*n;
  while(L<=R)
   {
    // printf("> %I64d %I64d %I64d\n",L,M,R);
     M=(L+R)/2;
     q=f(M);
     if(q==1)break;
     else if(q==0)R=M;
     else if(q==2)L=M+1;
   }
  
   printf("Case #%d: %I64d\n",ii,ans);
}    
    
    
    
    scanf(" ");
    return 0;
}
