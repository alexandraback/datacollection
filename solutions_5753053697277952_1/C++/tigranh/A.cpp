/*
 * A.cpp
 *
 *  Created on: May 8, 2016
 *      Author: tigran
 */




#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
#include <functional>
#include <iterator>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

typedef pair< int, char > p_type;

void solve( vector< int > p )
{
	set< p_type > s;
	for ( int i = 0; i < (int)p.size(); ++i )
		s.insert( p_type( p[ i ], 'A' + i ) );
	while ( s.size() > 2 ) {
		auto s_it = --s.end();
		p_type curr_p = *s_it;
		cout << " " << s_it->second;
		s.erase( s_it );
		--curr_p.first;
		if ( curr_p.first > 0 )
			s.insert( curr_p );
	}
	assert( s.size() == 2 );
	assert( s.begin()->first == (++s.begin())->first );
	while ( s.begin()->first > 0 ) {
		auto curr_p1 = *(s.begin()), curr_p2 = *(++s.begin());
		cout << " " << curr_p1.second << curr_p2.second;
		--curr_p1.first;
		--curr_p2.first;
		s.clear();
		s.insert( curr_p1 );
		s.insert( curr_p2 );
	}
}

int main()
{
	int TC;
	cin >> TC;
	for ( int tc = 1; tc <= TC; ++tc ) {
		int n;
		cin >> n;
		vector< int > p;
		for ( int i = 0; i < n; ++i ) {
			int value;
			cin >> value;
			p.push_back( value );
		}
		cout << "Case #" << tc << ":";
		solve( p );
		cout << endl;
	}
	return 0;
}
