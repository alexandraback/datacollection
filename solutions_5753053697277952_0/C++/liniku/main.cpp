#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int N;
vector<int> p;

void input() {
  cin >> N;
  p.resize(N);
  for (int i = 0; i < N; ++i) {
    cin >> p[i];
  }
}

int step() {
  int a = 0;
  int b = 0;
  int c1 = -1;
  int c2 = -1;

  for (int i = 0; i < N; ++i) {
    if (a < p[i]) {
      a = p[i];
      b = 1;
      c1 = i;
    } else if (a == p[i]) {
      ++b;
      c2 = i;
    }
  }

  if (b == 1) {
    --p[c1];
    cout << (char)('A' + c1);
    return 1;
  } else if (b == 2) {
    --p[c1];
    --p[c2];
    cout << (char)('A' + c1) << (char)('A' + c2);
    return 2;
  } else if (b > 2) {
    --p[c2];
    cout << (char)('A' + c2);
    return 1;
  }
  return 0;
}

void solve() {
  int s = 0;
  for (int i = 0; i < N; ++i) {
    s += p[i];
  }

  while (s) {
    cout << " ";
    s -= step();
  }
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    cout << "Case #" << i + 1 << ":";
    input();
    solve();
  }
  return 0;
}
