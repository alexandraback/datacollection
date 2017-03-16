#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <algorithm>

using namespace std;

int sum( vector<int> &vs ) {
  int sum = 0;
  for ( auto v : vs ) {
	sum += v;
  }
  return sum;
}

int argmax( vector<int> &vs ) {
  int max_index = 0;
  int max_value = vs[ 0 ];
  for ( int i = 1; i < vs.size(); i++ ) {
	if ( max_value < vs[ i ] ) {
	  max_value = vs[ i ];
	  max_index = i;
	}
  }
  return max_index;
}

void select( vector<int> &vs )
{
  int i1 = argmax( vs );
  vs[ i1 ]--;
  cout << static_cast<char>( 'A' + i1 );
  
  int i2 = argmax( vs );
  if ( vs[ i2 ] * 2 > sum( vs ) )
  {
	vs[ i2 ]--;
	cout << static_cast<char>( 'A' + i2 );
  }
}

int main()
{
  int T;
  cin >> T;
  for ( int t = 1; t <= T; t++ )
  {
	int n;
	cin >> n;
	vector<int> vs( n );
	for ( int i = 0; i < n; i++ ) {
	  cin >> vs[ i ];
	}

	cout << "Case #" << t << ":";
	while ( count( vs.begin(), vs.end(), 0 ) < n )
	{
	  cout << " ";
	  select( vs );
	}
	cout << endl;
  }
}
