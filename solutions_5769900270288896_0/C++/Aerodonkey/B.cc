#include <iostream>

int Search(int r, int c, int n) {
  int s = r * c;
  int u = 2 * s;
  for (int m = 0; m < (1 << s); m++) {
    int b = 0;
    for (int i = 0; i < s; i++) {
      if (m & (1 << i)) {
        b++;
      }
    }
    if (b != n) {
      continue;
    }
    int v = 0;
    for (int x = 0; x < r - 1; x++) {
      for (int y = 0; y < c; y++) {
        if ((m & (1 << (x * c + y))) && (m & (1 << (x * c + c + y)))) {
          v++;
        }
      }
    }
    for (int y = 0; y < c - 1; y++) {
      for (int x = 0; x < r; x++) {
        if ((m & (1 << (x * c + y))) && (m & (1 << (x * c + y + 1)))) {
          v++;
        }
      }
    }
    if (v < u) {
      u = v;
    }
  }
  return u;
}

int main() {
  int t;
  std::cin >> t;
  for (int i = 0; i < t; i++) {
    int r, c, n;
    std::cin >> r >> c >> n;
    int u = Search(r, c, n);
    std::cout << "Case #" << i + 1 << ": " << u << std::endl;
  }
}
