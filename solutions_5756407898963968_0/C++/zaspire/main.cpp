#include <gmpxx.h>
#include <gtk/gtk.h>
#include <cairo.h>

#include "shelly.hpp"

using namespace std;
using namespace shelly;

int main(int argc, char **argv) {
  freopen("input.txt", "r", stdin);
  gtk_init(&argc, &argv);

  int T;
  cin >> T;
  for (int TT = 1; TT <= T; TT++) {
    int a1, a2;
    cin >> a1;
    vector<vector<int>> board1(4, vector<int>(4)), board2(4, vector<int>(4));
    for (size_t i = 0; i < 4; i++) {
      for (size_t k = 0; k < 4; k++) {
        int t;
        cin >> t;
        board1[i][k] = t;
      }
    }
    cin >> a2;
    for (size_t i = 0; i < 4; i++) {
      for (size_t k = 0; k < 4; k++) {
        int t;
        cin >> t;
        board2[i][k] = t;
      }
    }
    a1--;
    a2--;

    sort(board1[a1].begin(), board1[a1].end());
    sort(board2[a2].begin(), board2[a2].end());
    vector<int> res;
    set_intersection(board1[a1].begin(), board1[a1].end(), board2[a2].begin(), board2[a2].end(), back_inserter(res));
    if (res.size() > 1)
      cout << "Case #" << TT <<": " <<  "Bad magician!" << endl;
    else if (res.size() == 1)
      cout << "Case #" << TT <<": " <<  res[0] << endl;
    else
      cout << "Case #" << TT <<": " <<  "Volunteer cheated!" << endl;
  }
  return 0;
}
