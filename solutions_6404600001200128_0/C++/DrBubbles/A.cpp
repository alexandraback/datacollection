#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>

// Premature optimization is the root of all evil

using namespace std;

void solveacase() {

	int times;
	cin >> times;

	int* shrooms = new int[times];

	int mina = 0;
	int minb = 0;

	for (int i = 0; i < times; ++i ) {
		cin >> shrooms[i];
	}

	for ( int i = 1; i < times; ++i ) {
		if ( shrooms[i] < shrooms[i-1] ) {
			mina += shrooms[i-1] - shrooms[i];
		}
	}

	int minslope = 0;
	for (int i = 1; i < times; ++i ) {
		if ( shrooms[i] < shrooms[i-1] ) {
			if ( shrooms[i-1] - shrooms[i] > minslope ) {
				minslope = shrooms[i-1] - shrooms[i];
			}
		}
	}

	for (int i = 1; i < times; ++i ) {
		minb += min( shrooms[i-1], minslope );
	}

	cout << mina << " " << minb << endl;

	delete shrooms;
	return;
}

int main ( int, char** ) {

	int T;
	cin >> T;

	for ( int i = 1; i <= T; ++i ) {
		cout << "Case #" << i << ": ";
		solveacase();
	}


	return 0;
}
