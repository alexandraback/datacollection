#include <iostream>
using namespace std;
const int N = 1005;

#define fo( i, x, y ) for ( int i=x; i<y; ++i )

int a[N];
int n, m;

int main()
{
	ios :: sync_with_stdio( 0 );
	int T; cin >> T;
	fo ( Case, 0, T )
	{
		cin >> n;
		fo ( i, 0, n ) cin >> a[i];
		int S1 = 0, S2 = 0, S3 = 0;
		fo ( i, 0, n - 1 ) 
			if ( a[i] > a[ i+1 ] )
				S1 += a[i] - a[ i+1 ], S2 = max( S2, a[i] - a[ i+1 ] );
		fo ( i, 0, n - 1 ) S3 += min( S2, a[i] );
		cout << "Case #" << ( Case+1 ) << ": " << S1 << " " << S3 << endl;
	}
}

