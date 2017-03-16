#include <iostream>
using namespace std;

int main() {

  int T;

  cin >> T;

  for ( int i = 0; i < T; i++ ) {

    int r1,r2;

    cin >> r1;

    int map1[4][4],map2[4][4];

    for ( int y = 0; y < 4; y++ ) {

      for ( int x = 0; x < 4; x++ ) {

	cin >> map1[x][y];

      }

    }

    cin >> r2;

    for ( int y = 0; y < 4; y++ ) {

      for ( int x = 0; x < 4; x++ ) {

	cin >> map2[x][y];

      }

    }

    int ans = 0;

    cout << "Case #" << i+1 << ": ";

    for ( int x = 0; x < 4; x++ ) {

      for ( int y = 0; y < 4; y++ ) {

	if ( map1[x][r1-1] != map2[y][r2-1] ) continue;

	if ( ans != 0 ) {

	  cout << "Bad magician!" << endl;

	  ans = -1;

	  break;

	}

	ans = map1[x][r1-1];

      }

      if ( ans == -1 ) break;

    }

    if ( ans == -1 ) continue;

    if ( ans == 0 ) {

      cout << "Volunteer cheated!" << endl;

    }else {

      cout << ans << endl;

    }

  }

  return 0;

}
