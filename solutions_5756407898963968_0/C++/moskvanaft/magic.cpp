#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
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

template<class T> class Matrix {
  size_t m_rows;
  size_t m_cols;
  std::vector<T> m_values;
 public:
  size_t rows() const {
    return m_rows;
  }
  size_t cols() const {
    return m_cols;
  }
  T& operator()(size_t r, size_t c) {
    assert(1 <= r && r <= m_rows);
    assert(1 <= c && c <= m_cols);
    return m_values[(r-1)*m_rows+(c-1)];
  }
  const T& operator()(size_t r, size_t c) const {
    assert(1 <= r && r <= m_rows);
    assert(1 <= c && c <= m_cols);
    return m_values[(r-1)*m_rows+(c-1)];
  }
  Matrix(size_t r, size_t c, const std::initializer_list<T>& l) : m_rows(r), m_cols(c), m_values(l) {
    assert(r*c == l.size());
  }
  Matrix(size_t r, size_t c) : m_rows(r), m_cols(c), m_values(r*c) {
  }
};

template<class T> std::ostream& operator<<(std::ostream& osm, const Matrix<T>& m) {
  for (size_t r = 1; r <= m.rows(); ++r) {
    for (size_t c = 1; c <= m.cols(); ++c) {
      osm << std::setw(3) << m(r,c);
    }
    osm << std::endl;
  }
  return osm;
}

template<class T> std::istream& operator>>(std::istream& ism, Matrix<T>& m) {
  for (size_t r = 1; r <= m.rows(); ++r) {
    for (size_t c = 1; c <= m.cols(); ++c) {
      ism >> m(r,c);
    }
  }
  return ism;
}

int main() {
  Files f("A-small-attempt0.in");
  size_t N;
  f.in >> N;

  size_t row1, row2;
  for (size_t n = 1; n <= N; ++n) {
    f.in >> row1;
    Matrix<int> m1(4, 4);
    f.in >> m1;
    f.in >> row2;
    Matrix<int> m2(4, 4);
    f.in >> m2;

    int res = 0;
    for (size_t i = 1; i <= 4; ++i) {
      auto t = m1(row1, i);
      bool found = false;
      for (size_t j = 1; j <= 4; ++j) {
	if (t == m2(row2, j)) {
	  found = true;
	  break;
	}
      }
      if (found) {
	if (0 == res) {
	  res = t;
	} else {
	  res = -1;
	  break;
	}
      }
    }
    f.out << "Case #" << n << ": ";
    if (-1 == res) {
      f.out << "Bad magician!";
    } else if (0 == res) {
      f.out << "Volunteer cheated!";
    } else {
      f.out << res;
    }
    f.out << std::endl;
  }
}

