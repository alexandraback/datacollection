#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  auto fstb = vector<vector<int>>(16, vector<int>(16));
  auto sndb = vector<vector<int>>(16, vector<int>(16));

  int tests;
  cin >> tests;
  for (int t = 0; t < tests; t++) {
    int first, second;
    cin >> first; first--;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        cin >> fstb[i][j];
    cin >> second; second--;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        cin >> sndb[i][j];
    vector<int> good;
    for (int i = 0; i < 4; i++)
      for (int j = 0; j < 4; j++)
        if (fstb[first][i] == sndb[second][j])
          good.push_back(fstb[first][i]);
    cout << "Case #" << (t + 1) << ": ";
    if (good.size() == 0)
      cout << "Volunteer cheated!";
    else if (good.size() > 1)
      cout << "Bad magician!";
    else
      cout << good.front();
    cout << '\n';
  }
    
}
