#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <bitset>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <functional>
#include <unordered_map>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <list>
#include <deque>
#include <queue>
#include <math.h>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <stdio.h>
#include <string>
#include <sstream>
#include <utility>
#include <vector>

using namespace std;
bool test = false;
const double pi = acos(-1.0);
const double eps = 1e-11;
int breakpoint = 0;

const char rootdir[] = "C:\\CodeJam\\SenateEvacuation";
void reopen(char* a) {
  char input[256], output[256];
  sprintf(input, "%s\\%s", rootdir, a);
  sprintf(output, "%s\\%s", rootdir, a);
  char *p = strstr(output, ".in");
  if (p) sprintf(p, ".out");
  else sprintf(&p[strlen(output)], ".out");
  freopen(input, "r", stdin);
  if (!test) freopen(output, "w", stdout);
}

int N;
int P[32];

bool ok(int total) {
  int half = total >> 1;
  for (int k = 0; k < N; k++) {
    if (P[k] > half) return false;
  }
  return true;
}

void solve(int t) {
  printf("Case #%d: ", t);
  int total = 0;
  for (int i = 0; i < N; i++) total += P[i];

  while (total > 0) {
    bool found = false;
    for (int i = 0; i < N; i++) {
      if (P[i] == 0) continue;
      // consider (i,i)
      if (P[i] >= 2) {
        P[i] -= 2;
        if (ok(total - 2)) {
          printf("%c%c ", 'A' + i, 'A' + i);
          found = true;
          total -= 2;
          break;
        } else {
          P[i] += 2;
        }
      }
      if (found) break;

      P[i] -= 1;
      // consider (i,j)
      for (int j = i + 1; j < N; j++) {
        if (P[j] == 0) continue;
        P[j] -= 1;
        if (ok(total - 2)) {
          printf("%c%c ", 'A' + i, 'A' + j);
          found = true;
          total -= 2;
          break;
        } else {
          P[j] += 1;
        }
      }
      if (found) break;

      // consider i alone
      if (ok(total - 1)) {
        printf("%c ", 'A' + i);
        found = true;
        total -= 1;
      }
      if (found) break;
    }
    assert(found);
  }
  printf("\n");
}

int main() {
  // test = true;
  // reopen("sample.in");
  reopen("A-small-attempt0.in");
  // reopen("C-large-practice.in");

  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%d", &P[i]);
    }
    // if (test && qq != 47) continue;
    solve(qq);
  }
  return 0;
}
