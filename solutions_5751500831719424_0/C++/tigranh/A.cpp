
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <climits>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair< string, vector< int > > string_num;

void numerize_string( const string& s, string_num& p )
{
	p.first.clear();
	p.second.clear();
	if ( s.empty() )
		return;
	p.first.push_back( s[ 0 ] );
	p.second.push_back( 1 );
	for ( int i = 1; i < (int)s.length(); ++i ) {
		if ( s[ i ] == s[ i - 1 ] )
			++p.second.back();
		else {
			p.first.push_back( s[ i ] );
			p.second.push_back( 1 );
		}
	}
}

int get_char_cnt_diff_to( const vector< int >& v, int m )
{
	int r = 0;
	for ( int i = 0; i < (int)v.size(); ++i )
		r += abs( m - v[ i ] );
	return r;
}

int get_char_cnt_diff( const vector< int >& v )
{
	int r = INT_MAX;
	int v_min = *min_element( v.begin(), v.end() );
	int v_max = *max_element( v.begin(), v.end() );
	for ( int m = v_min; m <= v_max; ++m ) {
		r = min( r, get_char_cnt_diff_to( v, m ) );
	}
	return r;
}

int solve( const vector< string >& sv )
{
	vector< string_num > sv_num;
	sv_num.resize( sv.size() );
	for ( int i = 0; i < (int)sv.size(); ++i )
		numerize_string( sv[ i ], sv_num[ i ] );
	for ( int i = 1; i < (int)sv_num.size(); ++i )
		if ( sv_num[ i ].first != sv_num[ 0 ].first )
			return -1;
	vector< int > sv_char_cnt;
	sv_char_cnt.resize( sv_num.size() );
	int r = 0;
	for ( int i = 0; i < (int)sv_num[ 0 ].second.size(); ++i ) {
		sv_char_cnt[ 0 ] = sv_num[ 0 ].second[ i ];
		for ( int j = 1; j < (int)sv_num.size(); ++j )
			sv_char_cnt[ j ] = sv_num[ j ].second[ i ];
		r += get_char_cnt_diff( sv_char_cnt );
	}
	return r;
}

int main()
{
	int T;
	cin >> T;
	for ( int t = 1; t <= T; ++t ) {
		int n;
		cin >> n;
		vector< string > sv;
		sv.resize( n );
		for ( int i = 0; i < n; ++i )
			cin >> sv[ i ];
		int s = solve( sv );
		cout << "Case #" << t << ": ";
		if ( s == -1 )
			cout << "Fegla Won";
		else
			cout << s;
		cout << endl;
	}
}
