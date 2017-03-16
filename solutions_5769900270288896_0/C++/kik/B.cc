#include <iostream>

using namespace std;

int main()
{
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; cas++) {
    int R, C, N;
    cin >> R >> C >> N;
    int m = R * C;
    int min = 100000;
    for (unsigned int i = 0; i < (1 << m); i++) {
      int x = __builtin_popcount(i);
      if (x != N) continue;
      int v = 0;
      for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
          if (r + 1 < R) {
            if ((i & (1 << (r + c * R))) &&
                (i & (1 << (r + 1 + c * R)))) {
              v++;
            }
          }
          if (c + 1 < C) {
            if ((i & (1 << (r + c * R))) &&
                (i & (1 << (r + (c + 1) * R)))) {
              v++;
            }
          }
        }
      }
      if (v < min) min = v;
    }
    cout << "Case #" << cas << ": " << min << endl;
  }
  return 0;
}
