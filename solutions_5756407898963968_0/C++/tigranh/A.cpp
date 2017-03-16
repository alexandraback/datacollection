
#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

void input_matrix( int m[][ 4 ] )
{
	for ( int i = 0; i < 4; ++i )
		for ( int j = 0; j < 4; ++j )
			cin >> m[ i ][ j ];
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t ) {
		int a, b;
		int A[ 4 ][ 4 ], B[ 4 ][ 4 ];
		cin >> a;
		--a;
		input_matrix( A );
		cin >> b;
		--b;
		input_matrix( B );
		sort( A[ a ], A[ a ] + 4 );
		sort( B[ b ], B[ b ] + 4 );
		vector< int > c;
		set_intersection( A[ a ], A[ a ] + 4, B[ b ], B[ b ] + 4, back_inserter( c ) );
		cout << "Case #" << t << ": ";
		if ( c.empty() )
			cout << "Volunteer cheated!";
		else if ( c.size() == 1 )
			cout << c[ 0 ];
		else
			cout << "Bad magician!";
		cout << endl;
	}
	return 0;
}
