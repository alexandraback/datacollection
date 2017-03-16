#include<stdio.h>
#include<string.h>
#include<algorithm>

using namespace std;
int T;
int n;
int a[1011];
int b[1011];
int ans1,ans2;

int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("A-small-attempt0 (1).txt","w",stdout);    
    
    int i,j,k;
    int p,q,r;
    int t,tt,ttt;
    scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
   scanf("%d",&n);
   for(i=0;i<n;i++)scanf("%d",&a[i]);
   k=0;
   for(i=0;i<n-1;i++)
    {
      b[i]=a[i]-a[i+1];
      if(b[i]>0)
       {
         if(k<b[i])k=b[i];
       }
    }
   ans1=0;
   for(i=0;i<n-1;i++)  
    {
      if(a[i]>a[i+1])ans1+=a[i]-a[i+1];
    }
   ans2=0;
   for(i=0;i<n-1;i++)
    {
      if(b[i]<=0)
       {
         if(a[i]>k)ans2+=k;
         else ans2+=a[i];
       }
      else
       {
         if(a[i]>k)ans2+=k;
         else ans2+=a[i];
       }
    }
   
   printf("Case #%d: %d %d\n",ii,ans1,ans2);
}
    
    
    scanf(" ");
    return 0;
}
