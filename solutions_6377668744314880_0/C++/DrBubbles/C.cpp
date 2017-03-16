#include <iostream>
#include <string>
#include <assert.h>
#include <algorithm>

// Premature optimization is the root of all evil

using namespace std;

void solveacase() {
	int N;
	cin >> N;

	int* X = new int[N];
	int* Y = new int[N];
	int* out = new int[N];

	for ( int i = 0; i < N; ++i ) {
		cin >> X[i] >> Y[i];
		out[i] = N;
	}

	if ( N == 1 ) { out[0] = 0; }

	for (int i = 0; i < N; ++i ) {
		for ( int j = i + 1; j < N; ++j ) {

			long long dX = X[i] - X[j];
			long long dY = Y[i] - Y[j];
			int l = 0;
			int r = 0;

			for ( int k = 0; k < N; ++k ) {

				long long x = X[k] - X[i];
				long long y = Y[k] - Y[i];

				long long theta = dX * (long long)y - dY * (long long) x;

				if ( theta > 0 ) { ++l; }
				else if ( theta < 0 ) { ++r; }
			}

			int c = min(l, r);
			out[i] = min( out[i], c );
			out[j] = min( out[j], c );
			
			//cout << "[" << i << ", " << j << "] " << l << " " << r << endl;

		}

		cout << out[i] << endl;
	}



	delete X;
	delete Y;
	delete out;

	return ;
}

int main ( int, char** ) {

	int T;
	cin >> T;

	for ( int i = 1; i <= T; ++i ) {

		cout << "Case #" << i << ": " << endl;
		solveacase();
	}


	return 0;
}
