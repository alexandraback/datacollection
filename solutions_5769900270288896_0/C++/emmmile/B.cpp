#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <cmath>
#include <numeric>
#include <set>
#include <vector>
using namespace std;
typedef long long ll;



int main ( ) {
	FILE *fin = freopen("B-small.in", "r", stdin);
	assert( fin!=NULL );
	FILE *fout = freopen("B-small.out", "w", stdout);
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		cout << "Case #" << t << ": ";
		
		int r, c, n;
		cin >> r >> c >> n;


		std::vector<int> s(r * c, 0);
		for ( int i = 0; i < n; ++i) s[i] = 1;

    	std::sort(s.begin(), s.end());
    	int best = 100000;
		do {
			int shared = 0;
			for ( int i = 0; i < r * c; ++i) {
				if ( s[i] == 0 ) continue;

				int x = i / c;
				int y = i % c;

				int j;
				j = (x-1) * c + y;
				if ( x != 0 && j > i ) shared += s[j];

				j = x * c + y - 1;
				if ( y != 0  && j > i ) shared += s[j];

				j = (x+1) * c + y;
				if ( x != r - 1  && j > i ) shared += s[j];

				j = x * c + y + 1;
				if ( y != c - 1  && j > i ) shared += s[j];
			}
			best = min(best, shared);
		} while(std::next_permutation(s.begin(), s.end()));

		cout << best << endl;
	}

	fclose(fout);
	exit(0);
}