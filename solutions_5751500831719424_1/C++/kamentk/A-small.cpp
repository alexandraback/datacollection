#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

string a[1<<10];
string s[1<<10];
int v[1<<7][1<<7];

int main ()
{  
   freopen ("A-large.in", "r", stdin);
   freopen ("A-large.out", "w", stdout);
   int t,i,n,tt,j,tj,k,fll=0,pp,cans=0,minn=10000,ans=0;
   cin>>t;
   
   for(tt=1;tt<=t;tt++)
   {
      ans=0;
      for(i=0;i<=100;i++)
      {
         for(j=0;j<=100;j++)
         {
            v[i][j]=0;
         }
      }
      
      cin>>n;
      for(i=1;i<=n;i++)
      {
         cin>>a[i];
         s[i]=a[i];
      }
      
      for(i=1;i<=n;i++)
      {
         for(j=0;j<s[i].length()-1;j++)
         {
            //cout<<i<<" "<<j<<" "<<a[i][j]<<" "<<a[i][j+1]<<endl;
            if(s[i][j]==s[i][j+1])
            {
               s[i].erase(j,1);
               v[i][j]++;
               j--;
            }
         }
      }
      
      /*for(i=1;i<=n;i++)
      {
          cout<<s[i]<<endl;
      }*/
      
      for(i=1;i<=n;i++)
      {
         /*for(j=0;j<=s[i].length();j++)
         {
            cout<<v[i][j]<<" ";
         }
         cout<<endl;*/
      }
      
      for(i=1;i<n;i++)
      {
         if(s[i]!=s[i+1])
         {
            printf("Case #");
            printf("%d",tt);
            printf(": ");
            printf("Fegla Won\n");
            fll=1;
            break;
         }
      }
      if(fll==1)
      {
         fll=0;
         continue;
      }
      else
      {
            for(i=0;i<s[1].length();i++)
            {
               for(pp=0;pp<=100;pp++)
               {
                  cans=0;
                  for(j=1;j<=n;j++)
                  {
                     cans=cans+abs(pp-v[j][i]);
                     //cout<<pp<<" "<<cans<<endl;
                  }
                  minn=min(minn,cans);
               }
               //cout<<minn<<endl;
               ans=ans+minn;
               minn=10000;
            }
            printf("Case #");
            printf("%d",tt);
            printf(": ");
            printf("%d\n",ans);
      }
      
      //system("pause");
   }
   //system("pause");
   return 0;
}
/*

3
2
mmaw
maw
2
gcj
cj
3
aaabbb
ab
aabb

*/
