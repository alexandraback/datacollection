#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> read_sorted_row()
{
  int r;
  vector<int> ret;
  cin >> r;
  for (int i = 1; i <= 4; i++) {
    for (int j = 0; j < 4 ; j++) {
      int x;
      cin >> x;
      if (i == r) ret.push_back(x);
    }
  }
  sort(ret.begin(), ret.end());
  return ret;
}

int main()
{
  int test_case;
  cin >> test_case;
  for (int t = 1; t <= test_case; t++) {
    vector<int> r1 = read_sorted_row(), r2 = read_sorted_row(), res(4);
    auto it = set_intersection(r1.begin(), r1.end(), r2.begin(), r2.end(), res.begin());
    cout << "Case #" << t << ": ";
    if (it == res.begin()) {
      cout << "Volunteer cheated!" << endl;
    } else if (it > res.begin() + 1) {
      cout << "Bad magician!" << endl;
    } else {
      cout << res[0] << endl;
    }
  }

  return 0;
}
