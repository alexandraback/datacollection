#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

#define iterate(_i, _c) _i = _c.begin(); _i != _c.end(); ++_i
#define existsIn(_k, _c) (_c.find(_k) != _c.end())

#if 0
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace boost::multiprecision;
#define Integer cpp_int
#define Rational cpp_rational
#define Float cpp_dec_float_50
#endif

int main(void) {
  int T; cin >> T;
  
  for (int iCase = 1; iCase <= T; ++iCase) {
    cout << "Case #" << iCase << ":";
    cerr << "[" << iCase << "] " << flush;

    int i, n; cin >> n;
    vector< pair<int, char> > members(n);
    int total = 0;

    for (i = 0; i < n; ++i) {
      int count; cin >> count;
      members[i] = make_pair(count, 'A'+i);
      total += count;
    }

    vector< pair<int, char> >::iterator start = members.begin();;
    while (total > 0) {
      while (start != members.end() && start->first==0) ++start;
      sort(start, members.end());
      
      int &no1 = members[n-1].first;
      int &no2 = members[n-2].first;
      char party1 = members[n-1].second;
      char party2 = members[n-2].second;
      
      if (no1==1) {  // All 1's and 0's
	if (total==3) {
	  --total; --no1;
	  cout << " " << party1;
	} else {
	  total -= 2; --no1; --no2;
	  cout << " " << party1 << party2;
	}
      } else {  // no1 at least 2
	--total; --no1;
	cout << " " << party1;

	if (no2 > no1 || total > 2*no2) {
	  --total; --no2;
	  cout << party2;
	}
      }    
    }
    
    cout << "\n";
  }

  return 0;
}
