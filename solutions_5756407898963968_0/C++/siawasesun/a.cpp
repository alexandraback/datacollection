#include <bits/stdc++.h>

using namespace std;

int firstSquare[4][4];
int secondSquare[4][4];
int firstRow, secondRow;

void Input() {
  scanf("%d", &firstRow);
  for (int y = 0; y < 4; ++y) for (int x = 0; x < 4; ++x) scanf("%d", &firstSquare[y][x]);
  scanf("%d", &secondRow);
  for (int y = 0; y < 4; ++y) for (int x = 0; x < 4; ++x) scanf("%d", &secondSquare[y][x]);

  firstRow--;
  secondRow--;
}

void Solve() {
  set<int> s1, s2;
  for (int x = 0; x < 4; ++x) {
    s1.insert(firstSquare[firstRow][x]);
    s2.insert(secondSquare[secondRow][x]);
  }

  set<int> intersect;
  std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(),
                        std::inserter(intersect, intersect.begin()));

  if (intersect.size() == 0) {
    printf("Volunteer cheated!");
  } else if (intersect.size() > 1) {
    printf("Bad magician!");
  } else {
    printf("%d", *intersect.begin());
  }
}

int main(int argc, char **argv) {
  int T;
  scanf("%d", &T);

  for (int test_case = 1; test_case <= T; ++test_case) {
    Input();
    printf("Case #%d: ", test_case);
    Solve();
    printf("\n");
  }
  return 0;
}
