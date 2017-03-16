#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <iterator>
#include <utility>
#include <iomanip>
#include <cmath>
#include <climits>
#include <stdio.h>
#include <string.h>

using namespace std;

long gcd(long a, long b) {
  while (b != 0) {
    long tmp = a;  a = b;  b = tmp % b;
  }
  return a;
}

void solve() {
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    int B;
    long long N;
    cin >> B >> N;
    
    std::vector<int> vv(B);    for (int i = 0; i < B; i++) { cin >> vv[i]; }
    
    long long m = vv[0];
    int prev = vv[0];
    for (int i = 1; i < B; i++) {
      m *= vv[i] / gcd(prev, vv[i]);
      prev = vv[i];
    }
//    cerr << m << endl;
    long long m2 = 0;
    for (int i = 0; i < B; i++) {
      m2 += m/vv[i];
    }
//    cerr << m2 << endl;
    
    long long n = N % m2;
    if (n == 0) n = m2;
//    cerr << n << endl;
    long long tmpn = 0;
    std::vector<int > bb(B, 0);
    int result = -1;
    while (true) {
      auto mm = *(std::min_element(bb.begin(), bb.end()));
      for (int i = 0; i < B; i++) {
	bb[i] -= mm;
      }
      for (int i = 0; i < B; i++) {
	if (bb[i] == 0) {
	  bb[i] += vv[i];
	  tmpn++;
	  if (tmpn == n) {
	    result = i;
	    break;
	  }
	}
      }
      if (result != -1) break;
    }

    std::cout << "Case #" << (t+1) << ": " << (result+1) << std::endl;
  }
}

int main(int argc, char *argv[])
{
  solve();
  return 0;
}
