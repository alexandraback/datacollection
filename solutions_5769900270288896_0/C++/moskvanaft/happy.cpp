#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <limits>
#include <algorithm>
#include <map>

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

constexpr size_t inf = std::numeric_limits<size_t>::max();

void test() {
}

inline size_t happy(size_t r, size_t c, const vector<char>& v) {
  size_t h = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    if (v[i] == 1) {
      auto x = i%c;
      auto y = i/c;
      h += (x < c-1 && v[i+1] == 1);
      h += (y < r-1 && v[i+c] == 1);
    }
  }
  return h;
}

size_t solve(size_t r, size_t c, size_t n) {
  vector<char> v(r*c-n, 0);
  v.insert(v.end(), n, 1);
  size_t res = inf;
  do {
    auto h = happy(r, c, v);
    //for (int i : v) { cout << i;   } cout << " (" << n << ") = " << h << endl;
    res = min(res, h);
  } while (next_permutation(v.begin(), v.end()));
  return res;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    //cout << inf << endl;
    //std::cerr << "Use ./a.out <file>" << std::endl;
    //test();
    return 1;
  }

  Files f(argv[1]);
  size_t T;
  f.in >> T;
  for (size_t t = 1; t <= T; ++t) {
    size_t r, c, n;
    f.in >> r >> c >> n;
    auto min = solve(r, c, n);
    f.out << "Case #" << t << ": " << min << endl;
  }
}
