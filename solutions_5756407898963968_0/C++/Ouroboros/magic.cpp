#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

int T;
int main() {
  cin >> T;
  int t[17];
  int run = 0;
  while (run++ < T) {
    int a,b,c,k,num;
    k = 0;
    for (int i = 0;i <= 16;i++) t[i] = 0;
    cin >> a;
    a--;
    for (int i = 0;i < 16;i++) {
      cin >> c;
      if (i >=a*4 && i < a*4+4) {
        t[c] = 1;
      }
    }
    cin >> b;
    b--;
    for (int i = 0;i < 16;i++) {
      cin >> c;
      if (i >=b*4 && i < b*4+4) {
        if (t[c] == 1) { 
          k++;
          num = c;
        }
      }
    }
    if (k == 0) {
      printf("Case #%d: Volunteer cheated!\n",run);
    } else if (k == 1) {
      printf("Case #%d: %d\n",run,num);
    } else {
      printf("Case #%d: Bad magician!\n",run);
    }
  }
}
