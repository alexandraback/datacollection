#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

#define fr(a,b,c) for (int a = b ; a < c; ++a)
#define db(x) cerr << #x " == " << x << endl
#define _ << ", " <<
#define sf(f, x) scanf("%"#f, &x)

typedef long long ll;

int cc(int k) {
  int r = 0;
  while(k) r += k&1, k >>= 1;
  return r;
}

int n,r,c;

int dd[4][2] = {{0,1}, {0,-1}, {1,0}, {-1, 0}};

int opa(int i, int j, int c) {
  return i*c + j;
}

void doit() {
  scanf("%d%d%d", &r, &c, &n);
  int m = r*c;
  int res = 10000000;
  fr(k,0,(1<<m)) {
    if (cc(k) == n) {
      int p = 0;
      fr(i,0,r) fr(j,0,c) if (k & (1<<(i*c+j))) fr(d,0,4) {
        int ii = i + dd[d][0];
        int jj = j + dd[d][1];
        if (ii < 0 || ii >= r || jj < 0 || jj >= c) continue;
        if (k & (1<<(ii * c + jj))) p++;
      }
      res = min(res, p / 2);
    }
  }
  printf("%d\n", res);
}

int main() {
  int t; sf(d, t);
  fr(i,0,t) {
    printf("Case #%d: ", i+1);
    doit();
  }
  return 0;
}