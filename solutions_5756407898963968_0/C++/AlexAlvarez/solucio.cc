#include <iostream>
#include <vector>
using namespace std;

int M[4][4];

vector<int> select() {
  int f;
  cin >> f;
  for (int i = 0; i < 4; ++i) for (int j = 0; j < 4; ++j) cin >> M[i][j];
  vector<int> res;
  for (int i = 0; i < 4; ++i) res.push_back(M[f - 1][i]);
  return res;
}

void solve() {
  vector<int> v1 = select();
  vector<int> v2 = select();
  vector<int> res;
  for (int i = 0; i < v1.size(); ++i) {
    for (int j = 0; j < v2.size(); ++j) {
      if (v2[j] == v1[i]) {
        res.push_back(v1[i]);
        break;
      }
    }
  }
  if (res.empty()) cout << "Volunteer cheated!" << endl;
  else if (res.size() > 1) cout << "Bad magician!" << endl;
  else cout << res.back() << endl;
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": ";
    solve();
  }
}
