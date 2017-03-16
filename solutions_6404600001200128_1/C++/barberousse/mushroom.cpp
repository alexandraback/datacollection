// basic file operations
#include <iostream>
#include <fstream>
using namespace std;

#define DEBUG 0
#define trace if( DEBUG ) printf

/*
qsort( device, N, sizeof(uint64_t), compare );
int compare (const void * a, const void * b)
{
  return ( *(uint64_t*)a - *(uint64_t*)b );
}
*/

int main (int argc, char **argv)
{
   if( argc != 2 ) return -1;
   ifstream myfile;
   int ntests;

   myfile.open( argv[1] );
   myfile >> ntests;
   trace( "Ntests = %d\n", ntests );

   for( int i = 1; i <= ntests; i++ )
   {
      trace( "------------\n" );
      trace( "| Test #%02d |\n", i );
      trace( "------------\n" );

      int N, M[1000];

      int res1 = 0, res2 = 0;

      myfile >> N;
      for(int j = 0; j < N; j++ )
      {
         myfile >> M[j];
      }

      int max = 0;
      for(int j = 1; j < N; j++ )
      {
         int diff = M[j-1] - M[j];
         if(diff > 0) { res1 += diff; }
         if(diff > max) { max = diff; }
      }

      trace( "max = %d\n", max );

      int plate = M[0];
      for( int j = 1; j < N; j++ )
      {
         trace( "plate IN = %d\n", plate );
         if( plate < max ) { res2 += plate; } else { res2 += max; }
         plate = M[j];
      }

      printf( "Case #%d: %d %d\n", i, res1, res2 );
   }

   myfile.close();
   return 0;
}
