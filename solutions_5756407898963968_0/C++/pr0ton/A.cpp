#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

#define s(x) scanf("%d", &x)

int c[17];

int main() {
  int cases;
  s(cases);
  for (int t=1; t <= cases; t++) {
    printf("Case #%d: ", t);
    memset(c, 0, sizeof c);
    int r1, r2;
    s(r1);
    for (int i=0; i < 4; i++) 
    for (int j=0; j < 4; j++) {
      int v;
      s(v);
      if (i+1 == r1) {
        c[v] += 1;
      }
    }
    s(r2);
    
    for (int i=0; i < 4; i++) 
    for (int j=0; j < 4; j++) {
      int v; s(v);
      if (i + 1 == r2) {
        c[v] += 1;
      }
    }
    int sol = 0, lastSol = 0;
    for (int i=1; i <= 16; i++)
      if (c[i] == 2) {
        sol ++;
        lastSol = i;
      }
    if (sol == 0) {
      puts("Volunteer cheated!");
    } else if (sol != 1) {
      puts("Bad magician!");
    } else {
      printf("%d\n", lastSol);
    }
  }
}
