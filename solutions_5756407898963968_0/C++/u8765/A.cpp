#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cassert>
#include <cmath>
#include <deque>
#include <map>
#include <cstring>
#include <set>

using namespace std;

int main() {
	int cases;

	cin >> cases;

	for( int caseid = 1; caseid <= cases; ++caseid ) {
		cout << "Case #" << caseid << ": ";

		int r1;
		cin >> r1;

		int a1[4][4];
		for( int i = 0; i < 4; ++i ) {
			for( int j =0 ; j < 4; ++j ) {
				cin >> a1[i][j];
			}
		}

		int r2;
		cin >> r2;

		int a2[4][4];
		for( int i = 0; i < 4; ++i ) {
			for( int j = 0; j < 4; ++j ) {
				cin >> a2[i][j];
			}
		}

		int cnt = 0;
		int result;
		for( int i = 0; i < 4; ++i ) {
			for( int j = 0; j < 4; ++j ) {
				if( a1[r1-1][i] == a2[r2-1][j] ) {
					++cnt;
					result = a1[r1-1][i];
				}
			}
		}

		if( cnt == 0 ) {
			cout << "Volunteer cheated!\n";
		} else if( cnt == 1 ) {
			cout << result << endl;
		} else {
			cout << "Bad magician!\n";
		}
	}
	return 0;
}
