#include <cstdio>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

int run() {
  int R,C,N;
  scanf("%d%d%d",&R,&C,&N);
  if (N<=(R*C+1)/2) return 0;
  if (R==1) return 2*N-C-1;
  if (C==1) return 2*N-1-R;
  int unh=R*(C-1)+(R-1)*C;
  int mid=(R-2)*(C-2);
  if (N>=R*C-(mid+1)/2) return unh-4*(R*C-N);
  int p1=(mid+1)/2;
  int p2=mid/2;
  int rest1=R*C-N-p1;
  int rest2=R*C-N-p2;
  int unh1=unh-4*p1;
  int unh2=unh-4*p2;
  int side1,side2;
  if ((R*C)%2) { side1=(R+C)-6; side2=(R+C)-4; }
  else { side1=side2=R+C-4; }
  int s1=min(side1,rest1);
  rest1-=s1;
  unh1-=3*s1;
  int s2=min(side2,rest2);
  rest2-=s2;
  unh2-=3*s2;
  while (rest1>0) { --rest1; unh-=2; }
  while (rest2>0) { --rest2; unh-=2; }
  return min(unh1,unh2);
}

int main() {
  int T;
  scanf("%d",&T);
  for (int t=1;t<=T;++t) {
    printf("Case #%d: ",t);
    printf("%d\n",run());
  }
  return 0;
}
