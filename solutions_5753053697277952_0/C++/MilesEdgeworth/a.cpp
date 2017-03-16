#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX_N = 30;
int num[MAX_N];
int T, N;

int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
      scanf("%d", num + i);
    }

    printf("Case #%d:", t);
    while (1) {
      vector<pair<int, int>> left;
      for (int i = 0; i < N; ++i) {
        if (num[i] != 0) left.push_back({-num[i], i});
      }
      sort(left.begin(), left.end());
      if (left.size() == 2) {
        printf(" %c%c", (char)(left[0].second + 'A'), (char)(left[1].second + 'A'));
        num[left[0].second]--;
        num[left[1].second]--;
      } else if (left.size() == 0) {
        printf("\n");
        break;
      } else {
        printf(" %c", (char)(left[0].second + 'A'));
        num[left[0].second]--;
      }
    }
  }
}
