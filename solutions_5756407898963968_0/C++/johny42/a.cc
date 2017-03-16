#include <iostream>
using namespace std;

int main() {
  bool cards[17];

  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt) {
    for (int i = 1; i <= 16; ++i) cards[i] = true;

    int row;

    for (int i = 0; i < 2; ++i) {
      cin >> row;
      for (int r = 1; r <= 4; ++r) {
        for (int c = 1; c <= 4; ++c) {
          int card;
          cin >> card;
          if (r != row) cards[card] = false;
        }
      }
    }

    int cnt = 0, res;
    for (int i = 1; i <= 16; ++i) {
      if (cards[i]) {
        ++cnt;
        res = i;
      }
    }

    cout << "Case #" << tt << ": ";

    if (cnt == 0) {
      cout << "Volunteer cheated!" << endl;
    } else if (cnt > 1) {
      cout << "Bad magician!" << endl;
    } else {
      cout << res << endl;
    }
  }
}
