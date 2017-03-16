#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
typedef long long ll;

#define MAX_B 1050
#define MAX_N 100000005LL
#define MAX_M 100005LL
ll M[MAX_N];


int main()
{
  int T;
  scanf( "%d", &T );
  
  for ( int i = 0; i < T; i++ ) {
    int B, N;
    int ans = 0;
    ll min_t = 1;
    ll max_t = MAX_N * MAX_M;
    
    scanf( "%d %d\n", &B, &N );

    for ( int j = 0; j < B; j++ ) {
      scanf( "%lld\n", &M[j] );
    }

    // 最初の一巡で終了
    if ( N <= B ) {
      printf( "Case #%d: %d\n", (i+1), N );
      continue;
    }
    while ( max_t > min_t ) {
      ll mid = ( min_t + max_t ) / 2;
      //      printf("mid = %lld\n", mid);
      ll num = B;

      for ( int j = 0; j < B; j++ ) {
        num += (mid / M[j]);
        //        printf("j = %d, mid = %lld, M[j] = %lld, add = %lld, num = %lld\n", j, mid, M[j], (mid / M[j]), num);
      }

      if ( num < N ) {
        min_t = mid + 1;
      } else {
        max_t = mid;
      }
    }

    int started = B;
    if ( ( max_t - 1 ) > 0 ) {
      for ( int j = 0; j < B; j++ ) {
        started += ( ( max_t - 1) / M[j] );
      }
    }
    //    printf("t-1 = %lld, started = %d\n", (max_t-1), started);
    for ( int j = 0; j < B; j++ ) {
      if ( max_t % M[j] == 0 ) {
        started++;
        if ( started == N ) {
          ans = j + 1;
          break;
        }
      }
    }
    
    printf( "Case #%d: %d\n", (i+1), ans );
  }
}
