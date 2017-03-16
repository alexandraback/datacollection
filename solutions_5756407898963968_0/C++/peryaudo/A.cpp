#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> GetRow() {
  vector<int> row;
  for (int i = 0; i < 4; ++i) {
    int cur;
    scanf("%d", &cur);
    row.push_back(cur);
  }
  return row;
}

vector<int> GetRows() {
  int ans;
  scanf("%d\n", &ans);
  vector<int> row;
  for (int i = 0; i < 4; ++i) {
    vector<int> cur = GetRow();
    if (i == ans - 1)
      row = cur;
  }
  return row;
}

int main() {
  int t;
  scanf("%d\n", &t);

  for (int i = 0; i < t; ++i) {
    vector<int> row_a = GetRows();
    vector<int> row_b = GetRows();
    sort(row_a.begin(), row_a.end());
    sort(row_b.begin(), row_b.end());
    vector<int> united(4);
    united.resize(
        set_intersection(row_a.begin(), row_a.end(),
                         row_b.begin(), row_b.end(), united.begin())
        - united.begin());
    printf("Case #%d: ", i + 1);
    if (united.size() == 0) {
      printf("Volunteer cheated!\n");
    } else if (united.size() > 1) {
      printf("Bad magician!\n");
    } else {
      printf("%d\n", united[0]);
    }
  }

  return 0;
}
