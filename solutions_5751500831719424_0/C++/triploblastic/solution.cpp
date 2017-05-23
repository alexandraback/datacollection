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
int comp(int j, int i)
{
  int ii = 0, jj = 0, ret = 0;
  while(ii < s[i].SZ && jj < s[j].SZ) {
    if(s[j][jj] != s[i][ii])
      return -1;

    int cnti = 1, cntj = 1;
    while(ii < (int)s[i].SZ - 1) {
      if(s[i][ii] != s[i][ii+1])
        break;
      cnti++;
      ii++;
    }
    while(jj < (int)s[j].SZ - 1) {
      if(s[j][jj] != s[j][jj+1])
        break;
      cntj++;
      jj++;
    }

    ret += abs(cnti - cntj);
    i = ii+1;
    j = jj+1;
  }

  return ret;
}

int main()
{
  READ("A-small-attempt1.in");
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
    if(v[0].SZ != v[1].SZ)
      pos = false;
    REP(i, v[0].SZ) {
      int tmp = v[0][i].Fr;
      if(!pos)
        break;
      REP(j, n) {
        if(i >= v[j].SZ) {
          pos = false;
          break;
        }
        if(v[0][i].Sc != v[j][i].Sc) {
          pos = false;
          break;
        }
        tmp = min(tmp, v[j][i].Fr);
      }
      if(!pos)
        break;

      REP(j, n) {
        ret += abs(tmp - v[j][i].Fr);
      }
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
