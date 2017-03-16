#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <limits>
#include <map>
#include <algorithm>

using namespace std;

struct noncopyable {
  noncopyable(const noncopyable&) = delete;
  noncopyable& operator=(const noncopyable&) = delete;
  noncopyable() {}
};

struct Files : noncopyable {
  std::fstream in;
  std::fstream out;

  static std::string name_to_out(const std::string& s) {
    if (s.substr(s.size()-3) == ".in") {
      return s.substr(0, s.size()-3)+".out";
    } else {
      return s+".out";
    }
  }

  Files(const std::string& name) : in(name.c_str(), std::ios_base::in),
    out(name_to_out(name).c_str(), std::ios_base::out) {
  }

  size_t get_numline() {
    size_t N;
    in >> N;
    std::string es;
    std::getline(in, es);
    if (!es.empty()) {
      assert(false);
    }
    return N;
  }

  template<class T> std::vector<T> get_vec(size_t n) {
    std::vector<T> v;
    v.reserve(n);
    while (n-- > 0) {
      T tmp;
      in >> tmp;
      v.push_back(std::move(tmp));
    }
    return v;
  }

  template<class T> T get() {
    T tmp;
    in >> tmp;
    return tmp;
  }
};

typedef unsigned int uint;

inline uint gcd (uint a, uint b) {
  while (b) {
    a %= b;
    swap (a, b);
  }
  return a;
}

inline uint lcm(uint a, uint b) {
  return a*b / gcd(a, b);
}

size_t solve(const vector<uint> m, size_t n) {
  //cout << " --- " << endl;
  size_t x = 1;
  for (auto i : m) {
    x = lcm(x, i);
  }
  size_t count = 0;
  for (auto i : m) {
    count += x/i;
  }
  n = n%count;
  if (n == 0) {
    n = count;
  }
  //cout << "n = " << n << endl;
  vector<uint> fr(m.size());
  uint min = 0;
  for (size_t k = 1; k <= n; ++k) {
    min = 0;
    for (size_t i = 1; i < fr.size(); ++i) {
      if (fr[i] < fr[min]) {
	min = i;
      }
    }
    fr[min] += m[min];
    //cout << k << " : " << (min+1) << endl;
  }
  return min;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    std::cerr << "Use ./a.out <file>" << std::endl;
    //test();
    return 1;
  }

  Files f(argv[1]);
  size_t T;
  f.in >> T;

  for (size_t t = 1; t <= T; ++t) {
    size_t b, n;
    f.in >> b >> n;
    vector<uint> m = f.get_vec<uint>(b);
    auto res = solve(m, n);
    f.out << "Case #" << t << ": " << (res+1) << endl;
  }

  /*
  vector<size_t> res = r.result();
  for (size_t t = 1; t <= T; ++t) {
    f.out << "Case #" << t << ": " <<  res[t-1] << endl;
  }
  */
}
