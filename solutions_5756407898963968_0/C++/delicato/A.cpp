#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < int(n); ++i)
#define all(c) (c).begin(), (c).end()

void solve(const int testcaseIndex) {
  int r1;
  cin >> r1;

  int row1[4][4];

  rep(y, 4) {
    rep(x, 4) {
      cin >> row1[y][x];
    }
  }

  int r2;
  cin >> r2;

  int row2[4][4];

  rep(y, 4) {
    rep(x, 4) {
      cin >> row2[y][x];
    }
  }

  vector<int> v1;
  vector<int> v2;

  rep(x, 4) {
    v1.push_back( row1[r1-1][x] );
    v2.push_back( row2[r2-1][x] );
  }

  sort( all(v1) );
  sort( all(v2) );

  vector<int> intersection;

  set_intersection( all(v1), all(v2), back_inserter(intersection) );


  cout << "Case #" << testcaseIndex + 1 << ": ";
  switch (intersection.size()) {
  case 0:
    cout << "Volunteer cheated!";
    break;

  case 1:
    cout << intersection.front();
    break;

  default:
    cout << "Bad magician!";
    break;
  };

  cout << endl;
}


int main() {

  int T;
  cin >> T;

  rep(i, T) {
    solve(i);
  }

  return 0;
}
