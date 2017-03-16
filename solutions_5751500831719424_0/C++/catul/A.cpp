#define DBGn

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <algorithm>
#include <iterator>
#include <utility>
using namespace std;
#include <cstring>

typedef vector<int>          vint;
typedef vector<unsigned int> vuint;
typedef vector<string>       vstr;
typedef long long            ll;
typedef unsigned long long   ull;
typedef pair<int, int>       pii;

#define FORN(i,n) for (int (i) = 0; (i) < (n); (i)++)
#define FE  (i,x) for (typeof((x).begin()) (i) = (x).begin(); (i) != (x).end(); (i)++)

#define PB push_back
#define MP make_pair
#define A  first
#define B  second

ostream& operator<<(ostream& os, const vector<int> keys) {
  vector<int>::size_type sz = keys.size();
  for (unsigned int i = 0; i < sz; i++)
    os << keys[i] << " ";
  os << endl;
  return os;
}

void disp_table(int table[101][101], int N, int M) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++)
      printf("%d ", table[i][j]);
    printf("\n");
  }
  printf("\n");
}



int main() {
  int T, num=1;

  for (cin >> T; T--;) {
    int N;
    char s[101][101]; // max 100 strings of 100 chars
    cin >> N;
    FORN(i,N) cin >> s[i];

#ifdef DBG
    FORN(i,N) printf("[%d] %s\n", i, s[i]);
#endif

    // Browse all strings in parallel starting with the first char and find how many of it
    // each string has. If at any point one of the string doesn't have the character, it's over.
    int nb[101][101]; // max 100 strings, max 100 different characters
    int diff;         // number of different characters found
    int pos[101];     // position in each string
    char c;           // current character
    ll total = 0;

    memset(nb,0,sizeof(nb));
    memset(pos,0,sizeof(pos));
    diff = 0;

    while(1) {
      c = s[0][ pos[0] ];  // current char in first string, might be '\0'
      if (c == 0) {
        // Check that all strings are finished, otherwise it's lost
        FORN(i,N) {
          if (s[i][pos[i]] != c) {
#ifdef DBG
            printf("String '%s' not finished at pos %d\n", s[i], pos[i]);
#endif
            goto lose;
          }
        }
        // If all strings are finished at the same time, we're good.
        break;
      }

      // Count occurrences of "c" in each string at current position
      FORN(i,N) {
        int k;

        for (k = pos[i]; s[i][k] == c; k++); // no need to check for bounds, the strings are null-terminated
        nb[i][diff] = k - pos[i];
        if (nb[i][diff] == 0) { // this char has not been found in this string
#ifdef DBG
          printf("Character '%c' not found in string '%s' starting at pos %d\n", c, s[i], pos[i]);
#endif
          goto lose;
        } else {
#ifdef DBG
          printf("Character '%c' found %d times in string '%s' starting at pos %d\n", c, nb[i][diff], s[i], pos[i]);
#endif
          pos[i] = k;
        }

      }

      diff++; // next char
    }


#ifdef DBG
    disp_table(nb, N, diff);
#endif

    // For each character in the table nb[0..diff-1]:
    // - calculate min and max
    // - for each value between min and max, calculate total delta to bring all values to it
    // - pick the minimum
    // Add all those values
    FORN(i, diff) {
      ll min_delta = -1;
      int min_val = -1;
      int max_val = -1;
      int n;
      FORN(j, N) {
        n = nb[j][i];
        if (n < min_val || min_val == -1) min_val = n;
        if (n > max_val || max_val == -1) max_val = n;
      }

      for (int k = min_val; k <= max_val; k++) {
        ll delta = 0;
        FORN(j,N) {
          delta += abs(nb[j][i] - k);
        }
        if (min_delta == -1 || delta < min_delta)
          min_delta = delta;
      }

      total += min_delta;
    }

    printf("Case #%d: %llu\n", num++, total);
    continue;

lose:
    printf("Case #%d: Fegla Won\n", num++);
  }


}
