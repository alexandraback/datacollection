#include <cstdio>
using namespace std;
int t,tt,n,m,k,best,a[22][22];
void rec(int i, int j, int k, int s) {
  if (i>n) {
    if (k==0 && s<best) best=s;
    return;
  }
  if (j>m) {
    rec(i+1,1,k,s);
    return;
  }
  if (k>0) {
    a[i][j]=1;
    rec(i,j+1,k-1,s+a[i-1][j]+a[i][j-1]);
    a[i][j]=0;
  }
  rec(i,j+1,k,s);
}
int main() {
  freopen("Bs.in","r",stdin);
  freopen("Bs.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d%d",&n,&m,&k);
    best=1000000000;
    rec(1,1,k,0);
    printf("Case #%d: %d\n",t,best);
  }
  return 0;
}
