#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int T;
int N;
vector<string> v;
char buff[128];
int p[100];

bool check() {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (p[i] == (-1 + v[i].size())) {
      cnt++;
    }
  }
  return cnt == N;
}

int main() {
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &N);
    printf("Case #%d: ", t);

    v.resize(N);
    memset(p, 0, sizeof p);

    int max_size = 0;

    for (int i = 0; i < N; i++) {
      scanf("%s", buff);
      v[i] = string(buff);
    }

    char flag = 1;
    for (int i = 0; i < N; i++) {
      if (v[i][0] != v[0][0]) {
        flag = 0;
        break;
      }
    }

    if (flag == 0) {
      printf("Fegla won\n");
      continue;
    }

    int res = 0;
    while (!check()) {
      flag = 0;
      char next_char = 'a';
      // move with the same letter
      for (int i = 0; i < N; i++) {
        if (p[i] + 1 != v[i].size() && v[i][p[i]] == v[i][p[i] + 1]) {
          flag = 1;
          next_char = v[i][p[i]];
          break;
        }
      }

      if (flag == 0) {
        flag = 0;
        for (int i = 0; i < N; i++) {
          if (p[i] + 1 == v[i].size()) {
            flag = 1;
            break;
          }
          if (v[i][p[i] + 1] != v[0][p[0] + 1]) {
            flag = 1;
            break;
          }
        }
        if (flag) {
          res = -1;
          printf("Fegla Won\n");
          break;
        }
        for (int i = 0; i < N; i++) {
          p[i]++;
        }
        continue;
      }
      int add = 0;
      int rem = 0;

      for (int i = 0; i < N; i++) {
        if (p[i] + 1 == v[i].size()) {
          add++;
        } else {
          if (v[i][p[i] + 1] == next_char) {
            rem++;
          } else {
            add++;
          }
        }
      }
      if (rem == N) {
        for (int i = 0; i < N; i++) {
          p[i]++;
        }
        continue;
      } else {
        res += min(add, rem);
        for (int i = 0; i < N; i++) {
          if (p[i] + 1 != v[i].size() && v[i][p[i] + 1] == next_char) {
            p[i]++;
          }
        }
      }

    }
    if (res != -1) printf("%d\n", res);
  }

}
