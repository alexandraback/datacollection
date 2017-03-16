#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <map>
using namespace std;

int main()
{
   int x;
   cin >> x;
   for(int i = 0; i < x; i++)
   {
      int result1 = 0;
      int result2 = 0;

      int n;
      cin >> n;
      std::vector< int > v;
      for(int j = 0; j < n; j++)
      {
         int y;
         cin >> y;
         v.push_back(y);
      }

      for(int j = 1; j < v.size(); j++)
      {
         if( v[j] < v[j-1] )
            result1 += v[j-1] - v[j];
      }

      int maxGap = 0;
      for(int j = 1; j < v.size(); j++)
      {
         if( v[j] < v[j-1] && v[j-1] - v[j] > maxGap )
            maxGap =  v[j-1] - v[j];
      }

      //deal with 0s
      result2 = maxGap * (n-1);
     // std::cout << "Gap: " << maxGap << std::endl;
      for(int j = 0; j < v.size()-1; j++)
      {
         if( v[j] < maxGap)
         {
            result2 -= maxGap - v[j];
         }
      }
      
      std::cout << "Case #" << i+1 << ": " << result1 << " " << result2 << std::endl;
   }
}