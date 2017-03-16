#include <fstream>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = ( int ) 1E3 + 5;
const LL Inf = ( LL ) 1E15;

#define fo( i, x, y ) for ( int i=x; i<y; ++i )

int n, m;
int v[N], R[N];

void preprocessing()
{
	cin >> m >> n;
	fo ( i, 0, m ) cin >> v[i];
}

LL Chk( LL Ti )
{
	LL Res = 0;
	fo ( i, 0, m ) 
	{
		Res += Ti / v[i] + 1;
		R[i] = v[i] - Ti % v[i];
	}
	return Res;
}

void solve( int Case )
{
	LL l = 0, r = Inf, Res = 0;
	for ( LL mid=( l+r )>>1; l<r-1; mid=( l+r )>>1 )
		if ( Chk( mid ) >= n-1 ) r = mid;
		else l = mid;
	if ( Chk( l ) < n - 1 )n -= Chk( l );
	while ( n )
	{
		int Num = 0;
		fo ( i, 0, m ) if ( R[i] < R[Num] ) Num = i;
		int Ti = R[Num];
		fo ( i, 0, m ) R[i] -= Ti;
		fo ( i, 0, m ) if ( !R[i] )
		{
			R[i] = v[i];
			if ( !( --n ) ) 
			{
				Res = i + 1;
				break;
			}
		}
 	}
	cout << "Case #" << ( Case + 1 ) << ": " << Res << endl;
}

int main()
{
	freopen( "0", "r", stdin );
	ios :: sync_with_stdio( 0 );
	int T; cin >> T;
	fo ( Case, 0, T )
	{
		preprocessing();
		solve( Case );
	}
	return 0;	
}

