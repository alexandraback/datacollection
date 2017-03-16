#include <iostream>
#include <cstring>

using namespace std;

int A[17], n = 4;

void oper(int row) {
  int x;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      cin >> x;
      if (i == row)
        ++A[x];
    }
}

int main() {
  ios::sync_with_stdio(0);
  int tc, row;
  cin >> tc;
  for (int caso = 1; caso <= tc; ++caso) {
    cout << "Case #" << caso << ": ";
    memset(A, 0, sizeof A);
    cin >> row;
    oper(row-1);
    cin >> row;
    oper(row-1);
    int cnt = 0, id;
    for (int i = 1; i < 17; ++i)
      if (A[i] == 2) {
        id = i;
        ++cnt;
      }
    if (cnt == 1)
      cout << id;
    else if (cnt > 1)
      cout << "Bad magician!";
    else
      cout << "Volunteer cheated!";
    cout << endl;
  }
}

