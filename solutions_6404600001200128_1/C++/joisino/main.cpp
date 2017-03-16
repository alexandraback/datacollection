#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;

template<typename T>T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T>T chmax( T &a , T b ){ return a = max( a , b ); }

int a[10010];

int main(){

  int t;
  scanf( "%d" , &t );

  for( int cnt = 1; cnt <= t; cnt++ ){
    int n;
    scanf( "%d" , &n );

    for( int i = 0; i < n; i++ )
      scanf( "%d" , &a[i] );

    printf( "Case #%d: " , cnt );
    
    int ans = 0;
    for( int i = 0; i < n-1; i++ )
      ans += max(0,a[i]-a[i+1] );

    printf( "%d " , ans );

    ans = 0;
    int r = 0;
    for( int i = 0; i < n-1; i++ )
      chmax( r , a[i]-a[i+1] );

    for( int i = 0; i < n-1; i++ )
      ans += min( r , a[i] );

    printf( "%d\n" , ans );
  }
  
  return 0;
}
