#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <queue>
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

inline size_t gcd (size_t a, size_t b) {
  while (b) {
    a %= b;
    swap (a, b);
  }
  return a;
}

inline size_t lcm(size_t a, size_t b) {
  return a*b / gcd(a, b);
}
/*
pair<size_t, size_t> solve(const vector<uint> m, size_t n) {
  //cout << " --- " << endl;
  size_t 
  return ;
}
*/
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
    size_t n;
    f.in >> n;
    vector<size_t> m = f.get_vec<size_t>(n);
    //auto res = solve(m, n);
    size_t first = 0;
    size_t max = 0;
    for (size_t i = 1; i < m.size(); ++i) {
      if (m[i-1] > m[i]) {
	auto diff = m[i-1] - m[i];
	first += diff;
	if (diff > max) {
	  max = diff;
	}
      }
    }
    size_t second = 0;
    for (size_t i = 0; i < m.size()-1; ++i) {
      second += std::min(max, m[i]);
    }

    f.out << "Case #" << t << ": " << first << ' ' << second << endl;
  }

  /*
  vector<size_t> res = r.result();
  for (size_t t = 1; t <= T; ++t) {
    f.out << "Case #" << t << ": " <<  res[t-1] << endl;
  }
  */
}
