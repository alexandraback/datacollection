#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
     int test_cases;
     cin >> test_cases;
     for(int z=0; z<test_cases; z++)
     {
          int samples;
          cin >> samples;
          int s_ary[samples];
          for(int i=0; i<samples; i++)
               cin >> s_ary[i];

          //Method 1: max(0,s_ary[i+1]-s_ary[i]
          int shrooms_eaten_m1 = 0;
          int maxminrate = 0;
          for(int i=0; i<samples-1; i++)
          {
               shrooms_eaten_m1+=max(0,s_ary[i]-s_ary[i+1]);
               if(s_ary[i]-s_ary[i+1] > maxminrate) //for M2
                    maxminrate=s_ary[i]-s_ary[i+1];
          }

          //Method 2: find maximum minimum rate, then apply
          int shrooms_eaten_m2 = 0;
          for(int i=0; i<samples-1; i++)
               shrooms_eaten_m2+=min(s_ary[i],maxminrate);

          cout << "Case #" << z+1 << ": " << shrooms_eaten_m1 << ' ' << shrooms_eaten_m2 << endl;
     }

     return 0;
}
