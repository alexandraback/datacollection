#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>

#define FOR(i,k,n) for (int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define sz size()
#define pb push_back
#define mp make_pair
#define ALL(X) (X).begin(),(X).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;

void output(int c, int n) { printf ("Case #%d: %d\n", c, n); }
void output(int c, string s) { printf ("Case #%d: %s\n", c, s.c_str()); }

int a[4][4];

int main(void)
{
  int t, x;
  cin >> t;
  REP(c,t) {
    vector<int> v(17);
    cin >> x;
    REP(i,4)REP(j,4) cin >> a[i][j];
    REP(i,4) v[a[x-1][i]]++;
    cin >> x;
    REP(i,4)REP(j,4) cin >> a[i][j];
    REP(i,4) v[a[x-1][i]]++;
    int res = -1;
    REP(i,17) {
      if (v[i] == 2) {
        if (res == -1) res = i;
        else if (res != -2) res = -2;
      }
    }
    if (res == -1) output(c+1, "Volunteer cheated!");
    else if (res == -2) output(c+1, "Bad magician!");
    else output(c+1, res);
  }
  return 0;
}
