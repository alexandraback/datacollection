/*
 * main.cpp
 *
 *  Created on: 02 ???, 2015 ?.
 *      Author: Tigran
 */



#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

void fill_row( int x, std::vector< bool >& row )
{
	std::fill( row.begin(), row.end(), 0 );
	int p = 0;
	while ( x > 0 ) {
		row[ p++ ] = x % 2;
		x /= 2;
	}
}

void fill_matrix( const std::vector< bool >& row,
		std::vector< std::vector< bool > >& m )
{
	int r = m.size();
	int c = m.front().size();
	for ( int i = 0; i < r; ++i )
		for ( int j = 0; j < c; ++j )
			m[ i ][ j ] = row[ i * c + j ];
}

int calc_unhappiness( const std::vector< std::vector< bool > >& m )
{
	int r = m.size();
	int c = m.front().size();
	int res = 0;
	for ( int i = 0; i < r; ++i )
		for ( int j = 1; j < c; ++j )
			if ( m[ i ][ j - 1 ] && m[ i ][ j ] )
				++res;
	for ( int i = 1; i < r; ++i )
		for ( int j = 0; j < c; ++j )
			if ( m[ i - 1 ][ j ] && m[ i ][ j ] )
				++res;
	return res;
}

void print_matrix( const std::vector< std::vector< bool > >& m )
{
	int r = m.size();
	int c = m.front().size();
	for ( int i = 0; i < r; ++i ) {
		for ( int j = 0; j < c; ++j )
			cout << (m[ i ][ j ] ? "1" : "0");
		cout << endl;
	}
}
int solve( int r, int c, int n )
{
	std::vector< std::vector< bool > > m;
	m.resize( r, std::vector< bool >( c ) );

	std::vector< bool > m_row( r * c );

	int res = 1000000000;
	for ( int x = 0; x < (1 << (r*c)); ++x ) {
		fill_row( x, m_row );
		if ( std::count( m_row.begin(), m_row.end(), true ) != n )
			continue;
		//if ( std::accumulate( m_row.begin(), m_row.end(), int( 0 ) ) != n )
		//	continue;
		fill_matrix( m_row, m );
		int new_val = calc_unhappiness( m );
		if ( new_val < res ) {
			res = new_val;
			//print_matrix( m );
			//cout << x << " " << res << endl;
		}
	}
	return res;
}

int main()
{
	int TC;
	cin >> TC;
	for ( int tc = 1; tc <= TC; ++tc ) {
		int r, c, n;
		cin >> r >> c >> n;
		cout << "Case #" << tc << ": " << solve( r, c, n ) << endl;
	}
	return 0;
}
