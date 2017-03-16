#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
#include <climits>
using namespace std;

typedef unsigned long long ull;

ull gcd( ull a, ull b)
{
   while(b != 0)
   {
      ull temp = b;
      b = a % b;
      a = temp;
   }
   return a;
}

ull lcm( ull a, ull b )
{
   return (a * b ) / gcd(a,b);
}

int main()
{
   int x;
   cin >> x;
   for(int i = 0; i < x; i++)
   {
      int result;

      int b, n;
      cin >> b >> n;
      std::vector< int > m;
      for(int j = 0; j < b; j++)
      {
         int k;
         cin >> k;
         m.push_back(k);
      }

      std::vector< int > work;
      for(int j = 0; j < b; j++)
         work.push_back(0);

      //calculate the total in one "pass"
      ull l = 1;
      for(int j = 0; j < m.size(); j++)
      {
         l = lcm(l, m[j]); 
      }

      ull sum = 0;
      for(int j = 0; j < m.size(); j++)
      {
         sum += l / m[j];
      }

      ull remainder = n % sum;

  //    std::cout << "Eliminate " << sum << " per pass " << std::endl;
   //   std::cout << remainder << " left." << std::endl;

      int current = b-1;
      if( remainder == 0)
         remainder = sum;
      for(int j = 0; j < remainder; j++)
      {
         bool empty = false;
         for(int k = 0; k < m.size(); k++)
         {
            if( work[k] == 0 )
            {
               work[k] = m[k];
               empty = true;
               current = k;
          //     std::cout << "Patron " << j << " uses " << k << " for " << m[k] << " minutes " << std::endl;
               break;
            }
         }
         if( !empty )
         {
            int min = INT_MAX;
            int minIndex = 0;
            for(int k = 0; k < m.size(); k++)
            {
               if( work[k] < min )
               {
                  min = work[k];
                  minIndex = k;
               }
            }
          //  time += min;
           /// std::cout << "Wait for " << min << std::endl;
            for(int k = 0; k < m.size(); k++)
            {
               work[k] -= min;
            }
            j--;
         }
      }

      std::cout << "Case #" << i+1 << ": " << current + 1 << std::endl;
   }
}