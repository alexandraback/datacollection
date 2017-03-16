#include <stdio.h>
#include <string.h>
#include <limits.h>

#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>

#include <math.h>

#define DBG(a,...)
//#define DBG printf

using namespace std;

char sv[101][101];
int id[101];
int pos[101];
int siz[101];

int main()
{
  int tn;
  int v = scanf("%d",&tn);
  (void)v;

  int ti = 1;
  while(tn) {

    bool imp = false;

    int N;

    v = scanf("%d",&N);

    DBG("%d\n",N);

    memset(sv, 0, sizeof(sv));
    memset(pos, 0, sizeof(pos));
    memset(id, 0, sizeof(id));
    memset(siz, 0, sizeof(siz));

    int n;
    for (n = 0; n < N; n++) {
      int res = scanf("%s", sv[n]);
      (void)res;
      siz[n] = strlen(sv[n]);
    }
    
    for (n = 0; n < N; n++) {
      DBG("[%d]%s len %d\n", n, sv[n], siz[n]);
    }

    // scan line algo
    int totOp = 0;
    bool all_done = false;
    while (!all_done) {

      // check not out of bounds
      for (n = 0; n < N; n++) {
        if (siz[n] <= pos[n]) {
          imp = true;
          DBG("SIZE!!\n");
          goto _imposs;
        }
      }      

      // check sanity, all same first char
      char c = sv[0][ pos[0] ];
      for (n = 1; n < N; n++) {
        if (sv[n][ pos[n] ] != c) {
          imp = true;
          DBG("CHAR!! %c != %c\n", c, sv[n][ pos[n] ]);
          goto _imposs;
        }
      }

      for (n = 0; n < N; n++) {
        // calc identical
        char *s = sv[n];
        int p = pos[n];
        char c = s[ p ];
        id[ n ] = 0;
        while (s[ p ] == c) {
          id[ n ]++;
          p++;
        }
      }

      // ok check which to pro-long and to cut
      int n1,n2;
      int minOp = 99999;
      for (n1 = 0; n1 < N; n1++) {
        int corr = id[ n1 ];
        int op = 0;
        for (n2 = 0; n2 < N; n2++) {
          if (n2 == n1) {
            continue; // dont count itslef
          }
          if ( id[ n2 ] < corr ) {
            op += (corr - id[ n2 ]);
          }
          else {
            op += (id[ n2 ] - corr);
          }
        }
        if (op < minOp) {
          minOp = op;
        }
      }

      totOp += minOp;

      // 2. jump to next char
      for (n = 0; n < N; n++) {
        pos[n] += id[ n ];
      }

      // 3. check if all done...
      bool all_end = true;
      for (n = 0; n < N; n++) {
        if (pos[n] != siz[n]) {
          all_end = false;
          break;
        }
      }
      if (all_end) {
        all_done = true;
        imp = false;
      }

    }

 _imposs:

    if (imp) {
      printf("Case #%d: Fegla Won\n", ti);
    }
    else {
      printf("Case #%d: %d\n", ti, totOp);
    }

    ti++;
    tn--;
  }

  return 0;
}
