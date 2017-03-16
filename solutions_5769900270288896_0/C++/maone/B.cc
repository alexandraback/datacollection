#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N, R, C;

int calc(int n, int a, int b, int a0, int b0 = 0) {
  if (n <= a) return 0;
  n -= a;

  if (n <= b0) return n;
  int res = 1 * b0;
  n -= b0;

  if (n <= b) return res + 2 * n;
  res += 2 * b;
  n -= b;

  int c = (R + C) * 2 - 4 - (a - a0) - b;
  if (n <= c) return res + 3 * n;
  res += 3 * c;
  n -= c;

  return res + n * 4;
}

int go() {
  if (R == 1 || C == 1) {
    return calc(N, (R * C + 1) >> 1, (R * C - 1) >> 1, 0, 1 - (R & C & 1));
  } else if (R & C & 1) {
    int a = calc(N, (R * C + 1) >> 1, 0, ((R - 1) * (C - 1) + 1) >> 1);
    int b = calc(N, (R * C - 1) >> 1, 4, ((R - 1) * (C - 1) - 1) >> 1);
    return min(a, b);
  } else {
    return calc(N, (R * C) >> 1, 2, ((R - 1) * (C - 1)) >> 1);
  }
}

int main(int argc, const char* argv[]) {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> C >> R >> N;
    cout << "Case #" << t + 1 << ": " << go() << endl;
  }
}
