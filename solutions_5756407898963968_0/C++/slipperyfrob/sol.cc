#include <iostream>
#include <set>

using namespace std;

struct bd {
	size_t guess;
	size_t bd[4][4];
};

int main() {
	size_t T; cin >> T;
	for( size_t Case = 1; Case <= T; ++Case ) {
		bd bd1, bd2;
		cin >> bd1.guess; --bd1.guess;
		for( size_t i = 0; i < 4; ++i )
		for( size_t j = 0; j < 4; ++j )
			cin >> bd1.bd[i][j];
		cin >> bd2.guess; --bd2.guess;
		for( size_t i = 0; i < 4; ++i )
		for( size_t j = 0; j < 4; ++j )
			cin >> bd2.bd[i][j];
		set< size_t > oks; oks.clear();
		for( size_t i1 = 0; i1 < 4; ++i1 )
		for( size_t i2 = 0; i2 < 4; ++i2 ) {
			if( bd1.bd[bd1.guess][i1] == bd2.bd[bd2.guess][i2] ) {
				oks.insert( bd1.bd[bd1.guess][i1] );
			}
		}
		cout << "Case #" << Case << ": ";
		if( oks.empty() ) {
			cout << "Volunteer cheated!";
		}
		else if( oks.size() == 1 ) {
			cout << *oks.begin();
		}
		else {
			cout << "Bad magician!";
		}
		cout << endl;
	}
	return 0;
}
