#include <fstream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;
typedef long long LL;
typedef pair< LL, LL > PII;
const double Pi = 3.1415926535897932384;
const double eps = 1E-8;
const int N = 3005;

#define fo( i, x, y ) for ( int i=x; i<y; ++i )
#define mkp( A, B ) make_pair( A, B )
#define pb( x ) push_back( x )
#define _x first
#define _y second

double Rad[N];
int Ans[N];
int n, Res;
vector < PII > v;
PII a[N];

void preprocessing()
{
	cin >> n;
	fo ( i, 0, n ) cin >> a[i]._x >> a[i]._y;
}

bool cmp( PII A, PII B )
{
	return atan2( A._y, A._x ) < atan2( B._y, B._x );
}

PII vec( PII A, PII B ) { return mkp( A._x - B._x, A._y - B._y ); }

LL cross( PII A, PII B ) { return A._x*B._y - A._y*B._x; }

int Do( int x )
{
	int m = n - 1;
	if ( !m ) return 0;
	fo ( i, 0, N ) Rad[i] = 0;
	v.clear();
	fo ( i, 0, n ) if ( i!=x ) 
		v.pb( vec( a[i], a[x] ) );
	sort( v.begin(), v.end(), cmp );
	//fo ( i, 0, m ) Rad[i] = atan2( v[i]._x, v[i]._y );
	int tl = 1, Res = N;
	fo ( i, 0, m ) v.pb( v[i] );
	//fo ( i, 0, m ) Rad[ i+m ] = Rad[i] + Pi + Pi;
	fo ( i, 0, m ) 
	{
		while ( tl==i || cross( v[i], v[ tl ] )>0 ) ++tl;
		Res = min( Res, tl - i );
	}
	return Res - 1;
}

void solve( int Case )
{
	fo ( i, 0, n ) Ans[i] = Do( i );
	cout << "Case #" << ( Case + 1 ) << ":" << endl;
	fo ( i, 0, n ) cout << Ans[i] << endl;
}

int main()
{
	freopen( "0", "r", stdin );
	ios :: sync_with_stdio( 0 );
	int T = 0; cin >> T;
	fo ( Case, 0, T )
	{
		preprocessing();
		solve( Case );
	}
	return 0;
}

