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
#define elsif else if
#define all(a) (a).begin(), (a).end()
#define sz(a) ((int)(a).size())

using namespace std;

int a[4][4], b[4][4];
int r, c;

inline int readInt() {
  int res;
  scanf("%d", &res);
  return res;
}

void clear() {
}

void read() {
  r = readInt() - 1;
  fori(i,0,4)
    fori(j,0,4)
      a[i][j] = readInt();

  c = readInt() - 1;
  fori(i,0,4)
    fori(j,0,4)
      b[i][j] = readInt();
}

void solve() {
  set<int> first, second;
  fori(j,0,4)
    first.add(a[r][j]);
  fori(j,0,4)
    second.add(b[c][j]);
  set<int> res;
  set_intersection(all(first), all(second), inserter(res, res.begin()));
  if (sz(res) == 0)
    printf("Volunteer cheated!");
  elsif (sz(res) > 1)
    printf("Bad magician!");
  else
    printf("%d", *res.begin());
  printf("\n");
}

int main() {
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  srand(time(0));
  int N;
  scanf("%d", &N);
  fori(T,1,N+1) {
    clear();
    read();
    printf("Case #%d: ", T);
    solve();
  }
}
