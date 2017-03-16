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

ll solve() {
  size_t B;
  ll N;
  cin >> B;
  cin >> N;
  vector<ll> M;
  read_to_vector(B, M);

  ll minM = 1000001;
  for(int i=0; i<B; i++) {
    minM = min(M[i], minM);
  }

  ll mint = 0;
  ll maxt = 1000000LL*1000000000LL*10LL;

  while(maxt > mint) {
    ll testt = (maxt + mint) / 2;
    ll cust = 0; //customers finished
    for(int i=0; i<B; i++) {
      cust +=  (testt + M[i] - 1) / M[i];
    }
    cerr << testt << ":" << cust << "\n";
    if(cust >= N)
      maxt = testt;
    if(cust < N)
      mint = testt+1;
    //    cerr << mint << " " << maxt << "\n";
  }

  ll T = maxt - 1;
  ll cust = 0; //customers taken
  for(int i=0; i<B; i++) {
    cust +=  (T+M[i] - 1) / M[i];
  }

  ll custleft = N - cust;

  cerr << "Served at " << T << ": " << cust << "\n";
  ll res = -1;
  for(int i=0; i<B; i++) {
    if (T % M[i] == 0) {
      custleft--;
    }
    if(custleft==0) {
      res = i;
      break;
    }
  }
  
  cerr << T << " " << res << "\n";

  return res+1; // offset
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
    //CHOOSE A
    auto res = solve();
    std::cout << "Case #" << i << ": " << res << "\n";
  }

  return 0;
}
