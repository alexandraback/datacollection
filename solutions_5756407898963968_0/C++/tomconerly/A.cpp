#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]) {
  int T;
  cin >> T;
  for (int c = 1; c <= T; c++) {
    int r1, r2;
    vector<int> options;
    cin >> r1;
    int temp;
    for (int r = 1; r <= 4; r++) {
      for (int c = 1; c <= 4; c++) {
        cin >> temp;
        if (r == r1)
          options.push_back(temp);
      }
    }
    cin >> r2;
    vector<int> ans;
    for (int r = 1; r <= 4; r++) {
      for (int c = 1; c <= 4; c++) {
        cin >> temp;
        if (r == r2 &&
            find(options.begin(), options.end(), temp) != options.end()) {
          ans.push_back(temp);
        }
      }
    }
    cout << "Case #" << c << ": ";
    if (ans.size() == 0) {
      cout << "Volunteer cheated!" << endl; 
    } else if (ans.size() == 1) {
      cout << ans[0] << endl;
    } else {
      cout << "Bad magician!" << endl;
    }
  }
}
