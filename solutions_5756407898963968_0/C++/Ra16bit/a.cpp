#include <cstdio>
using namespace std;
int t,tt,i,j,x,y,c,z,a[4][4],b[4][4];
int main() {
  freopen("As.in","r",stdin);
  freopen("As.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d",&x); x--;
    for (i=0; i<4; i++) for (j=0; j<4; j++) scanf("%d",&a[i][j]);
    scanf("%d",&y); y--;
    for (i=0; i<4; i++) for (j=0; j<4; j++) scanf("%d",&b[i][j]);
    for (c=i=0; i<4; i++) for (j=0; j<4; j++) if (a[x][i]==b[y][j]) {
      c++;
      z=a[x][i];
      break;
    }
    printf("Case #%d: ",t);
    if (c==1) printf("%d\n",z); else if (c) puts("Bad magician!"); else puts("Volunteer cheated!");
  }
  return 0;
}
