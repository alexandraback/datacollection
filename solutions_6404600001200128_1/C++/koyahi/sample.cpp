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

    for ( int j = 1; j < N; j++ ) {
      ans2 += min( max_diff, m[j - 1] );
    }

    printf( "Case #%d: %d %d\n", (i+1), ans1, ans2 );
  }
}
