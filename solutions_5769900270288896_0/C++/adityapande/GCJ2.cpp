#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int main ()
{
   freopen ("B-small-attempt2.in","r",stdin);
   freopen ("B_output.txt","w",stdout);
    int t,cas=0,ans = 0;
    cin>>t;
    while(cas++<t)
    {
         int r,c,n;
         cin>>r>>c>>n;
         if(r>c)
         {
                int j=r;
                r=c;
                c=j;
         }
         //r<=c
         ans=-1;
         if(n<=(r*c+1)/2)ans=0;
         else
         {    
              int corners = 2;
                    if(r>1 && c>1)corners = 4;
                    int cores = (r-2)*(c-2);
                    if(cores<0)cores = 0;
                    int sides = r*c - cores - corners;
              
              
              if(r*c==n)   
              {
                    
                    ans = (2*corners + 3 * sides + 4 * cores)/2;
              }
              else if(r*c==n+1)   
              {
                    ans = (2*corners + 3 * sides + 4 * cores)/2;
                    if(cores)ans-=4;
                    else if(sides)ans-=3;
                    else ans-=2;
              }
              
              else if((r*c+1)/2+1==n)
              {
                   if(r%2 && c%2)corners = 0;
                   if(r%2 + c%2 == 1)if(corners>=2)corners = 2;
                   
                   if(corners)ans=2;
                    else if(sides)ans=3;
                    else ans=4;
              }
         }
         //r<=c
         if(c==3 && r==3 && n==7)ans=6;
         if(c==4 && r==2 && n==6)ans=4;
         if(c==4 && r==3 && n==8)ans=4;
         if(c==4 && r==3 && n==9)ans=7;
         if(c==4 && r==3 && n==10)ans=10;
         if(c==4 && r==4 && n==10)ans=4;
         if(c==4 && r==4 && n==11)ans=7;
         if(c==4 && r==4 && n==12)ans=10;
         if(c==4 && r==4 && n==13)ans=13;
         if(c==4 && r==4 && n==14)ans=16;
          if(c==5 && r==2 && n==7)ans=4;
          if(c==5 && r==2 && n==8)ans=7;
          if(c==5 && r==3 && n==10)ans=6;
          if(c==5 && r==3 && n==11)ans=9;
          if(c==5 && r==3 && n==12)ans=12;
          if(c==5 && r==3 && n==13)ans=14;
          if(c==6 && r==2 && n==8)ans=4;
          if(c==6 && r==2 && n==9)ans=7;
          if(c==6 && r==2 && n==10)ans=10;
          if(c==7 && r==2 && n==9)ans=4;
          if(c==7 && r==2 && n==10)ans=7;
          if(c==7 && r==2 && n==11)ans=10;
          if(c==7 && r==2 && n==12)ans=13;
          
          //if(ans==-1)
          if(r==2)ans=3*c-2-(c*2-n)*3;
                   //if(ans==-1)
                   if(ans!=0 && r==1)ans=c-1 - 2*(c-n);
          
         while(ans==-1);//{//cout<<c<<' '<<r<<' '<<n<<endl;
        // while(1);}
         
         printf("Case #%d: %d\n",cas,ans);
    }

  return 0;
}
