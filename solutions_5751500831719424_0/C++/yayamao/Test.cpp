#include <unistd.h>

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cctype>
#include <cstdio>
#include <future>
#include <string>
#include <thread>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

using std::max;
using std::swap;

using std::map;
using std::set;
using std::pair;
using std::vector;
using std::string;

// Template Begin(By yayamao)
#ifndef ONLINE_JUDGE
#define READ(file_name) \
  do { \
    if (nullptr == freopen(file_name, "r", stdin)) { \
      fprintf(stderr, "Failed open file: \"%s\" for read!\n", file_name); \
      exit(-1); \
    } \
  } while (0)
#define WRITE(file_name) \
  do { \
    if (nullptr == freopen(file_name, "w", stdout)) { \
      fprintf(stderr, "Failed open file: \"%s\" for write!\n", file_name); \
      exit(-1); \
    } \
  } while (0)
#else
#define READ(file_name)
#define WRITE(file_name)
#endif

#ifdef _MSC_VER
#define int64 __int64
#define uint64 unsigned __int64
#else
#define int64 long long
#define uint64 unsigned long long
#endif

#define EPS 1E-9
#define D_INF 1E99
#define I_INF 0x7FFFFFFF
#define L_INF 0x7FFFFFFFFFFFFFFFLL

#define S(x) ((int)x.size())
#define L(x) ((int)x.length())

#define X first
#define Y second

#define VI vstd::ector<int>
#define VS std::vector<string>
#define PB(x) push_back(x)

#define MII std::map<int, int>
#define MSI std::map<string, int>
#define MIS std::map<int, string>

#define PII std::pair<int, int>
#define PSI std::pair<string, int>
#define PIS std::pair<int, string>
#define MP(x,y) std::make_pair(x, y)

#define TWO(x)          (1 << (x))
#define TWOL(x)         (1LL << (x))
#define LOWER_BIT(x)    ((x) & (-(x)))
#define CONTAIN(s,x)    (((s) & TWO(x)) != 0)
#define CONTAINL(s,x)   (((s) & TWOL(x)) != 0)

template<class T>inline void checkMax(T &a, const T &b){if (a < b) a = b;}
template<class T>inline void checkMin(T &a, const T &b){if (b < a) a = b;}
template<class T>inline std::string toString(const T &n){std::ostringstream out;out << n;out.flush();return out.str();}
template<class T>inline T toValue(const std::string &s){T x;std::istringstream in(s);in >> x;return x;}
bool hasNext(){char c;if (scanf(" %c", &c) == EOF) return false;ungetc(c, stdin);return true;}

enum Direction {
  LEFT = 0,
  RIGHT = 1,
  UP = 2,
  DOWN = 3,
  LEFT_UP = 4,
  LEFT_DOWN = 5,
  RIGHT_UP = 6,
  RIGHT_DOWN = 7
};
int dx[]={ 0, 0,-1, 1,-1, 1,-1, 1};
int dy[]={-1, 1, 0, 0,-1,-1, 1, 1};
std::string dir[]={"L", "R", "U", "D", "LU", "LD", "RU", "RD"};

int tenPower[10]={0x1, 0xA, 0x64, 0x3E8, 0x2710, 0x186A0, 0xF4240, 0x989680, 0x5F5E100, 0x3B9ACA00};

#define setv(a, v) memset(a, v, sizeof(a))

// [l, r]
#define range(i, l, r) for(int i = (l); i <= (int)(r); ++i)
#define rangeD(i, r, l) for(int i = (r); i >= (int)(l); --i)

// [0, n)
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define repD(i, n) for(int i = (int)(n) - 1; i >= 0; --i)

#define all(c) (c).begin(), (c).end()
#define foreach(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
// Template Ended(By yayamao)

void preProcess() {
}

class Solution {
public:
  explicit Solution(const int caseId) {
    caseId_ = caseId;
  }

  ~Solution() {
  }

  void input() {
    start_time_ = clock();

    cin >> n_;
    rep (i, n_) {
      string s;
      cin >> s;
      lines_.PB(s);
    }
  }

  void run() {
    end_time_ = clock();

    vector<vector<std::pair<char, int>>> alphas;
    rep (i, n_)
      alphas.PB(getAlphas(lines_[i]));

    min_step_ = go(alphas);

    fprintf(stderr, "Case #%d cost time %.0lfms.\n",
        caseId_, (double)(end_time_ - start_time_) * 1000.0 / CLOCKS_PER_SEC);
  }

  void output() {
    if (min_step_ == -1) {
      cout << "Case #" << caseId_ << ": " << "Fegla Won" << endl;
    } else {
      cout << "Case #" << caseId_ << ": " << min_step_ << endl;
    }
  }

protected:
  int go(const vector<vector<std::pair<char, int>>>& alphas) {
    vector<std::pair<char, int>> result = alphas[0];

    rep (i, n_) {
      if (S(alphas[i]) != S(result)) {
        return -1;
      }
      rep (j, S(result)) {
        if (alphas[i][j].first != result[j].first) {
          return -1;
        }
        checkMax(result[j].second, alphas[i][j].second);
        //std::cerr << "alphas:[" << i << "][" << j << "]=" << alphas[i][j].first << "," << alphas[i][j].second << std::endl;
      }
    }

    int min_step = 0;
    rep (j, S(result)) {
      int mstep = I_INF;
      range (x, 1, result[j].second) {
        int step = 0;
        rep (i, n_) {
          step += abs(alphas[i][j].second - x);
        }
        checkMin(mstep, step);
      }
      min_step += mstep;
    }

    return min_step;
  }

  vector<std::pair<char, int>> getAlphas(const string& s) {
    vector<std::pair<char, int>> alphas;
    if (L(s) == 0) {
      return alphas;
    }

    char c = s[0];
    int count = 1;
    range (i, 1, L(s) - 1) {
      if (s[i] == c) {
        ++count;
      } else {
        alphas.PB(MP(c, count));
        c = s[i];
        count = 1;
      }
    }
    alphas.PB(MP(c, count));
    return alphas;
  }

private:
  int caseId_;
  clock_t start_time_;
  clock_t end_time_;

  int n_;
  vector<string> lines_;
  int min_step_;
};

void runWithoutCaseT() {
  static const int kMaxThreadNumbers = 8;

  int current_threads = 0;
  vector<std::thread> threads;
  vector<std::unique_ptr<Solution>> solutions;

  for (int caseId = 1; hasNext(); ++caseId) {
    std::unique_ptr<Solution> solution(new Solution(caseId));

    solution->input();
    while (current_threads >= kMaxThreadNumbers) {
      for (auto& thread : threads) {
        if (thread.joinable()) {
          thread.join();
          --current_threads;
        }
      }
      usleep(100000);
    }

    threads.emplace_back(&Solution::run, solution.get());
    ++current_threads;

    solutions.emplace_back(std::move(solution));
  }

  for (size_t i = 0; i < solutions.size(); ++i) {
    if (threads[i].joinable()) {
      threads[i].join();
    }
    solutions[i]->output();
  }

  if (solutions.empty()) {
    fprintf(stderr, "Input file is empty!\n");
    exit(-1);
  }
}

void runWithCaseT() {
  int caseT;
  if (scanf("%d\n", &caseT) != 1) {
    fprintf(stderr, "Input file is empty!\n");
    exit(-1);
  }
  runWithoutCaseT();
}

void makeData() {
  freopen("in", "w", stdout);
  int T = 100;
  cout << T << endl;
}

int main(int argc, char *argv[]) {
  //makeData(); return 0;
  srand(time(NULL));

  if (argc == 3) {
    READ(argv[1]);
    WRITE(argv[2]);
  } else {
    READ("in");
    WRITE("out");
  }

  preProcess();

  clock_t begin = clock();
  //runWithoutCaseT();
  runWithCaseT();
  clock_t end = clock();
  fprintf(stderr, "Total case cost time %.3lfs.\n", (double)(end - begin) / CLOCKS_PER_SEC);

  return (EXIT_SUCCESS);
}

