#include <iostream>
#include <string>
#include <assert.h>

// Premature optimization is the root of all evil

using namespace std;

void solveacase() {
	int parties;
	cin >> parties;
	int hist[26];
	int total = 0;

	for ( int i = 0; i < parties; ++i ) {
		cin >> hist[i];
		total += hist[i];
	}
	for ( int i = parties; i < 26; ++i ) {
		hist[i] = 0;
	}

	int max = 0;
	int maxers[3];
	maxers[0] = maxers[1] =maxers[2]= -1;
	while( total > 0 ) {
		for ( int i = maxers[1]+1; i < parties; ++i ) {
			if ( hist[i] > max ) {
				maxers[1] = maxers[2]= -1;
				maxers[0] = i;
				max = hist[i];
			}
			else if ( hist[i] == max ) {
				if ( maxers[1] == -1 ) {
					maxers[1] = i;
				}
				else {
					maxers[2] = i;
				}
			}
		}
		if ( maxers[2] != -1 ) {
			cout << " " << char('A' + maxers[2]);
			hist[maxers[2]]--;
			total--;
			maxers[2] = -1;
		}
		else if ( maxers[1] != -1 ) {
			cout << " " << char('A' + maxers[0]) << char('A' + maxers[1]);
			hist[maxers[0]]--;
			hist[maxers[1]]--;
			total -= 2;
			max = 0;
			maxers[0] = maxers[1] = -1;
		}
		else {
			cout << " " << char('A' + maxers[0]);
			hist[maxers[0]]--;
			maxers[0] = -1;
			max = 0;
			total--;
		}

	}
		cout << endl;

	return ;
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
