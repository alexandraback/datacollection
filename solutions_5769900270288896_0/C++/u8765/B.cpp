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
int m[16][16];

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

		memset( m, 0, sizeof(m));

		int iter = 1;
		int best = 1000000000;
		for( int i = (1<<(rows*cols))-1; i >= 0; --i ) {
			++iter;
			int cnt = 0;
			for( int j = 0; j < rows*cols; ++j ) {
				if( i & (1<<j) ) {
					++cnt;
					m[j/cols][j%cols] = iter;
				}
			}
			if( cnt != N ) continue;
			int unhappy = 0;
			for( int r = 0; r < rows; ++r ) {
				for( int c = 0; c < cols; ++c ) {
					if( c < cols-1 && m[r][c] == iter && m[r][c+1] == iter ) ++unhappy;
					if( r < rows-1 && m[r][c] == iter && m[r+1][c] == iter ) ++unhappy;
				}
			}
			best = min( best, unhappy );
		}
		cout << best << endl;
	}
	return 0;
}

