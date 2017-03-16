#include <map>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <string>
#include <climits>
using namespace std;

typedef unsigned long long ull;

int main()
{
   int n;
   cin >> n;
   
   for(int a = 0; a < n; a++)
   {
      int result = INT_MAX;
      int r, c, t;
      cin >> r >> c >> t;
      

      std::vector< std::vector< bool > > v;
      v.resize( r );
      for(int i = 0; i < v.size(); i++)
         v[i].resize( c );

      for(ull i = 0; i <= 1 << r * c; i++)
      {
         //init
         for( int j = 0; j < r; j++)
            for(int k = 0; k < c; k++)
               v[j][k] = false;

         for( int j = 0; j < v.size(); j++)
            for( int k = 0; k < v[j].size(); k++)
            {
               if( i & (1 << (j * v[j].size() + k) ) )
                  v[j][k] = true;
            }

    

         //scan
            int counter = 0;
            for(int j = 0; j < r; j++)
               for(int k = 0; k < c; k++)
                  if( v[j][k] == true )
                     counter++;
            if( counter != t )
               continue;
            /*
              for(int j = 0; j < v.size(); j++)
      {
         for(int k = 0; k < v[j].size(); k++)
         {
            std::cout << v[j][k];
         }
         std::cout << std::endl;
      }
      std::cout<< std::endl;
      */
         //eval
            int temp = 0;
            for(int j = 0; j < r; j++)
               for(int k = 0; k < c; k++)
               {
                  if( j < r - 1 && v[j][k] && v[j+1][k] )
                     temp++;
                  if( k < c - 1 && v[j][k] && v[j][k+1] )
                     temp++;
               }

            if( temp < result )
               result = temp;
      }



      std::cout << "Case #" << a+1 << ": " << result << std::endl;
   }


}