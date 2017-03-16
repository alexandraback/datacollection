#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int gcd(int m, int n) {

     //ensure that m is greater than or equal to n
     if (m < n) {
          swap(m, n);
     }

     //loop until r is 0

     int r = m % n;
     while (r) {
          m = n;
          n = r;
          r = m % n;
     }

     return n;
}

int lcm(int m,int n)
{
     return (m*n)/gcd(m,n);
}

int main()
{
     int test_cases;
     cin >> test_cases;
     for(int z=0; z<test_cases; z++)
     {
          int barbers, linepos;
          cin >> barbers >> linepos;

          int barber_ary[barbers];
          bzero(barber_ary,sizeof(int)*barbers);
          int barber_times[barbers];
          for(int i=0; i<barbers; i++)
               cin >> barber_times[i];

          int yourbarber=1;
          int blcm = -1;
          vector<int> cust_sequence;
          int cuts = 0;
          if(barbers==1)
          {
               yourbarber=1;
               goto out;
          }
          else
               blcm = lcm(barber_times[0],barber_times[1]);

          for(int i=2; i<barbers; i++)
               blcm = lcm(blcm,barber_times[i]);

          while(cuts!=blcm)
          {
               for(int i=0; i<barbers; i++)
                    if(barber_ary[i]==0)
                    {
                         barber_ary[i] = barber_times[i];
                         cust_sequence.push_back(i);
                    }

               //cut hair min free timesteps
               int mintime = INT_MAX;
               for(int i=0; i<barbers; i++)
                    if(mintime > barber_ary[i])
                         mintime = barber_ary[i];
               for(int i=0; i<barbers; i++)
                    barber_ary[i]-=mintime;
               cuts+=mintime;
          }

          yourbarber = cust_sequence[(linepos-1)%cust_sequence.size()]+1;
     out:
          cout << "Case #" << z+1 << ": " << yourbarber << endl;

     }
     return 0;
}
