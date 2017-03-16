#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Vi;

int main() {
  int tcas;
  cin >> tcas;
  for (int cas = 1; cas <= tcas; ++cas) {
    Vi v(16, 0);
    for (int k = 0; k < 2; ++k) {
      int r;
      cin >> r;
      --r;
      for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j) {
          int x;
          cin >> x;
          --x;
          if (i == r) ++v[x];
        }
    }
    int c = 0, n = 0;
    for (int i = 0; i < 16; ++i)
      if (v[i] == 2) {
        ++c;
        n = i;
      }
    cout << "Case #" << cas << ": ";
    if (c == 0) cout << "Volunteer cheated!" << endl;
    else if (c == 1) cout << n + 1 << endl;
    else cout << "Bad magician!" << endl;
  }
}
