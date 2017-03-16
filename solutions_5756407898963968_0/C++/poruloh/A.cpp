#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <numeric>
#include <utility>

using namespace std;

int main(void) {
  
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    vector <int> freq(17);
    for (int k = 0; k < 2; k++) {
      int r; cin >> r;
      for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++) {
	  int x; cin >> x;
	  if (i+1 == r) {
	    freq[x]++;
	    //cout << x << " ";
	  }
	}
    }
    int num2 = 0, x2 = 0;
    for (int x = 1; x <= 16; x++)
      if (freq[x] == 2) {
	num2++;
	x2 = x;
      }    
    printf("Case #%d: ", t);
    if (num2 == 1) printf("%d", x2);
    else if (num2 > 1) printf("Bad magician!");
    else printf("Volunteer cheated!");
    printf("\n");
  }
}
