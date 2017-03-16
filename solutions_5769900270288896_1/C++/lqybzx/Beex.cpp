#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int map[17][17];
int ax[17][17];
int b[1001];
int main()
{
	 freopen("B-large.in","r",stdin);
	 freopen("B-large.out","w",stdout);
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
          long long ans=0;
          int tk=k;
          k-=(r*c)/2;
          if(k<=0||tk<=(r*c+1)/2)
          {
               k=-2;
               ans=0;
          }
          else if(r!=1&&c!=1)
          {
          	   int x1=1+r%2,y1=1+c%2;
               int xx=(r-x1)/2,yy=(c-y1)/2;
               int xxt=xx+x1,yyt=yy+y1;
               if(x1==2&&y1==2)
               {
                    ans+=8;
                    k-=4;
               }
               else
               {
                    ans+=4;
                    k-=2;
               }
               while(k<0)
               {
                    k++;
                    ans-=2;
               }
               int sx=xx+yy;
               if(r%2==1)
                    sx+=yy;
               else
               {
                    if(y1==1)
                         sx+=(c-yyt)-1;
                    else
                         sx+=(c-yyt);
               }
               if(c%2==1)
                    sx+=xx;
               else
               {
                    if(x1==1)
                         sx+=(r-xxt)-1;
                    else
                         sx+=(r-xxt);
               }
               if(k<=sx)
                    ans+=k*3;
               else
               {
                    ans+=sx*3;
                    k-=sx;
                    ans+=k*4;
               }
          }
          else if(r==1)
          {
          	   k=tk;
               k-=c/2;
               if(k>0)
               {
                    if(c%2==0)
                    {
                         k--;
                         ans+=1;
                    }
                    else
                    {
                         k-=2;
                         ans+=2;
                         if(k<0)
                         {
                              k++;
                              ans--;
                         }
                    }
                    if(k>0)
                    {
                         ans+=k*2;
                    }
               }
          }
          else if(c==1)
          {
          	   k=tk;
               k-=r/2;
               if(k>0)
               {
                    if(r%2==0)
                    {
                         k--;
                         ans+=1;
                    }
                    else
                    {
                         k-=2;
                         ans+=2;
                         if(k<0)
                         {
                              k++;
                              ans--;
                         }
                    }
                    if(k>0)
                    {
                         ans+=k*2;
                    }
               }
          }
          printf("Case #%d: %d\n",tx,ans);
     }
     return 0;
}
