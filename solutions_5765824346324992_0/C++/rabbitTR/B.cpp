#include <iostream>
#include <vector>
using namespace std;

long long int gcd( long long int p, long long int q ) {

  if ( q > p ) swap( p, q );

  while( q > 0 ) {

    p = p % q;
    swap( p, q );

  }

  return p;

}

long long int lcm( long long int p, long long int q ) {

  return p / gcd( p, q ) * q ;

}

int main() {

  long long int t;
  cin >> t;

  for ( long long int tt = 0; tt < t; tt++ ) {

    cout << "Case #" << tt+1 << ": ";

    long long int b, n;
    cin >> b >> n;

    vector< long long int > m;

    for ( long long int i = 0; i < b; i++ ) {

      long long int in;
      cin >> in;

      m.push_back( in );

    }

    long long int l = 1;

    for ( long long int i = 0; i < b; i++ ) {
      l = lcm( l, m[i] );
    }

    long long int c = 0;
    for ( long long int i = 0; i < b; i++ ) {
      c += l / m[i];
    }

    n = ( n - 1 ) % c + 1;

    long long int p[5] = {};

    while( true ) {
      long long int q = 30;
      bool f = true;
      for ( long long int i = 0; i < b; i++ ) {
	if ( p[i] == 0 ) {
	  n--;
	  if ( n == 0 ) {
	    cout << i+1 << endl;
	    break;
	  }
	  p[i] = m[i];
	  f = false;
	  break;
	}
	q = min( q, p[i] );
      }
      if ( n == 0 ) break;
      if ( f == false ) continue;
      for ( long long int i = 0; i < b; i++ ) {
	p[i] -= q;
      }
    }

  }

  return 0;

}
