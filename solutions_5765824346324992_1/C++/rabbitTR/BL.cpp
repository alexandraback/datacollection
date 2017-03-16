#include <iostream>
#include <vector>
using namespace std;

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

    long long int lo = 0;
    long long int hi = 100000000000000;

    while( lo < hi ) {

      long long int k = ( lo + hi ) / 2;
      long long int cnt = 0;
      for ( long long int i = 0; i < b; i++ ) {
	cnt += k / m[i];
	if ( ( k % m[i] ) != 0 ) cnt++;
      }
      if ( cnt > n - 1 ) {
	hi = k;
      }else if ( cnt < n - 10000 ) {
	lo = k;
      }else {
	lo = k;
	n -= cnt;
	break;
      }

    }

    long long int p[1001] = {};
    for ( long long int i = 0; i < b; i++ ) {
      p[i] = ( lo % m[i] );
      if ( p[i] > 0 ) p[i] = m[i] - p[i];
    }

    while( true ) {
      long long int q = 1000000;
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
