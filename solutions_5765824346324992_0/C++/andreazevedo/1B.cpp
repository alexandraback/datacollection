#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long LL;

const string fileName = "small";
ifstream fin (fileName + ".in");
ofstream fout(fileName + ".out");

struct TestCase {
  size_t id;

  std::vector<int> arr;
  LL n;

  string output(int result) {
    std::stringstream buf;
    buf << "Case #" << id << ": " << result;
    return buf.str();
  }
};

vector<TestCase> read() {
  vector<TestCase> vec;

  // reads input
  int numTestCases;
  fin >> numTestCases;
  for (int i = 0; i < numTestCases; ++i) {
    TestCase tc;
    tc.id = i+1;

    int b, n;
    fin >> b >> n;

    tc.n = n;
    tc.arr.resize(b);
    for (int i = 0; i < b; ++i) {
      int tmp;
      fin >> tmp;
      tc.arr[i] = tmp;
    }

    vec.push_back(tc);
  }

  return vec;
}

LL gcd(LL a, LL b)
{
  for (;;) {
    if (a == 0) return b;
    b %= a;
    if (b == 0) return a;
    a %= b;
  }
}
LL lcm(LL a, LL b)
{
  LL tmp = gcd(a, b);
  return tmp ? (a / tmp * b) : 0;
}
LL lcm(TestCase& tc) {
  LL res = tc.arr[0];
  for (int i = 1; i < tc.arr.size(); ++i) {
    res = lcm(res, tc.arr[i]);
  }
  return res;
}

int smallest(std::vector<int>& vec) {
  int is = 0;
  int s = vec[0];
  for (int i = 1; i < vec.size(); ++i) {
    if (vec[i] < s) {
      s = vec[i];
      is = i;
    }
  }
  return is;
}
void sub(std::vector<int>& vec, int num) {
  if (num == 0) return;
  for (int i = 0; i < vec.size(); ++i) {
    vec[i] -= num;
  }
}
int solve(TestCase& tc) {
  std::vector<int> freeIn(tc.arr.size());
  for (int j = 0; j < tc.arr.size(); ++j) {
    freeIn[j] = 0;
  }

  int l = lcm(tc);
  int cl = 0;
  for(int i = 0; i < tc.arr.size(); i++) {
    cl += l / tc.arr[i];
  }
  tc.n = tc.n % cl;
  if (tc.n == 0) {
    tc.n = cl;
  }

  int j = 0;
  for (int i = 1; i <= tc.n; ++i) {
    j = smallest(freeIn);
    sub(freeIn, freeIn[j]);
    freeIn[j] = tc.arr[j];
  }
  return j + 1;
}

int main() {
  // reads input
  auto vec = read();

  // solves and writes solution.
  for (auto& tc : vec) {
    auto sol = solve(tc);
    fout << tc.output(sol) << endl;
    cout << tc.output(sol) << endl;
  }

  return 0;
}
