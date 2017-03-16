#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
using namespace std;
using ll = long long;

class range {private: struct I{int x;int operator*(){return x;}bool operator!=(I& lhs){return x<lhs.x;}void operator++(){++x;}};I i,n;
public:range(int n):i({0}),n({n}){}range(int i,int n):i({i}),n({n}){}I& begin(){return i;}I& end(){return n;}};

void solve();

int main() {
  int T; cin >> T;
  for (int test : range(1, T+1)) {
    cout << "Case #" << test << ": ";
    solve();
  }
}

//=====

void solve() {
  int N; cin >> N;
  vector<int> v(N);
  for (int i : range(N)) cin >> v[i];

  int ret1 = 0, ret2 = 0;
  for (int i : range(1, N)) ret1 += max(0, v[i - 1] - v[i]);
  int rate = 0;
  for (int i : range(1, N)) rate = max(rate, v[i - 1] - v[i]);
  for (int i : range(1, N)) {
    ret2 += min(v[i - 1], rate);
  }

  cout << ret1 << " " << ret2 << endl;
}
