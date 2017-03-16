#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int TT,ii;
int x,y,n;
int ans=0;

int main()
{
    freopen("B-small-attempt2 (1).in","r",stdin);
    freopen("B-small-attempt2 (1)out.txt","w",stdout);

    int i,j,k;
    int p,q,r;
    int t,tt,ttt;
scanf("%d",&TT);
for(ii=1;ii<=TT;ii++)
{
   scanf("%d %d %d",&x,&y,&n);
   ans=0;
   if(x>y)swap(x,y);
   if(x==1)
    {
      if(y%2==1)
       {
         k=y/2;
         k++;
         if(n<=k)ans=0;
         else
          {
            ans+=(n-k)*2;
          }
       }
      else
       {
         k=y/2;
         if(n<=k)ans=0;
         else
          {
            n-=k;
            ans+=1;
            n--;
            ans+=n*2;
          }
       }
    }
   else if(x==2)
    {
       k=y;
       if(n<=k)ans=0;
       else
        {
          n-=k;
          ans+=2;
          n--;
          if(n>0)
           {
             ans+=2;
             n--;
             if(n>0)
              {
                ans+=3*n;
              }
           }
        }
    }
    else if(x==3)
     {
       if(y==3)
        {
          k=5;
          if(n<=k)ans=0;
          else
           {
             n-=k;
             ans+=3*n;
             if(n==3)ans--;
           }
        }
       else if(y==4)
        {
          k=6;
          if(n<=k)ans=0;
          else
           {
             n-=k;
             ans+=2;
             n--;
             if(n>0)
              {
                ans+=2;
                n--;
                if(n>0)
                 {
                   ans+=3*n;
                   if(n==4)ans++;
                 }
              }
           }
        }
       else if(y==5)
        {
          k=8;
          if(n<=k)ans=0;
          else
           {
             n-=k;
             if(n==1)ans=3;
             if(n==2)ans=6;
             if(n==3)ans=8;
             if(n==4)ans=11;
             if(n==5)ans=14;
             if(n==6)ans=18;
             if(n==7)ans=22;
           }
        }
     }
    else if(x==4)
     {
       k=8;
       if(n<=k)ans=0;
       else
        {
          n-=k;
          ans+=2;
          n--;
          if(n>0)
           {
             n--;
             ans+=2;
             if(n>0)
              {
                ans+=3*n;
                if(n==5)ans+=1;
                if(n==6)ans+=2;
              }
           }
        }
     }
    printf("Case #%d: %d\n",ii,ans);
}
    
    
    scanf(" ");
    return 0;
}
