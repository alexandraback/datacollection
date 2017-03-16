#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <sstream>
#include <set>
#include <utility>
#include <queue>
#include <cassert>
#include <ctime>
using namespace std;

#define PB push_back
#define SZ size()
#define all(v) v.begin(), v.end()
#define REP(i, n) for(int i = 0; i < (int)n; i++)
#define ITR(i, j, n) for(int i = j; i < (int)n; i++)
#define mem(array, val) memset(array, val, sizeof(array))
#define READ(filename) freopen(filename, "r", stdin)
#define WRITE(filename) freopen(filename, "w", stdout)
#define Pii pair <int, int>
#define Fr first
#define Sc second
#define Long long long
#define get(a) scanf("%d", &a)

string s[105];
int test, caseno = 1, n;

int main()
{
  READ("A-large.in");
  WRITE("answer.out");
  scanf("%d", &test);

  while(caseno <= test) {
    scanf("%d%*c", &n);
    REP(i, n)
      getline(cin, s[i]);

    vector < pair <int, char> > v[105];
    REP(i, n) {
      int j = 0;
      while(j < s[i].SZ) {
        int a = 1;
        while(j < (int)s[i].SZ - 1) {
          if(s[i][j] != s[i][j+1])
            break;
          a++;
          j++;
        }
        v[i].PB(make_pair(a, s[i][j]));
        j++;
      }
    }

    bool pos = true;
    int ret = 0;
    REP(i, n)
      if(v[i].SZ != v[0].SZ) {
        pos = false;
        break;
      }
    REP(i, v[0].SZ) {
      int tmp = v[0][i].Fr;
      if(!pos)
        break;
      REP(j, n) {
        if(v[0][i].Sc != v[j][i].Sc) {
          pos = false;
          break;
        }
      }
      if(!pos)
        break;

      int mi = 10000000;
      ITR(k, 1, 101) {
        int tmp = 0;
        REP(j, n)
          tmp += abs(v[j][i].Fr - k);
        mi = min(mi, tmp);
      }
      ret += mi;
    }
/*
    if(1) {
      REP(j, v[0].SZ) {
        if(v[0][j].Sc != v[1][j].Sc) {
          printf("1 ");
        }
      }
      puts("");
    }
*/
    printf("Case #%d: ", caseno++);
    if(pos)
      printf("%d\n", ret);
    else
      puts("Fegla Won");
  }
  return 0;
}
