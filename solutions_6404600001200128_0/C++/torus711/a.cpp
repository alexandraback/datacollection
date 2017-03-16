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

int solve1( const int N, const VI &as )
{
	int res = 0;
	REP( i, N - 1 )
	{
		res += max( 0, as[i] - as[ i + 1 ] );
	}
	return res;
}

int solve2( const int N, const VI &as )
{
	int rate = 0;
	REP( i, N - 1 )
	{
		rate = max( rate, as[i] - as[ i + 1 ] );
	}

	int res = 0;
	REP( i, N - 1 )
	{
		res += min( rate, as[i] );
	}
	return res;
}

void solve()
{
	int N;
	cin >> N;

	VI as( N );
	cin >> as;

	cout << solve1( N, as ) << ' ' << solve2( N, as ) << endl;

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
		cout << "Case #" << i + 1 << ": ";
		solve();
	}

	return 0;
}
