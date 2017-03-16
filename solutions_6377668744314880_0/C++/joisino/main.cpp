#include "bits/stdc++.h"

using namespace std;

typedef long long int ll;
typedef pair<ll,ll> P;

template<typename T>T chmin( T &a , T b ){ return a = min( a , b ); }
template<typename T>T chmax( T &a , T b ){ return a = max( a , b ); }

ll cross( P a , P b ){
  return a.first*b.second-a.second*b.first;
}

ll dot( P a , P b ){
  return a.first*b.first+a.second*b.second;
}
ll norm( P a ){
  return a.first*a.first+a.second*a.second;
}

int ccw( P a , P b , P c ){
  b = P( b.first - a.first , b.second - a.second );
  c = P( c.first - a.first , c.second - a.second );
  if( cross(b,c) > 0 ) return 1;
  if( cross(b,c) < 0 ) return -1;
  if( dot(b,c) < 0 ) return 2;
  if( norm(b) < norm(c) ) return -2;
  return 0;
}

vector<P> convex_hull( vector<P> ps ){
  int n = ps.size();
  int k = 0;

  if( n <= 2 ) return ps;

  sort( ps.begin() , ps.end() );
  vector<P> ch(2*n);
  for( int i = 0; i < n; ch[k++] = ps[i++] )
    while( k >= 2 && ccw(ch[k-2],ch[k-1],ps[i]) == -1 ) k--;
  for( int i = n-2,t = k+1; i >= 0; ch[k++] = ps[i--] )
    while( k >= t && ccw(ch[k-2],ch[k-1],ps[i]) == -1 ) k--;

  ch.resize(k-1);

  return ch;
}

int n;
vector<P> ps;
vector<P> cp;

int main(){

  int t;
  scanf( "%d" , &t );


  for( int cnt = 1; cnt <= t; cnt++ ){
    scanf( "%d" , &n );

    ps.clear();
    for( int i = 0; i < n; i++ ){
      ll x , y;
      scanf( "%lld %lld" , &x , &y );
      ps.push_back( P( x , y ) );
    }

    printf( "Case #%d:\n" , cnt );
    for( int i = 0; i < n; i++ ){
      int ans = n;
      for( int j = 0; j < (1<<n); j++ ){
	cp.clear();
	for( int k = 0; k < n; k++ )
	  if( j&(1<<k) )
	    cp.push_back( ps[k] );

	vector<P> res = convex_hull( cp );

	for( int j = 0; j < res.size(); j++ )
	  if( res[j] == ps[i] ) chmin( ans , n-int(cp.size()) );
      }
      printf( "%d\n" , ans );
    }
  }

  return 0;
}
