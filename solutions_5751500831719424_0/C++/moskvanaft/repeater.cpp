#include <string>
#include <cstddef>
#include <vector>
#include <fstream>
#include <iostream>
#include <cassert>

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

int count(const std::string& s1, const std::string& s2) {
  auto& a = s1.size() > s2.size() ? s2 : s1; //less than b
  auto& b = s1.size() > s2.size() ? s1 : s2;
  if (a[0] != b[0]) {
    return -1;
  }
  size_t j = 0;
  size_t i = 0;
  size_t count = 0;
  while(i < b.size() && j < a.size()) {
      if (b[i] == a[j]) {
	++j;
	++i;
      } else if (b[i] == a[j-1]) {
	++count;
	++i;
      } else if (b[i-1] == a[j]) {
	++count;
	++j;
      } else {
	return -1;
      }
  }
  while (i < b.size()) {
    if (b[i] == a[j-1]) {
      ++count;
      ++i;
    } else {
      return -1;
    }
  }
  while (j < a.size()) {
    if (b[i-1] == a[j]) {
      ++count;
      ++j;
    } else {
      return -1;
    }
  }
 return count;
}

void test() {
  assert(1 == count("maw", "mmaw"));
  assert(-1 == count("gcj", "cj"));
  assert(0 == count("abc", "abc"));
  assert(38 == count("fffpppxxrrrrjllfwyzhhuhhhhhhhnccccauuaaaaaahhtzgeophoomjjj", "fppxxrjlllfffwyyzhhuuuuuuuuuhhnccccccauuaahttttzzzgeophhhomjjj"));
  assert(41 == count("fffpppxxrrrrjllfwyzhhuhhhhhhhnccccauuaaaaaahhtzgeophoomjjj", "fppxxrjlllfffwyyzhhuuuuuuuuuhhnccccccauuaahttttzzzgeophhhomjjjjjj"));
  //auto res = count("fffpppxxrrrrjllfwyzhhuhhhhhhhnccccauuaaaaaahhtzgeophoomjjj", "fppxxrjlllfffwyyzhhuuuuuuuuuhhnccccccauuaahttttzzzgeophhhomjjjjjj");
  //std::cout << res << std::endl;
}

int main(int argc, char** argv) {
  if (argc < 2) {
    //std::cerr << "Use ./a.out <file>" << std::endl;
    test();
    return 1;
  }

  Files f(argv[1]);
  size_t T;
  f.in >> T;
  for (size_t t = 1; t <= T; ++t) {
    size_t n;
    f.in >> n;
    std::string s1;
    std::string s2;
    f.in >> s1 >> s2;
    auto res = count(s1, s2);
    f.out << "Case #" << t << ": ";
    if (res >= 0) {
      f.out << res << std::endl;
    } else {
      f.out << "Fegla Won" << std::endl;
    }
  }
  return 0;
}

