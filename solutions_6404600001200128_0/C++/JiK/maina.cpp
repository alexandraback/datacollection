/* My Template for the Google Code Jam.
 *
 * Compile: g++ -std=c++11 -lgmp -lgmpxx
 *  - I'm probably using some C++11 features.
 *  - I might use GMP (GNU Multiple Precision Arighmetic Library) so
 *    I'm including the library in the template even if they
 *    won't be used.
 *
 * This code is ugly but it works - otherwise you wouldn't be reading
 * it, right?
 */

#include <cassert>
//#define NDEBUG

#include <cstdlib>
#include <cstdint>
#include <cmath>

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

#include <gmpxx.h>

using namespace std;
typedef size_t szt;

typedef long long ll;
typedef unsigned long long ull;

typedef mpz_class mpz;

template<typename T>
void read_to_vector(size_t N, std::vector<T> &v) {
  for(size_t i=0; i<N; i++) {
    T tmp;
    std::cin >> tmp;
    v.push_back(tmp);
  }
}
template<typename T>
void print_vector(const std::vector<T> &v) {
  for(auto it = v.begin(); it<v.end(); it++) {
    if(it==v.begin())
      std::cout << " ";
    std::cout << (*it);
  }
}

//Copy functions from TCR here.



//Solution:

ll solvea(int N, vector<ll> M) {
  ll mini = 0;
  for(int i=0; i<N-1; i++) {
    if(M[i+1] < M[i]) {
      mini += M[i] - M[i+1];
    }
  }
  return mini;
}

ll solveb(int N, vector<ll> M) {
  ll minirate = 0;

  for(int i=0; i<N-1; i++) {
    minirate = max(M[i] - M[i+1], minirate);
  }

  ll mini = 0;
  for(int i=0; i<N-1; i++) {
    mini += min(minirate, M[i]);
  }

  return mini;
  
}

void solve() {
  int N;
  cin >> N;
  vector<ll> M;
  read_to_vector(N,M);

  std::cout << solvea(N,M) << " " << solveb(N,M);
}

//This is executed before any input is read.
void pre_compute() {
  
}

int main() {
  std::cout << std::setprecision(15);
  pre_compute();
  size_t T;
  std::cin >> T;
  for(size_t i=1; i<=T; i++) {
    std::cout << "Case #" << i << ": ";
    solve();
    std::cout << "\n"; //Either of these should be removed.
  }

  return 0;
}
