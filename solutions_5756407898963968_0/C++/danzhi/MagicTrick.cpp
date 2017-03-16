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

const char rootdir[] = "C:\\CodeJam\\MagicTrick";
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

const int md = 1000002013;

int cost(int n, int len) {
  int a = n + (n - len + 1);
  int b = len;
  if (a % 2 == 0) a /= 2;
  else b /= 2;
  return (long long)a * b % md;
}

int T = 0;
int a[4][4];
int b[4][4];
int answer1;
int answer2;

void showin() {
  if (!test) return;
  printf("%d\n", answer1);
  for (int i = 0; i < 4; i++) {
    printf("%d %d %d %d\n", a[i][0], a[i][1], a[i][2], a[i][3]);
  }
  printf("%d\n", answer2);
  for (int i = 0; i < 4; i++) {
    printf("%d %d %d %d\n", b[i][0], b[i][1], b[i][2], b[i][3]);
  }
}

int main() {
  test = false;
  // reopen("sample.in");
  reopen("A-small-attempt0.in");
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &answer1);
    for (int i = 0; i < 4; i++) {
      scanf("%d %d %d %d", &a[i][0], &a[i][1], &a[i][2], &a[i][3]);
    }
    scanf("%d", &answer2);
    for (int i = 0; i < 4; i++) {
      scanf("%d %d %d %d", &b[i][0], &b[i][1], &b[i][2], &b[i][3]);
    }
    showin();
    assert(answer1 >= 1 && answer1 <= 4);
    assert(answer2 >= 1 && answer2 <= 4);
    int row1 = answer1-1;
    int row2 = answer2-1;
    int match = 0;  // number of values that match
    int value = 0;  // the (last) value that matches
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (a[row1][i] == b[row2][j]) {
          match++;
          value = a[row1][i];
        }
      }
    }
    printf("Case #%d: ", t);
    if (match == 0) {
      printf("Volunteer cheated!\n");
    } else if (match == 1) {
      printf("%d\n", value);
    } else {
      printf("Bad magician!\n");
    }
  }
  return 0;
}