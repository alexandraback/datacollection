#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <stdio.h>
#include <list>
#include <vector>
#include <map>
#include <set>
#include <limits.h>
#define ll long long int
#define mod 1000000009
using namespace std;

char a[110][110];
string s[110];
ll cnt[110][110];


int main()
{

 // freopen("C:\\Users\\jack\\Desktop\\in.txt","r",stdin);
 //freopen("C:\\Users\\jack\\Desktop\\out.txt","w",stdout);
 
    int test,n,x,tt;
    scanf("%d",&tt);
    test=1;
    
    while(test<=tt)
    {
           scanf("%d",&n);
           bool flag=false;
           for(int i=0;i<n;i++)
           {
                   scanf("%s",a[i]);
                   s[i]="";
                   x=strlen(a[i]);
                   s[i]+=a[i][0];
           
                   int k=0;
                   cnt[i][0]=1;
                   
                   for(int j=1;j<x;j++)
                       {if(a[i][j]!=a[i][j-1])
                              {s[i]+=a[i][j];k++;cnt[i][k]=1;}
                        else 
                          cnt[i][k]++;
                       }
                            
                   if(i!=0)
                         if( strcmp(&s[i][0],&s[i-1][0])!=0){flag=true;}
                           
                   
                   }      

           if(flag){printf("Case #%d: Fegla Won\n",test);test++;continue;}
           int gg=s[0].length();
           ll cost=0;
           
           for(int i=0;i<gg;i++)
           {
              
             ll cn=0;
             
               for(int j=0;j<n;j++)
               cn=max(cn,cnt[j][i]);   
           
            ll ff=INT_MAX;
            ll temp=0;
            
              for(int j=1;j<=cn;j++)
                {
                      temp=0;
                      
                      for(int k=0;k<n;k++)
                       temp=temp+abs(cnt[k][i]-j);
                      
                      ff=min(ff,temp);
                      }
                      
                   cost+=ff;
                   
              }

          printf("Case #%d: %lld\n",test,cost);
          test++;
                 }

    }
