#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define SZ(c) ((int)(c).size())
typedef long long LL;

int main(void) {
  int T, r, x;
  scanf("%d", &T);
  for(int cs=1;cs<=T;cs++) {
    int a[20]={};
    scanf("%d", &r);
    for(int i=1;i<=4;i++) for(int j=1;j<=4;j++) {
      scanf("%d", &x); if(i==r) a[x]++;
    }
    scanf("%d", &r);
    for(int i=1;i<=4;i++) for(int j=1;j<=4;j++) {
      scanf("%d", &x); if(i==r) a[x]++;
    }
    int v = max_element(a+1, a+17)-a;
    printf("Case #%d: ", cs);
    if(a[v] < 2) puts("Volunteer cheated!");
    else if(*max_element(a+v+1, a+18) == 2) puts("Bad magician!");
    else printf("%d\n", v);
  }
  return 0;
}
