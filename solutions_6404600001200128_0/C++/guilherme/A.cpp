#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int mush[1999];
int main () {
  int tt;
  scanf("%d",&tt);
  for(int rr=1;rr<=tt;rr++) {
    int a=0,b=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
      scanf("%d",&mush[i]);
    for(int i=0;i<n-1;i++) {
      a+= max(0,mush[i]-mush[i+1]);
    }
    int x = 0;
    for(int i=0;i<n-1;i++){
      x = max(x,mush[i]-mush[i+1]);
    }
    for(int i=0;i<n-1;i++){
      b += min(x,mush[i]);
      //      printf("<%d>",min(x,mush[i]));
    }
    printf("Case #%d: %d %d\n",rr,a,b);
  }
  return 0;
}
