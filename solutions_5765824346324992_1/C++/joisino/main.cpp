#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;

template<typename T>T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T>T chmax( T &a , T b ){ return a = max( a , b ); }

ll n , b;

ll a[1024];

ll po( ll t ){
  ll res = 0;
  for( int i = 0; i < b; i++ )
    res += (t/a[i])+1;
  return res;
}

int main(){
    
  int t;
  scanf( "%d" , &t );

  for( int cnt = 1; cnt <= t; cnt++ ){
    scanf( "%lld %lld" , &b , &n );

    for( int i = 0; i < b; i++ )
      scanf( "%lld" , &a[i] );

    ll lb = -1 , ub = ll(n)*100010;
    while( ub-lb > 1 ){
      ll md = (lb+ub)/2;
      if( po( md ) >= n ) ub = md;
      else lb = md;
    }
    
    ll st = n - po(ub-1);

    //printf( "%lld %lld %lld %lld\n" , ub , po(ub-1) , po(ub) , st );
    for( int i = 0; i < b; i++ ){
      if( ub%a[i] == 0 ) st--;
      if( st == 0 ){
	printf( "Case #%d: %d\n" , cnt , i+1 );
	break;
      }
    }
  }
  
  return 0;
}
