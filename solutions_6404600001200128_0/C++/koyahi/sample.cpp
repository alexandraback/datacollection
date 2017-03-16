#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define MAX_N 1050
#define MAX_M 10050
int m[MAX_N];

int main()
{
  int T;
  scanf( "%d", &T );
  
  for ( int i = 0; i < T; i++ ) {
    int ans1 = 0;
    int ans2 = 0;
      
    int N;
    scanf( "%d\n", &N );

    for ( int j = 0; j < N; j++ ) {
      scanf( "%d\n", &m[j] );
    }

    int max_diff = 0;
    for ( int j = 1; j < N; j++ ) {
      if ( m[j] < m[j - 1] ) {
        ans1 += ( m[j - 1] - m[j] );
      }
      max_diff = max( max_diff, m[j - 1] - m[j] );
    }

    int min_ans = 0;
    int max_ans = MAX_M;
    while ( max_ans != min_ans ) {
      int mid = ( max_ans + min_ans ) >> 1;
      bool check = true;
      for ( int j = 1; j < N; j++ ) {
        int must = max( m[j - 1] - m[j], 0 );
        int enable = 10 * mid;
        if ( must > enable ) {
          check = false;
          break;
        }
      }

      if ( check ) {
        max_ans = mid;
      } else {
        min_ans = mid + 1;
      }
    }

    //    for ( int j = 1; j < N; j++ ) {
    //      ans2 += min( 10 * max_ans, m[j - 1] );
    //    }

    for ( int j = 1; j < N; j++ ) {
      ans2 += min( max_diff, m[j - 1] );
    }
    printf( "Case #%d: %d %d\n", (i+1), ans1, ans2 );
  }
}
