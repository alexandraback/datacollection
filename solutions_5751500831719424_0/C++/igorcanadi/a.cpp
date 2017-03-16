#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

std::vector<std::string> rijeci;

void load() {
  char buf[128];
  int n;
  scanf("%d", &n);
  rijeci.resize(n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", buf);
    rijeci[i] = string(buf);
  }
}

int moves(std::vector<int>& r) {
  nth_element(r.begin(), r.begin() + r.size()/2, r.end());
  int target = r[r.size()/2];
  int sol = 0;
  for (int i = 0; i < r.size(); ++i) {
    sol += (r[i] < target) ? target - r[i] : r[i] - target;
  }
  return sol;
}

int solve() {
  int sol = 0;
  std::vector<int> indexes(rijeci.size(), 0);
  while (indexes[0] < rijeci[0].size()) {
    char slovo = rijeci[0][indexes[0]];
    std::vector<int> repeats(rijeci.size());
    for (int i = 0; i < rijeci.size(); ++i) {
      for ( ; indexes[i] < rijeci[i].size() && rijeci[i][indexes[i]] == slovo; ++indexes[i]) {
        repeats[i]++;
      }
      if (repeats[i] == 0)
        return -1;
    }

    sol += moves(repeats);
  }

  for (int i = 0; i < indexes.size(); ++i) {
    if (indexes[i] != rijeci[i].size()) return -1;
  }

  return sol;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int tt = 1; tt <= T; ++tt) {
    load();
    int sol = solve();
    printf("Case #%d: ", tt);
    if (sol == -1) {
      printf("Fegla Won\n");
    } else {
      printf("%d\n", sol);
    }
  }
  return 0;
}
