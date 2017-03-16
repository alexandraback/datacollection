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
    LL i,j,k,l,n,m,t;
    
    freopen("output.txt", "w", stdout);
    
    cin >> t;
    string a;
    string b;
    for(i=1;i<=t;i++) {
                      cin >> n;
                      cin >> a >> b;
                      j = k = 0;
                      char a1;
                      char b1;
                      LL flag = 0;
                      l = 0;
                      LL x1,x2;
                      while(j<a.size() && k<b.size()) {
                                       x1=x2=0;
                                        a1 = a[j];
                                        b1 = b[k];
                                        if(a1 != b1) {
                                              flag = 1;
                                              break;
                                        }
                                        while(j<a.size() && a[j]==a1) {
                                                         x1++;
                                        j++;
                                        }
                                        
                                        while(k<b.size() && b[k]==b1){
                                                         x2++;
                                        k++;
                                        }
                                        l = l + abs(x1-x2);
                      }
                      
                      if(j!=a.size() || k!=b.size())
                      flag = 1;
                      
                      if(flag == 1)
                      printf("Case #%lld: Fegla Won\n",i);
                      else
                      printf("Case #%lld: %lld\n",i,l);
    }
  
    return 0;
}
