
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cassert>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

  template<typename A>
  A GreatestCommonDivisor(const A a, const A b) {
    if (a > b)
      return GreatestCommonDivisor(b, a);
    if (b % a == 0)
      return a;
    return GreatestCommonDivisor(a, b % a);
  }

int Naive(const vector<int> &b, int N) {
  int gcd = b[0];
  int64_t m = b[0];
  for (int i = 1; i < b.size(); i++) {
    gcd = GreatestCommonDivisor(gcd, b[i]);
    m *= b[i];
  }
  m /= gcd;
  int64_t n = 0;
  vector<pair<int, int>> seq;
  for (int i = 0; i < b.size(); i++) {
    n += m / b[i];
    for (int k = 0; k < m / b[i]; k++) {
      seq.emplace_back(k * b[i], i);
    }
  }
  sort(seq.begin(), seq.end());

  N = N % n;

  if (N == 0) {
    N = seq.size() - 1;
  } else {
    N--;
  }
  return seq[N].second + 1;
}

int64_t CountT(const vector<int> &b, int64_t T) {
  int64_t total = 0;
  for (int i = 0; i < b.size(); i++) {
    total += T / b[i];
    total++;
  }
  return total;
}

int64_t TestTime(const vector<int> &b, int N, int64_t T) {
  return N - CountT(b, T);
}

int64_t FindTime(const vector<int> &b, int N, int64_t l, int64_t h) {
  assert(l <= h);
  if (h - l < 4) {
    for (int64_t i = l; i <= h; i++) {
      if (TestTime(b, N, i) <= 0)
        return i;
    }
    assert(false);
  }
  int64_t m = (h - l) / 2 + l;
  int64_t test = TestTime(b, N, m);
  if (test <= 0)
    return FindTime(b, N, l, m);
  return FindTime(b, N, m, h);
}

int Solve(const vector<int> &b, int N) {
  int64_t T = FindTime(b, N, 0, int64_t(1000000) * int64_t(1000000000)) - 1;

  int64_t a = N - CountT(b, T - 1);
  for (int i = 0; i < b.size(); i++) {
    if (T % b[i] != 0)
      continue;
    a--;
    if (a <= 0)
      return i + 1;
  }
  T++;
  for (int i = 0; i < b.size(); i++) {
    if (T % b[i] != 0)
      continue;
    a--;
    if (a <= 0)
      return i + 1;
  }
  assert(false);
}

int main(void) {
  int T;
  cin >> T;
  for (int TT = 0; TT < T; TT++) {
    int B, N;
    cin >> B >> N;
    vector<int> b;
    b.reserve(B);
    while (B--) {
      int t;
      cin >> t;
      b.push_back(t);
    }

    //    assert(Naive(b, N) == Solve(b, N));
    cout << "Case #" << TT + 1 << ": " << Solve(b, N) << endl;
  }
  return 0;
}
