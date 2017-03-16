#include <cassert>
#include <string>
#include <sstream>
#include <iostream>
#include <deque>
#include <cctype>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <cstring>

using namespace std;

typedef pair<int,int> PI;
int m[10004][10004];
int iter = 0;

int calc1( int rows, int cols, int N ) {
	++iter;

	int cnt = 0;
	for( int r = 0; r < rows; ++r ) {
		for( int c = 0; c < cols; ++c ) {
			if( (r+c)%2 == 0 ) {
				m[r][c] = iter;
				++cnt;
			}
		}
	}
	if( cnt >= N ) return 0;

	int cnt2[5] = {0,0,0,0,0};

	for( int r = 0; r < rows; ++r ) {
		for( int c = 0; c < cols; ++c ) {
			if( m[r][c] == iter ) continue;
			int unhappy = 0;
			if( c < cols-1 ) ++unhappy;
			if( c > 0 ) ++unhappy;
			if( r < rows-1 ) ++unhappy;
			if( r > 0 ) ++unhappy;
			++cnt2[unhappy];
		}
	}

	int x = N-cnt;
	int res = 0;
	assert( cnt2[0] == 0 );
	for( int i = 1; i <= 4; ++i ) {
		int take = min( cnt2[i], x );
		res += take * i;
		x -= take;
	}
	assert( x == 0 );
	return res;
}

int calc2( int rows, int cols, int N ) {
	++iter;

	int cnt = 0;
	for( int r = 0; r < rows; ++r ) {
		for( int c = 0; c < cols; ++c ) {
			if( (r+c)%2 == 1 ) {
				m[r][c] = iter;
				++cnt;
			}
		}
	}
	if( cnt >= N ) return 0;

	int cnt2[5] = {0,0,0,0,0};

	for( int r = 0; r < rows; ++r ) {
		for( int c = 0; c < cols; ++c ) {
			if( m[r][c] == iter ) continue;
			int unhappy = 0;
			if( c < cols-1 ) ++unhappy;
			if( c > 0 ) ++unhappy;
			if( r < rows-1 ) ++unhappy;
			if( r > 0 ) ++unhappy;
			++cnt2[unhappy];
		}
	}

	int x = N-cnt;
	int res = 0;
	assert( cnt2[0] == 0 );
	for( int i = 1; i <= 4; ++i ) {
		int take = min( cnt2[i], x );
		res += take * i;
		x -= take;
	}
	assert( x == 0 );
	return res;
}

int main() {
	int cases;

	cin >> cases;

	for( int caseno = 1; caseno <= cases; ++caseno ) {
		cout << "Case #" << caseno << ": ";
		int rows, cols, N;
		cin >> rows >> cols >> N;

		if( N <= 1 ) {
			cout << 0 << endl;
			continue;
		}

		int x[4];
		x[0] = calc1( rows, cols, N );
		x[1] = calc1( cols, rows, N );
		x[2] = calc2( rows, cols, N );
		x[3] = calc2( cols, rows, N );
		int res = 1000000000;
		for( int i = 0; i < 4; ++i ) {
			//cerr << x[i] << ' ';
			res = min( res, x[i] );
		}
		//cerr << endl;
		cout << res << endl;
	}
	return 0;
}

