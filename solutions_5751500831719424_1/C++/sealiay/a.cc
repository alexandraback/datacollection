
#include <algorithm>
#include <cstdio>

using namespace std;

int n;
char b[120][120];
char *s[120];
char l;
int a;


void p() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", b[i]);
    s[i] = b[i];
  }
  l = '.';
  a = 0;
  while ( true ) {
    char c = *s[0];
    bool e = true;
    for (int i = 1; i < n && e; ++i) {
      e = *s[i] == c;
    }
    if ( e ) {
      if ( c == '\0' ) {
        printf("%d", a);
        return;
      }
      else {
        l = c;
        for (int i = 0; i < n; ++i) ++s[i];
      }
    } else {
      int q = 0;
      char d = '.';
      for (int i = 0; i < n; ++i) {
        if ( *s[i] != l ) {
          if ( d == '.' ) d = *s[i];
          else if ( d != *s[i] ) {
            printf("Fegla Won");
            return;
          }
        } else {
          ++q;
          ++s[i];
        }
      }
      a += min(q, n-q);
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; ++i) {
    printf("Case #%d: ", i);
    p();
    printf("\n");
  }
  return 0;
}
