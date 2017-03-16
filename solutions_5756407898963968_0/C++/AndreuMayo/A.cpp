#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
  int cases;
  cin >> cases;
  for (int cas = 1; cas <= cases; ++cas) {
    cout << "Case #" << cas << ": ";
    int a;
    cin >> a;
    --a;
    int m[4][4];
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        cin >> m[i][j];
      }
    }
    set<int> pa;
    for (int j = 0; j < 4; ++j) pa.insert(m[a][j]);
    
    cin >> a;
    --a;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        cin >> m[i][j];
      }
    }
    
    int total = 0;
    int element;
    for (int j = 0; j < 4; ++j) if (pa.count(m[a][j])) {
      ++total;
      element = m[a][j];
    }
    if (total == 1) cout << element << endl;
    else if (total == 0) cout << "Volunteer cheated!" << endl;
    else cout << "Bad magician!" << endl;
  }
}
