#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int R1; cin >> R1;
    int G[4][4];
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        cin >> G[i][j];
    set<int> row(G[R1-1], G[R1-1]+4);
    int R2; cin >> R2;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        cin >> G[i][j];

    int cand = -1;
    for (int i = 0; i < 4; i++)
      if (row.count(G[R2-1][i])) {
        if (cand != -1) {
          cand = -2;
          break;
        }
        cand = G[R2-1][i];
      }

    printf("Case #%d: ", t);
    if (cand == -1) {
      cout << "Volunteer cheated!" << endl;
    } else if (cand == -2) {
      cout << "Bad magician!" << endl;
    } else {
      cout << cand << endl;
    }
  }
}
