
/* Includes {{{ */
// C
#ifndef _GLIBCXX_NO_ASSERT
#include <cassert>
#endif
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

#if __cplusplus >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#endif

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

#if __cplusplus >= 201103L
#include <array>
#include <atomic>
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
#endif
/* }}} Includes */

/* Defines {{{ */
#define DBG(x) std::cerr << #x << " = " << x << std::endl
/* }}} Defines */

/* Typedefs {{{ */
using namespace std;

template<typename T>
using V = vector<T>;
template<typename T>
using VV = vector<vector<T>>;
template<typename T, size_t N>
using A = array<T,N>;
template<typename T, size_t M, size_t N = M>
using AA = array<array<T,N>,M>;
template<typename T>
using uset = unordered_set<T>;
template<typename K, typename V>
using umap = unordered_map<K,V>;
template<typename T>
using mset = multiset<T>;
template<typename K, typename V>
using mmap = multimap<K,V>;
template<typename T>
using umset = unordered_multiset<T>;
template<typename K, typename V>
using ummap = unordered_multimap<K,V>;
template<typename T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_heap = priority_queue<T, vector<T>, less<T>>;
using i8   = int_fast8_t;
using i16  = int_fast16_t;
using i32  = int_fast32_t;
using i64  = int_fast64_t;
// using i128 = __int128_t;
using u8   = uint_fast8_t;
using u16  = uint_fast16_t;
using u32  = uint_fast32_t;
using u64  = uint_fast64_t;
// using u128 = __uint128_t;
using f32  = float;
using f64  = double;
using f128 = long double;
/* }}} Typedefs */

string solve() {
  int N;
  cin >> N;
  max_heap<pair<int, int>> heap;
  for (int i = 0; i < N; ++i) {
    int P;
    cin >> P;
    heap.push({P, i});
  }

  vector<string> res;
  while (heap.size() > 2) {
    auto top = heap.top();
    heap.pop();

    res.emplace_back(1, 'A' + top.second);
    if (--top.first) {
      heap.push(top);
    }
  }

  auto V = heap.top();
  heap.pop();

  auto W = heap.top();
  heap.pop();

  assert(V.first == W.first);
  for (int i = 0; i < V.first; ++i) {
    string curr = "  ";
    curr[0] = 'A' + V.second;
    curr[1] = 'A' + W.second;
    res.push_back(move(curr));
  }

  string ans = res[0];
  for (size_t i = 1; i < res.size(); ++i) {
    ans += " " + res[i];
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cout << "Case #" << t+1 << ": " << solve() << endl;
  }

  return 0;
}
