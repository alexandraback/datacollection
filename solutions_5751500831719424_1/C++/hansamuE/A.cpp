#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
#include <cstdlib>

int main() {
  int t, n, it[100], c[100];
  std::string s[100];
  scanf("%d", &t);
  for (int cn = 1; cn <= t; cn++) {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      std::cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
      it[i] = 0;
    }
    bool end = false;
    int time = 0;
    while (!end) {
      if (s[0][it[0]] == '\0') {
        end = true;
        for (int i = 1; i < n; i++) {
          if (s[i][it[i]] != '\0') {
            time = -1;
            break;
          }
        }
        break;
      }
      for (int i = 0; i < n; i++) {
        c[i] = 1;
        if (i > 0) {
          if (s[i][it[i]] != s[i - 1][it[i - 1]]) {
            time = -1;
            end = true;
            break;
          }
        }
        while (s[i][it[i] + 1] == s[i][it[i]]) {
          it[i]++;
          c[i]++;
        }
      }
      if (end) {
        break;
      }
      int max = 0, min = 101, sum = 100000;
      for (int i = 0; i < n; i++) {
        max = std::max(max, c[i]);
        min = std::min(min, c[i]);
        it[i]++;
      }
      for (int i = min; i <= max; i++) {
        int dif = 0;
        for (int j = 0; j < n; j++) {
          dif += abs(i - c[j]);
        }
        sum = std::min(sum, dif);
      }
      time += sum;
    }
    printf("Case #%d: ", cn);
    if (time == -1) {
      printf("Fegla Won\n");
    } else {
      printf("%d\n", time);
    }
  }
  return 0;
}
