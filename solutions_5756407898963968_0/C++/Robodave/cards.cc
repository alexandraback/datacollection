#include <cstdio>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef unsigned int uint;
typedef vector< uint > tRow;
typedef vector< tRow > tGrid;

int main()
{
  uint t = 0;
  cin >> t;

  for ( uint i = 1; i <= t; i++ ) {
    uint r1, r2;
    tGrid g(4,4);
    tRow set1(4), set2(4);

    // read first grid
    cin >> r1;
    for (uint j = 0; j < 4; j++) {
      for (uint k = 0; k < 4; k++) {
	cin >> g[j][k];
      } // for k
    } // for j
    set1 = g[r1-1];

    // read second grid
    cin >> r2;
    for (uint j = 0; j < 4; j++) {
      for (uint k = 0; k < 4; k++) {
	cin >> g[j][k];
      } // for k
    } // for j
    set2 = g[r2-1];

    int ans = 0;
    for (uint j = 0; j < 4; j++) {
      for (uint k = 0; k < 4; k++) {
	if (set1[j] == set2[k]) {
	  if (ans == 0) {
	    ans = set1[j];
	  } else {
	    ans = -1;
	  } // else
	} // if
      } // for k
    } // for j

    switch(ans) {
    case -1:
      printf("Case #%d: Bad magician!\n", i);
      break;
    case 0:
      printf("Case #%d: Volunteer cheated!\n", i);
      break;
    default:
      printf("Case #%d: %d\n", i, ans);
    }

  } // for i

  return 0;
} // main
