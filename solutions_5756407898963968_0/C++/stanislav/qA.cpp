#include <algorithm>
#include <array>
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

using namespace std;

int readNum() {
  int num;
  cin >> num;
  return num;
}

typedef array<array<int, 4>, 4> Array;
Array readArr() {
  Array arr;
  for (int r = 0; r < 4; r++) {
    for (int c = 0; c < 4; c++) {
      cin >> arr[r][c];
    }
  }
  return arr;
}

void run(int t) {
  int ans1 = readNum();
  Array grid1 = readArr();
  array<int, 4> row1 = grid1[ans1 - 1];
  int ans2 = readNum();
  Array grid2 = readArr();
  array<int, 4> row2 = grid2[ans2 - 1];

  vector<int> nums;
  sort(row1.begin(), row1.end());
  sort(row2.begin(), row2.end());
  set_intersection(
    row1.begin(), row1.end(), row2.begin(), row2.end(), back_inserter(nums));

  if (nums.size() == 0) {
    cout << "Case #" << t << ": Volunteer cheated!" << endl;
  } else if (nums.size() > 1) {
    cout << "Case #" << t << ": Bad magician!" << endl;
  } else {
    cout << "Case #" << t << ": " << nums[0] << endl;
  }
}

int main() {
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    run(t);
  }
}
