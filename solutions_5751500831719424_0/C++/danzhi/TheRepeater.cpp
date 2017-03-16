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
#include <hash_map>
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
#define debug(x) cerr<<#x<<" = "<<(x)<<endl;
bool test = false;
const double pi=acos(-1.0);
const double eps=1e-11;
int breakpoint = 0;

const char rootdir[] = "C:\\CodeJam\\TheRepeater";
void reopen(char* a) {
	char input[256], output[256];
	sprintf(input, "%s\\%s", rootdir, a);
	sprintf(output, "%s\\%s", rootdir, a);
	char *p = strstr(output, ".in");
	if (p) sprintf(p, ".out"); 
	else sprintf(&p[strlen(output)], ".out");
	debug(input);
	debug(output);
	freopen(input,"r",stdin);
	if (!test) freopen(output,"w",stdout);
}

int T;
int N = 0;
char buf[110][110];

void showin() {
  if (!test) return;
  printf("%d\n", N);
  for (int i = 0; i < N; i++) {
    printf("%s\n", buf[i]);
  }
}

void solve(int t) {
  vector<int> counts[110];
  vector<char> letters[110];
  for (int i = 0; i < N; i++) {
    assert(strlen(buf[i]) > 0);
    char *p = &buf[i][1];
    char prev = buf[i][0];
    int cnt = 1;
    while (*p != 0) {
      if (*p == prev) {
        cnt++;
      } else {
        counts[i].push_back(cnt);
        letters[i].push_back(prev);
        // printf("counts[%d]<-%d\n", i, cnt);
        prev = *p;
        cnt = 1;
      }
      p++;
    }
    counts[i].push_back(cnt);
    letters[i].push_back(prev);
    // printf("counts[%d]<-%d\n", i, cnt);
  }
  if (test) {
    for (int i = 0; i < N; i++) {
      printf("counts[%d] : ", i);
      for (int j = 0; j < counts[i].size(); j++) {
        printf("%d ", counts[i][j]);
      }
      printf("\n");
    }
  }
  int ulen = counts[0].size();
  for (int i = 1; i < N; i++) {
    if (counts[i].size() != ulen) {
      printf("Case #%d: Fegla Won\n", t);
      return;
    }
    for (int j = 0; j < ulen; j++) {
      if (letters[i][j] != letters[0][j]) {
        printf("Case #%d: Fegla Won\n", t);
        return;
      }
    }
  }
  int m = N >> 1;
  int steps = 0;
  for (int j = 0; j < ulen; j++) {
    vector<int> cts;
    for (int i = 0; i < N; i++) {
      cts.push_back(counts[i][j]);
    }
    std::sort(cts.begin(), cts.end());
    for (int i = 0; i < N; i++) {
      steps += abs(counts[i][j] - cts[m]);
    }
  }
  printf("Case #%d: %d\n", t, steps);
}

int main() {
  // test = true;
  // reopen("sample.in");
  reopen("A-small-attempt1.in");
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      scanf("%s", &buf[i]);
    }
    showin();
    solve(t);
  }
  return 0;
}