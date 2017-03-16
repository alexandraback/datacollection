#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    long long i, j, k, l, n, m, t, fin, flag, cases = 0;
    long long arr[10002], arr2[10002];
    string xrr[10002];
    
    freopen("input2.in", "r", stdin);
    freopen("output2.txt", "w", stdout);
    
    cin >> t;
    
    char a;
    
    while (t--) {
          cases++;
          fin = 0;
          cin >> n ; 
                      
          for (i = 0; i < n; i++)
              cin >> xrr[i];
                      
                      flag = 1;
                      int flag2= 1;
                      
                      for (i = 0; i < n; i++)
                      arr[i] = 0;
                      
                      while(1) {
                               a = xrr[0][arr[0]];
                               for(i=0;i<n;i++)
                               arr2[i] = 0;
                               
                               for(i=0;i<n;i++) {
                                                
                                                if(a != xrr[i][arr[i]])
                                                {
                                                     flag = 0;
                                                     break;
                                                }
                                                
                                                while(arr[i]<xrr[i].size() && xrr[i][arr[i]]==a)
                                                {
                                                                         arr2[i]++;
                                                                         arr[i]++;
                                                }
                                                if(arr[i]==xrr[i].size()){
                                                                       flag2=0;
                                                }
                               }
                               
                               if(flag == 0)
                               break;
                               
                               m = 99999999;
                               
                               for(i=0;i<=100;i++) {
                                                   l = 0;
                                                   for(k = 0;k<n;k++) {
                                                         l =l + abs(arr2[k]-i);
                                                   }
                                                   if(m>l)
                                                   m = l;
                               }
                               fin = fin + m;
                               
                               for(i=0;i<n;i++)
                               arr2[i] = 0;
                               
                               if(flag2 == 0)
                               break;
                      }
                      
                      for(i=0;i<n;i++) {
                                       if( arr[i] < xrr[i].size())
                                       {
                                           flag = 0;
                                           break;
                                       }
                      }
                      
                      if (flag == 0)
                         printf("Case #%lld: Fegla Won\n", cases);
                      
                      else
                          printf("Case #%lld: %lld\n", cases, fin);
    }
    
    
    return 0;
}
