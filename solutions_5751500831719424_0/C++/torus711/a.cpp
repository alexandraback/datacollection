#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <iterator>
#include <limits>
#include <numeric>
#include <utility>
#include <cmath>

using namespace std; using namespace placeholders;

using LL = long long;
using ULL = unsigned long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using SS = stringstream;
using PII = pair<int,int>;
using VPII = vector< pair<int,int> >;
template < typename T = int > using VT = vector<T>;
template < typename T = int > using VVT = VT< VT<T> >;
template < typename T = int > using LIM = numeric_limits<T>;

template < typename T > inline T fromString( const string &s ){ T res; istringstream iss( s ); iss >> res; return res; };
template < typename T > inline string toString( const T &a ){ ostringstream oss; oss << a; return oss.str(); };

#define REP( i, m, n ) for ( int i = (int)( m ); i < (int)( n ); ++i )
#define FOR( e, c ) for ( auto &e : c )
#define ALL( c ) (c).begin(), (c).end()
#define AALL( a, t ) (t*)a, (t*)a + sizeof( a ) / sizeof( t )
#define DRANGE( c, p ) (c).begin(), (c).begin() + p, (c).end()

#define PB( n ) push_back( n )
#define MP( a, b ) make_pair( ( a ), ( b ) )
#define EXIST( c, e ) ( (c).find( e ) != (c).end() )

#define fst first
#define snd second

#define DUMP( x ) cerr << #x << " = " << ( x ) << endl

bool possible( VS ss )
{
	FOR( s, ss )
	{
		s.erase( unique( ALL( s ) ), s.end() );
	}

	return set<string>( ALL( ss ) ).size() == 1u;
}

VI convert( const string &s )
{
	const int L = s.size();

	VI res;
	REP( i, 0, L )
	{
		int j;
		for ( j = i; j < L && s[i] == s[j]; ++j );
		res.PB( j - i );
		i = j - 1;
	}

	return res;
}

int solve()
{
	int n;
	cin >> n;

	VS ss( n );
	FOR( s, ss )
	{
		cin >> s;
	}

	if ( !possible( ss ) )
	{
		return -1;
	}

	VVI nums( n );
	REP( i, 0, n )
	{
		nums[i] = convert( ss[i] );
	}

	int res = 0;
	REP( i, 0, nums[0].size() )
	{
		VI cnts( n );
		REP( j, 0, n )
		{
			cnts[j] = nums[j][i];
		}

		sort( ALL( cnts ) );

		int minimal = LIM<>::max();
		REP( t, cnts[0], cnts.back() + 1 )
		{
			int tmp = 0;
			FOR( c, cnts )
			{
				tmp += abs( c - t );
			}
			minimal = min( minimal, tmp );
		}

		res += minimal;
	}

	return res;
}

int main()
{
	cin.tie( 0 );
	ios::sync_with_stdio( false );

	int t;
	cin >> t;

	REP( i, 0, t )
	{
		const int res = solve();

		cout << "Case #" << i + 1 << ": " << ( res == -1 ? "Fegla Won" : toString( res ) ) << endl;
	}

	return 0;
}
