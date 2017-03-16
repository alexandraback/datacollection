#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long f( vector<long> &vs, long time ) {
  long ans = 0L;
  for ( long v : vs ) {
	ans += time / v + 1;
  }
  return ans;
}

int main()
{
  int T;
  cin >> T;
  for ( int t = 1; t <= T; t++ )
  {
	int b, n;
	cin >> b >> n;
	vector<long> ms;
	for ( int i = 0; i < b; i++ ) {
	  long v;
	  cin >> v;
	  ms.push_back( v );
	}
	
	long left = 0;
	long right = 1000000000l * 1000000l;
	for ( int i = 0; i < 64; i++ ) {
	  const long middle = ( left + right ) / 2;
	  if ( f( ms, middle ) >= n ) {
		right = middle;
	  } else {
		left = middle;
	  }
	}
	while ( f( ms, right ) >= n ) {
	  right--;
	}
	while ( f( ms, right ) < n ) {
	  right++;	  
	}
	
	long cust = f( ms, right - 1 );
	for ( int i = 0; i < b; i++ ) {
	  if ( right % ms[ i ] == 0 ) {
		cust++;
		if ( cust == n ) {
		  printf( "Case #%d: %d\n", t, i + 1 );
		  break;
		}
	  }
	}
  }
}
