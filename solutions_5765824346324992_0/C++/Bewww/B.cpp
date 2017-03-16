#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;

int f(int xx,int yy)
{
  if(xx>yy)swap(xx,yy);
  int aa;
  while(xx!=0)
  {
    aa=yy%xx;
    yy=xx;
    xx=aa;
  }
  return yy;
}
int T;
int b,n;
int a[1011];
int ans;

int main()
{
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("B-small-attempt0 (1).txt","w",stdout);
    int i,j,k;
    int p,q,r;
    int t,tt,ttt;
    
    scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
  scanf("%d %d",&b,&n);
  for(i=0;i<b;i++)scanf("%d",&a[i]);
  k=1;
  for(i=0;i<b;i++)
   {
     t=f(k,a[i]);
     tt=k/t;
     tt*=a[i];
     k=tt;
   }
  p=0;
  ans=-1;
  for(i=0;i<b;i++)
   {
     p+=k/a[i];
   }
  n%=p;
  n+=p;
  n--;
  //printf("> %d %d %d\n",k,p,n);
  r=0;
  ttt=0;
  for(i=0;;i++)
   {
     for(j=0;j<b;j++)
      {
        if(i%a[j]==0)
         {
          // printf(";; %d %d %d\n",i,ttt,j+1);
           //scanf("%d",&tt);
           if(ttt==n)
            {
              ans=j+1;
              r=1;
              break;
            }
           ttt++;
         }
        if(r==1)break;
      }
     if(r==1)break;
   }
   printf("Case #%d: %d\n",ii,ans);
}    
    
    
    
    scanf(" ");
    return 0;
}
