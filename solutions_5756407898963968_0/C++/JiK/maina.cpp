/* My Template for the Google Code Jam.
 *
 * Compile: g++ -std=c++11 -lgmp -lgmpxx
 *  - I'm probably using some c++11 features.
 *  - I might use GMP (GNU Multiple Precision Arighmetic Library) so
 *    I'm including -lgmp and -lgmpxx in the template even if they
 *    won't be used.
 *
 * This code is ugly but it works - otherwise you wouldn't be reading
 * it, right?
 */

#include <cassert>
//#define NDEBUG

#include <cstdlib>
#include <cstdint>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

#include <gmpxx.h>

void solve() {
  int first, second;
  bool possible[17];
  for(int i=0;i<17;i++)
    possible[i] = true;

  std::cin >> first;
  for(int i=0; i<4; i++){
    for(int j=0;j<4;j++) {
      int k;
      std::cin >> k;
      if(i!=first-1) {
	possible[k] = false;
      }
    }
  }

  std::cin >> second;
  for(int i=0; i<4; i++){
    for(int j=0;j<4;j++) {
      int k;
      std::cin >> k;
      if(i!=second-1) {
	possible[k] = false;
      }
    }
  }

  int count = 0;
  int res = 0;
  for(int i=1; i<=16; i++) {
    if(possible[i]) {
      count++;
      res = i;
    }
  }
  
  if(count ==0)
    std::cout << "Volunteer cheated!";
  else if(count >1)
    std::cout << "Bad magician!";
  else std::cout << res;

}

void pre_compute() {
  
}

int main() {
  pre_compute();
  size_t T;
  std::cin >> T;
  for(size_t i=1; i<=T; i++) {
    std::cout << "Case #" << i << ": ";
    solve();
    std::cout <<  "\n";
  }

  return 0;
}
