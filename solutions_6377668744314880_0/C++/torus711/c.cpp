#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <cmath>
#include <cassert>
#include <cstdio>

using namespace std; using namespace placeholders;

using LL = long long;
using ULL = unsigned long long;
using VI = vector< int >;
using VVI = vector< vector< int > >;
using VS = vector< string >;
using SS = stringstream;
using PII = pair< int, int >;
using VPII = vector< pair< int, int > >;
template < typename T = int > using VT = vector< T >;
template < typename T = int > using VVT = vector< vector< T > >;
template < typename T = int > using LIM = numeric_limits< T >;

template < typename T > inline istream& operator>>( istream &s, vector< T > &v ){ for ( T &t : v ) { s >> t; } return s; }
template < typename T > inline ostream& operator<<( ostream &s, const vector< T > &v ){ for ( int i = 0; i < int( v.size() ); ++i ){ s << ( " " + !i ) << v[i]; } return s; }
template < typename T > inline T fromString( const string &s ) { T res; istringstream iss( s ); iss >> res; return res; };
template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };

#define REP2( i, n ) REP3( i, 0, n )
#define REP3( i, m, n ) for ( int i = ( int )( m ); i < ( int )( n ); ++i )
#define GET_REP( a, b, c, F, ... ) F
#define REP( ... ) GET_REP( __VA_ARGS__, REP3, REP2 )( __VA_ARGS__ )
#define FOR( e, c ) for ( auto &e : c )
#define ALL( c ) ( c ).begin(), ( c ).end()
#define AALL( a, t ) ( t* )a, ( t* )a + sizeof( a ) / sizeof( t )
#define DRANGE( c, p ) ( c ).begin(), ( c ).begin() + p, ( c ).end()

#define SZ( v ) ( (int)( v ).size() )
#define PB push_back
#define EM emplace
#define EB emplace_back
#define BI back_inserter

#define EXIST( c, e ) ( ( c ).find( e ) != ( c ).end() )

#define MP make_pair
#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

#include <complex>
using Point =  complex< double >;
constexpr double EPS = 1e-8;
constexpr double PI = acos( -1 );
constexpr Point O( 0, 0 );

// 入力ストリームから実数二つをとって Point へ
istream& operator>> ( istream &s, Point &a )
{
	double r, i;
	s >> r >> i;
	a = Point( r, i );
	return s;
}

// 内積（ドット積）
double dot( const Point &a, const Point &b )
{
	return a.real() * b.real() + a.imag() * b.imag();
}

// 外積（クロス積）
double cross( const Point &a, const Point &b )
{
	return a.real() * b.imag() - a.imag() * b.real();
}

// a == b
bool eq( const double a, const double b )
{
	return abs( a - b ) <= EPS;
}

// x 座標優先
// include : eq
struct CompX : public binary_function<Point,Point,bool>
{
	bool operator ()( const Point &a, const Point &b ) const
	{
		return eq( a.real(), b.real() ) ? a.imag() < b.imag() : a.real() < b.real();
	}
};

// 点集合 ps の凸包（ Graham Scan ）
// include : cross, CompX
vector<Point> convex_hull( vector<Point> ps )
{
	const int N = ps.size();

	sort( ps.begin(), ps.end(), CompX() );

	int k = 0;
	vector<Point> convex( N * 2 );

	for ( int i = 0; i < N; i++ )
	{
		while ( 2 <= k && cross( convex[ k - 1 ] - convex[ k - 2 ], ps[i] - convex[ k - 1 ] ) <= EPS )
		{
			k--;
		}
		convex[ k++ ] = ps[i];
	}

	for ( int i = N - 2, t = k; 0 <= i; i-- )
	{
		while ( t < k && cross( convex[ k - 1 ] - convex[ k - 2 ], ps[i] - convex[ k - 1 ] ) <= EPS )
		{
			k--;
		}
		convex[ k++ ] = ps[i];
	}

	convex.resize( k - 1 );
	return convex;
}

// 点 p と直線 ( q1, q2 ) の距離
// include : cross
double distancePL( const Point &p, const Point &q1, const Point &q2 )
{
	return abs( cross( q2 - q1, p - q1 ) ) / abs( ( q2 - q1 ) );
}

// 点 p と線分 ( q1, q2 ) の距離
// include : dot, distancePL
double distancePS( const Point p, const Point &q1, const Point &q2 )
{
	if ( EPS < dot( q2 - q1, p - q1 ) && EPS < dot( q1 - q2, p - q2 ) ) // 垂線が交わる
	{
		return distancePL( p, q1, q2 );
	}
	else
	{
		return min( abs( q1 - p ), abs( q2 - p ) );
	}
}

void solve()
{
	int N;
	cin >> N;

	VT< Point > ps( N );
	cin >> ps;

	VI res( N, N - 1 );
	REP( s, 1, 1 << N )
	{
		VT< Point > qs;
		REP( i, N )
		{
			if ( s & 1 << i )
			{
				qs.PB( ps[i] );
			}
		}

		VT< Point > convex = convex_hull( qs );
		convex.PB( convex[0] );

		REP( i, N )
		{
			if ( !( s & 1 << i ) )
			{
				continue;
			}

			REP( j, SZ( convex ) - 1 )
			{
				if ( eq( 0, distancePS( ps[i], convex[j], convex[ j + 1 ] ) ) )
				{
					res[i] = min( res[i], N - __builtin_popcount( s ) );
				}
			}
		}
	}

	copy( ALL( res ), ostream_iterator< int >( cout, "\n" ) );
	cout << flush;

	return;
}

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	int T;
	cin >> T;
	REP( i, T )
	{
		cout << "Case #" << i + 1 << ':' << endl;
		solve();
	}

	return 0;
}
