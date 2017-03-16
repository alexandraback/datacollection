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

unsigned GCD(unsigned u, unsigned v) {
    while ( v != 0) {
        unsigned r = u % v;
        u = v;
        v = r;
    }
    return u;
}

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

      int B, N, M[1000];

      myfile >> B >> N;
      trace( "IN: %d %d\n", B, N );

      int next[1000];
      for( int j = 0; j < B; j++ ) { myfile >> M[j]; next[j] = 0; }

      int gcd = M[0], lcm = M[0];
      for( int j = 1; j < B; j++ ) { gcd = GCD(gcd, M[j]); lcm *= M[j] / gcd; }
      trace( "GCD = %d, LCM = %d\n", gcd, lcm );

      int speed = 0;
      for( int j = 0; j < B; j++ ) { speed += lcm / M[j]; }
      int cycles = N / speed;
      if( N % speed == 0 ) { cycles--; } // run assign code once

      trace( "Speed = %d, Cycles = %d\n", speed, cycles );

      for( int j = 0; j < B; j++ )
      {
         trace( "N = %d, M = %d\n", N, M[j] );
         N -= cycles * (lcm / M[j]);
      }
      trace( "N = %d\n", N );
      

      int res = 0;
      while( N > 0 )
      {
         int min = 1000000;
         for( int j = 0; j < B; j++ ) { if(next[j] < min){min = next[j];}}


         trace( "Min = %d\n", min );
         for( int j = 0; j < B; j++ )
         {
            next[j] -= min;
            if(next[j] == 0)
            {
               trace( "N = %d, j = %d\n", N, j );
               N--;
               if(N == 0){ res = j; }
               next[j] = M[j];
            }
         }
         
      }

      printf( "Case #%d: %d\n", i, res + 1 );
   }

   myfile.close();
   return 0;
}
