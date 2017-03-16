#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

using namespace std;

short a[17];

int main() {
  int nCase;
  scanf("%d", &nCase);
  for(int iCase = 1; iCase <= nCase; iCase++) {
    printf("Case #%d: ", iCase);
    memset(a, 0, sizeof(a));
    for(int k = 0; k < 2; k++) {
      int t0;
      scanf("%d", &t0);
      t0--;
      for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++) {
          int t1;
          scanf("%d", &t1);
          if(t0 == i)
            a[t1]++;
        }
    }
    int t0 = 0, t1;
    for(int i = 1; i <= 16; i++)
      if(a[i] == 2) {
        t0++;
        t1 = i;
      }
    switch(t0) {
    case 0:
      puts("Volunteer cheated!");
      break;
    case 1:
      printf("%d\n", t1);
      break;
    default:
      puts("Bad magician!");
    }
  }
  return 0;
}
