#include <iostream>
#include <vector>
using namespace std;

int main() {

  long long int t;
  cin >> t;

  for ( long long int tt = 0; tt < t; tt++ ) {

    cout << "Case #" << tt+1 << ":" << endl;

    long long int n;
    cin >> n;

    vector< long long int > x, y;

    for ( long long int i = 0; i < n; i++ ) {

      long long int in_x, in_y;
      cin >> in_x >> in_y;

      x.push_back( in_x );
      y.push_back( in_y );

    }

    if ( n == 1 ) {
      cout << 0 << endl;
      continue;
    }

    for ( long long int i = 0; i < n; i++ ) {

      long long int ans = n;

      for ( long long int bit = 0; bit < ( 1 << n ); bit++ ) {

	long long int i_bit = ( 1 << i );
	if ( ( bit & i_bit ) == 0 ) continue;

	for ( long long int j = 0; j < n; j++ ) {

	  if ( i == j ) continue;
	  long long int j_bit = ( 1 << j );
	  if ( ( bit & j_bit ) == 0 ) continue;

	  long long int flag = 0;

	  for ( long long int k = 0; k < n; k++ ) {

	    if ( k == i ) continue;
	    if ( k == j ) continue;
	    long long int k_bit = ( 1 << k );
	    if ( ( bit & k_bit ) == 0 ) continue;

	    long long int h = ( x[j] - x[i] ) * ( y[k] - y[i] ) - ( y[j] - y[i] ) * ( x[k] - x[i] );
	    if ( h == 0 ) continue;
	    if ( h > 0 ) {
	      if ( flag == 2 ) {
		flag = -1;
		break;
	      }
	      flag = 1;
	    }else {
	      if ( flag == 1 ) {
		flag = -1;
		break;
	      }
	      flag = 2;
	    }

	  }

	  if ( flag >= 0 ) {

	    long long int b = bit;
	    long long int cnt = 0;
	    while( b > 0 ) {
	      cnt += ( b % 2 );
	      b /= 2;
	    }
	    ans = min( n - cnt, ans );

	  }

	}

      }

      cout << ans << endl;

    }

  }

  return 0;

}
