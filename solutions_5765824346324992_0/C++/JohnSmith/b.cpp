//
// Round 1a 2015  problem A
//
// Usually built with g++ 4.4.5 on Linux
//
#include <iostream>
#include <iomanip>
#include <vector>
#include <set>
#include <gmpxx.h>

#include <cstdlib>
#include <math.h>

using namespace std;

uint64_t count( const vector<unsigned int> &v, uint64_t t )
{
     uint64_t s=0;    
     for (auto &x : v) s+= 1 + t/x;
     return s;
}
unsigned int solve(vector<unsigned int> v, unsigned int n)
{
     //cerr << "Solve " << n << endl;
     if (n <= v.size()) return n;
 
     uint64_t t_lo = 0;
     uint64_t t_hi = 100000000000000000;

     while (t_hi - t_lo > 1)
     {
	  uint64_t t = (t_hi+t_lo)/2;
	  uint64_t c = count(v, t);
	  if (c < n) {
	       t_lo = t;
	  } else {
	       t_hi = t;
	  }
	  if (0) {
	       cerr << t_lo << " ";
	       cerr << t << " ";
	       cerr << t_hi << " ";
	       cerr << "   " << c << " ";
	       cerr << endl;
	  }
     }

     uint64_t t = t_hi;
     uint64_t k = n - count(v,t-1);
     //cerr << "k = " << k << endl;
     for (unsigned int i=0; i<v.size(); i++)
     {
	  if (t % v.at(i) == 0) {
	       k--;
	       if (k==0) return i+1;
	  }
     }
     cerr << "Failed to find an answer" << endl;
     exit(0);

     return 0;
}

int main( int argc, char ** argv )
{
     unsigned int i;
     unsigned int t;

     cin >> t;

     for (i=1; i<=t; i++) {
	  unsigned int b;
	  unsigned int n;

	  cin >> b >> n;

	  vector<unsigned int> v(b);
	  for (auto &x : v) cin >> x;
	  auto e = solve(v, n);

	  cout << "Case #" << i << ": ";
	  cout << e ;
	  cout << endl;
     }

     return 0;
}

