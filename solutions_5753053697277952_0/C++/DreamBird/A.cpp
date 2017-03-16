#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main ()
{
  freopen("A-small-attempt0.in","r",stdin);   
  freopen("As.txt","w",stdout);
    
  int T, n;  
  int senators[26];
  
  

  // 65 int x = (int)('A');
  cin>>T;
  
  for (int t=1;t<=T;++t)
  {
      cin>>n;
      for (int i=0;i<n;++i)
          cin>>senators[i];
      cout<<"Case #"<<t<<":";
      
      
      int maxi = 1;
      while (maxi>0)
      {
           maxi = 0;
           int count_max = 0;
           int first_find = 0;
           for (int i=0;i<n;++i)
           {
               if (senators[i]>maxi)
               {
                  maxi=senators[i];
                  count_max = 1;
                  first_find=i;
               }
               else if (senators[i]==maxi)
                    count_max++;
           }
       
           //cout<<"Maxi: "<<maxi<<" First find: "<<first_find<<"\n";
       
           if (maxi>0)
           {
               if (count_max%2==1)
               {
                  cout<<" "<<(char)(65+first_find); 
                  senators[first_find]--;          
               }
               else
               {
                  cout<<" "<<(char)(65+first_find);       
                  senators[first_find]--;   
                  for (int i=first_find+1; i<n;++i)
                  {
                      if (senators[i]==maxi)
                      {
                                 cout<<(char)(65+i);           
                                 senators[i]--;
                                 break;
                      }    
                  }
               }
           }
      }
      cout<<"\n";
  }
  
  return 0;
}
