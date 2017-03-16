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

pair<unsigned int,unsigned int> solve(vector<unsigned int> v)
{
     pair<unsigned int,unsigned int> a;

     unsigned int s=0;
     for (auto i=0u; i<v.size()-1; i++)
     {
	  if (v.at(i+1) < v.at(i)) s+=v.at(i)-v.at(i+1);
     }

     a.first = s;

     unsigned int d=0;
     for (auto i=0u; i<v.size()-1; i++)
     {
	  if (v.at(i+1) < v.at(i)) {
	       unsigned int delta = v.at(i)-v.at(i+1);
	       if (delta > d) d = delta ;
	  }
     }

     s = 0;
     for (auto i=0u; i<v.size()-1; i++)
     {
	  if (v.at(i) < d)
	  {
	       s += v.at(i);
	  }
	  else
	  {
	       s += d;
	  }
     }

     a.second = s;

     return a;
}

int main( int argc, char ** argv )
{
     unsigned int i;
     unsigned int t;

     cin >> t;

     for (i=1; i<=t; i++) {
	  unsigned int r;

	  cin >> r;
	  vector<unsigned int> v(r);
	  for (auto &x : v) cin >> x;

	  auto e = solve(v);

	  cout << "Case #" << i << ": ";
	  cout << e.first << " " << e.second ;
	  cout << endl;
     }

     return 0;
}

