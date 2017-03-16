#include<cstdio>
#include<cstring>

#include<iostream>
using namespace std;

bool used[17];
int main() {
  int ca, a,c, r;
  bool done;
  scanf("%d", &ca);
  for(int cas=1; cas<=ca; cas++) {
    printf("Case #%d: ", cas);

    r=0;
    done = false;
    memset(used, 0, sizeof(used));

    scanf("%d", &a);
    for (int i=0; i<4; ++i) {
      for (int j=0; j<4; ++j) {
        scanf("%d", &c);
        if (i == a-1) {
          used[c] = true;
        }
      }
    } 
    scanf("%d", &a);
    for (int i=0; i<4; ++i) {
      for (int j=0; j<4; ++j) {
        scanf("%d", &c);
        if (i == a-1 && used[c]) {
          if (!done && r) {
            printf("Bad magician!\n"); 
            done = true;
          } else {
            r = c;
          }
        }
      }
    }
    if (done) continue;
    if (r) {
      printf("%d\n", r);
    } else {
      printf("Volunteer cheated!\n");
    }
  }
}
