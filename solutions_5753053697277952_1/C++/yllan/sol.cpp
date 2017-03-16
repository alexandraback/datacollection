#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>

// C++
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef long long ll;
typedef unsigned long long ull;
typedef complex<double> pnt;
typedef pair<int, int> pii;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define REPI(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

// insert other library code here...

// #define MAXN
int n;
int p[30];

bool larger(int half) 
{
  REPI(i, n) {
    if (p[i] * 2 > half) return true;
  }
  return false;
}

void solve()
{
  int sum = 0;
  REPI(i, n) sum += p[i];
  
  while (sum > 0) {
    int max_v = -1;
    int max_p = -1;
    REPI(i, n) {
      if (p[i] > max_v) {
        max_v = p[i];
        max_p = i;
      }
    }
    
    putchar('A' + max_p);
    p[max_p]--;
    sum--;
    if (!larger(sum)) {
      putchar(' ');
    }
  }
  printf("\n");
}

int main(int argc, char* argv[])
{
  int TEST_FROM = 0;
  int TEST_TO = 123456789;
  if (argc == 3) {
    sscanf(argv[1], "%d", &TEST_FROM);
    sscanf(argv[2], "%d", &TEST_TO);
  }
  // freopen("in", "r", stdin);
  // freopen("out", "w", stdout);

  int T = 0;
  scanf("%d", &T);
  for(int testcase = 1; testcase <= T; testcase++) {
    ll begin_clock = (ll)clock();
    // *** input data starts ***
    scanf("%d", &n);
    REPI(i, n) {
      scanf("%d", &p[i]);
    }
    
    // *** input data ends ***
    if (testcase < TEST_FROM || testcase > TEST_TO) {
      continue;
    }
    
    printf("Case #%d: ", testcase);
    fflush(stdout);
    
    // *** solution starts ***
    solve();
    // *** solution ends ***
    
    fflush(stdout);
    fprintf(stderr, "\x1b[1;33;40m test %d solved, time = %lld clocks.\x1b[m\n", testcase, (ll)(clock() - begin_clock));
  }
  return 0;
}
