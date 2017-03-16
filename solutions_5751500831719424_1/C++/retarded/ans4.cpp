/* HellGeek */
/* Shiva Bhalla */
/* iit2012077 */


#include<stdio.h>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<set>
#include<string>
#include<string.h>
#include<iostream>
#include<queue>
#include<stack>
#include<math.h>

#define LL long long
#define FIT(i,t) for(i=0;i<t;i++)
#define FIN(i,n) for(i=0;i<n;i++)
#define FJT(j,t) for(j=0;j<t;j++)
#define FJN(j,n) for(j=0;j<n;j++)
#define MAX2(a,b) a>b?a:b
#define MIN2(a,b) a>b?b:a
#define REP(i,a,b) for(i=a;i<=b;i++)

using namespace std;

int main()
{
    LL i,j,k,l,n,m,t,fin;
    string x[10000];
    LL len[10000];
    LL dif[10000];
    //freopen("out.txt","w",stdout);
    cin >> t;
    LL flag;
    char a;
    for(i=1;i<=t;i++) {
                      fin = 0;
                      cin >> n ; 
                      
                      for(j=0;j<n;j++)
                      cin >> x[j];
                      
                      flag = 1;
                      LL flag2= 1;
                      
                      for(j=0;j<n;j++)
                      len[j] = 0;
                      
                      while(1) {
                               a = x[0][len[0]];
                               for(j=0;j<n;j++)
                               dif[j] = 0;
                               
                               for(j=0;j<n;j++) {
                                                
                                                if(a != x[j][len[j]])
                                                {
                                                     flag = 0;
                                                    // cout << "1" << endl;
                                                     break;
                                                }
                                                
                                                while(len[j]<x[j].size() && x[j][len[j]]==a)
                                                {
                                                                         dif[j]++;
                                                                         len[j]++;
                                                }
                                                if(len[j]==x[j].size())
                                                {
                                                                       flag2=0;
                                                                       //break;
                                                }
                               }
                               
                               if(flag == 0)
                               break;
                               
                               m = 99999999;
                               
                               for(j=0;j<=100;j++) {
                                                   l = 0;
                                                   for(k = 0;k<n;k++) {
                                                         l =l + abs(dif[k]-j);
                                                   }
                                                   if(m>l)
                                                   m = l;
                               }
                               fin = fin + m;
                               
                               for(j=0;j<n;j++)
                               dif[j] = 0;
                               
                               if(flag2 == 0)
                               break;
                      }
                      
                      for(j=0;j<n;j++) {
                                       if( len[j] < x[j].size())
                                       {
                                           flag = 0;
                                          //cout << "1" << endl;
                                           break;
                                       }
                      }
                      
                      if(flag == 0)
                      printf("Case #%lld: Fegla Won\n",i);
                      
                      else
                      printf("Case #%lld: %lld\n",i,fin);
    }
    
    
    return 0;
}
