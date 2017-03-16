#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>
#include <cmath>
#include <climits>
#include <bitset>

using namespace std;

typedef unsigned long long lint;

lint solve(lint R, lint C, lint N) {
  lint curbest = ULLONG_MAX;
  for(lint i = 0; i < pow(2, R*C); i++) {
    lint n = 0;
    for(int k = 0; k < R*C; k++) {
      if((i & (1 << k)) > 0) n++;
    }
    if(n != N) continue;
    // cout << "found possible config" << endl;

    // cout << "--- i = " << i << endl;
    // for(int y = 0; y < R; y++) {
    //   for(int x = 0; x < C; x++) {
    //     lint aptn = C * y + x;
    //     cout << ((i & (1 << aptn) > 0) ? "#" : " ");
    //   }
    //   cout << "|" << endl;
    // }
    // cout << "---" << endl;

    lint unhappiness = 0;
    for(int y = 0; y < R; y++) {
      for(int x = 0; x < C; x++) {
        lint aptn = C * y + x;
        lint neigh1 = C * y  + x + 1;
        lint neigh2 = C * (y + 1) + x;
        // cout << "R*C: " << R*C << "; aptn: " << aptn << "; n1: " << neigh1 << "; n2: " << neigh2 << endl;


        // cout << "i = " << i << endl;
        // cout << "i:       " << (bitset<64>) i << endl;
        // cout << "aptn:    " << (bitset<64>) (1 << aptn) << endl;
        // cout << "i&aptn:  " << (bitset<64>) (i & (1 << aptn)) << endl;
        // cout << "i&aptn:  " << (i & (1 << aptn)) << endl;
        // cout << "n1:      " << (bitset<64>) (1 << neigh1) << endl;
        // cout << "i&n1:    " << (bitset<64>) (i & (1 << neigh1)) << endl;
        // cout << "n2:      " << (bitset<64>) (1 << neigh2) << endl;
        // cout << "i&n2:    " << (bitset<64>) (i & (1 << neigh2)) << endl;

        if((i & (1 << aptn)) > 0) {
          // cout << "has aptn " << aptn << endl;
          if(x < C - 1 && (i & (1 << neigh1)) > 0) {
            // cout << "has n1 " << neigh1 << endl;
            unhappiness++;
          }
          if(y < R - 1 && (i & (1 << neigh2)) > 0) {
            // cout << "has n2 " << neigh2 << endl;
            unhappiness++;
          }
        }
      }
    }
    // cout << "unhappines: " << unhappiness << endl;
    curbest = min(curbest, unhappiness);
  }
  return curbest;
}

int main() {
  lint T;
  cin >> T;

  for(lint t = 1; t <= T; t++) {
    lint R, C, N;
    cin >> R >> C >> N;

    lint sol = solve(R, C, N);

    cout << "Case #" << t << ": " << sol << endl;
  }

  return 0;
}
