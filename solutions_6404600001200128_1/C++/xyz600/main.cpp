#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve1( vector<int> &vs ) {
  int sum = 0;
  for ( int i = 1; i < vs.size(); i++ ) {
	if ( vs[ i - 1 ] > vs[ i ] ) {
	  sum += vs[ i - 1 ] - vs[ i ];
	}
  }
  return sum;
}

int simulate( int rate, vector<int> &vs ) {
  int sum = 0;
  for ( int i = 1; i < vs.size(); i++ ) {
	if ( vs[ i - 1 ] - rate > vs[ i ] ) {
	  return -1;
	} else {
	  if ( vs[ i - 1 ] < rate ) {
		sum += vs[ i - 1 ];
	  } else {
		sum += rate;
	  }
	}
  }
  return sum;
}

int solve2( vector<int> &vs ) {
  int max_value = 0;
  for ( int v : vs ) {
	max_value = max( max_value, v ) ;
  }

  int min_eaten = 1000000000;
  // i: constant rate
  for ( int i = 0; i <= max_value; i++ ) {
	int sub_ans = simulate( i, vs );
	if ( sub_ans >= 0 ) {
	  min_eaten = min( min_eaten, sub_ans );
	}
  }
  return min_eaten;
}

int main()
{
  int T;
  cin >> T;
  for ( int t = 1; t <= T; t++ )
  {
	int n;
	cin >> n;
	vector<int> vs;
	for ( int i = 0; i < n; i++ ) {
	  int v;
	  cin >> v;
	  vs.push_back( v );
	}
	printf( "Case #%d: %d %d\n", t, solve1( vs ), solve2( vs ) );
  }
}
