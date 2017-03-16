#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int run_1(const vector<int>& a) {
  int eaten = 0;
  for (int i = 1; i < a.size(); i++) {
    if (a[i] < a[i - 1]) {
      eaten += a[i - 1] - a[i];
    }
  }
  return eaten;
}

int run_2(const vector<int>& a) {
  int rate = 0;
  for (int i = 1; i < a.size(); i++) {
    if (a[i] < a[i - 1]) {
      rate = max(rate, a[i - 1] - a[i]);
    }
  }
  int eaten = 0;
  for (int i = 1; i < a.size(); i++) {
    eaten += min(rate, a[i - 1]);
  }
  return eaten;
}

string run() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  ostringstream oss;
  oss << run_1(a) << " " << run_2(a);
  return oss.str();
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << run() << endl;
  }
}
