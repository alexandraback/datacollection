#include <iostream>
using namespace std;

int t, n, m, tc;
int grid[5][5];
int num[17];

int main(){
	cin >> t;
	while( t-- ){
		for( int i=1; i<17; ++i ) num[i] = 0;
		cin >> n;
		for( int i=1; i<5; ++i ){
			for( int j=1; j<5; ++j ){
				cin >> grid[i][j];
			}
		}
		for( int i=1; i<5; ++i )
			num[ grid[n][i] ]++;
		
		cin >> m;
		for( int i=1; i<5; ++i ){
			for( int j=1; j<5; ++j ){
				cin >> grid[i][j];
			}
		}
		for( int i=1; i<5; ++i )
			num[ grid[m][i] ]++;
		
		int two = 0;
		int last = 0;
		for( int i=1; i<17; ++i ){
			if( num[i] == 2 ){
				two++;
				last = i;
			}
		}
		cout << "Case #" << ++tc << ": ";
		if( two == 0 ) cout << "Volunteer cheated!" << endl;
		else if( two == 1 ) cout << last << endl;
		else cout << "Bad magician!" << endl;
	}
}
