#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;
typedef unsigned long long ull ;

int main()
{
   ull x;
   cin >> x;
   for(ull i = 0; i < x; i++)
   {
      ull result1 = 0;
      ull result2 = 0;

      ull n;
      cin >> n;
      std::vector< ull > v;
      for(ull j = 0; j < n; j++)
      {
         ull y;
         cin >> y;
         v.push_back(y);
      }

      for(ull j = 1; j < v.size(); j++)
      {
         if( v[j] < v[j-1] )
            result1 += v[j-1] - v[j];
      }

      ull maxGap = 0;
      for(ull j = 1; j < v.size(); j++)
      {
         if( v[j] < v[j-1] && v[j-1] - v[j] > maxGap )
            maxGap =  v[j-1] - v[j];
      }

      //deal with 0s
      result2 = maxGap * (n-1);
     // std::cout << "Gap: " << maxGap << std::endl;
      for(ull j = 0; j < v.size()-1; j++)
      {
         if( v[j] < maxGap)
         {
            result2 -= maxGap - v[j];
         }
      }
      
      std::cout << "Case #" << i+1 << ": " << result1 << " " << result2 << std::endl;
   }
}