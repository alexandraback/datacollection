#include <cstdio>
#include <algorithm>
using namespace std;
int t,tt,n,m,k,kk,a1,a2,b1,b2,c,i,r,z;
int main() {
  freopen("Bl.in","r",stdin);
  freopen("Bl.out","w",stdout);
  scanf("%d",&tt);
  for (t=1; t<=tt; t++) {
    scanf("%d%d%d",&n,&m,&k);
    if (n>m) swap(n,m);
    if (n==1) {
      c=(m+1)/2;
      if (c<k) {
        k-=c;
        if (m%2==0) {
          r=1; k--;
        } else r=0;
        r+=k*2;
      } else r=0;
      z=r;
    } else {
    a1=(n+1)/2; a2=n-a1;
    b1=(m+1)/2; b2=m-b1;
    c=a1*b1+a2*b2; kk=k;
    if (c<k) {
      k-=c;
      c=int(a1==a2)+int(b1==b2)+int(a1-a2+b1-b2==1);
      if (c<k) {
        r=2*c;
        k-=c;
        for (c=0, i=2; i<n; i++) {
          if ((i+1)&1) c++;
          if ((i+m)&1) c++;
        }
        for (i=2; i<m; i++) {
          if ((i+1)&1) c++;
          if ((i+n)&1) c++;
        }
        if (c<k) r+=3*c+4*(k-c); else r+=3*k;
      } else r=2*k;
    } else r=0;
    z=r; r=0; k=kk;
    c=a1*b2+a2*b1;
    if (c<k) {
      k-=c;
      c=4-int(a1==a2)-int(b1==b2)-int(a1-a2+b1-b2==1);
      if (c<k) {
        r=2*c;
        k-=c;
        for (c=0, i=2; i<n; i++) {
          if (i&1) c++;
          if ((i+m+1)&1) c++;
        }
        for (i=2; i<m; i++) {
          if (i&1) c++;
          if ((i+n+1)&1) c++;
        }
        if (c<k) r+=3*c+4*(k-c); else r+=3*k;
      } else r=2*k;
    } else r=0;
    z=min(z,r);
    }
    printf("Case #%d: %d\n",t,z);
  }
  return 0;
}   
