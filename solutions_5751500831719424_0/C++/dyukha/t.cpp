#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <set>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <ctime>
#include <algorithm>
#include <string>
//#include <>

#define fori(i,b,e) for (int i = (b); i < (e); i++)
#define mp make_pair
#define pb push_back
#define add insert
#define all(a) (a).begin(), (a).end()
#define elsif else if
#define sz(a) ((int)(a).size())

using namespace std;

inline int getInt() { int res;  scanf("%d", &res);  return res; }
inline double getDbl() { double res;  scanf("%lf", &res);  return res; }

char s[100][101];
char r[100][101];
int res[100][101];
int len[100], rLen[100];
int b[100];

int n;

void clear() {
}

void reduce(int i) {
  int n = strlen(s[i]);
  int prev = -1;
  int cur = 0;
  fori(j,0,n) {
    char c = s[i][j];
    if (c != prev) {
      r[i][cur] = c;
      prev = c;
      cur++;
    }
  }
  r[i][cur] = 0;
}

void read() {
  n = getInt();
  fori(i,0,n) {
    scanf("%s", s[i]);
    len[i] = strlen(s[i]);
    reduce(i);
    rLen[i] = strlen(r[i]);
  }
}

void solve() {
  fori(i,1,n) {
    if (rLen[i] != rLen[i-1]) {
      printf("Fegla Won\n");
      return;
    }
    fori(j,0,rLen[i]) {
      if (r[i][j] != r[i-1][j]) {
        printf("Fegla Won\n");
        return;
      }
    }
  }
  char *a = r[0];
  fori(i,0,n) {
    int cur = 0;
    int prev = 0;
    fori(j,0,rLen[i]) {
      while (cur < len[i] && a[j] == s[i][cur]) {
        cur++;
      }
      res[i][j] = cur - prev;
      prev = cur;
    }
  }
  int sum = 0;
  fori(j,0,rLen[0]) {
    fori(i,0,n) {
      b[i] = res[i][j];
    }
    sort(b, b+n);
    int v = b[n / 2];
    fori(i,0,n) {
      sum += abs(b[i] - v);
    }
  }
  printf("%d\n", sum);
}

int main() {
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  srand(time(0));
  int N = getInt();
  fori(T,1,N+1) {
    clear();
    read();
    printf("Case #%d: ", T);
    solve();
  }
}
