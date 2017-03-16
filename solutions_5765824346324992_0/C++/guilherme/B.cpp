#include<cstdio>
#include<algorithm>
#include<cassert>
using namespace std;
typedef long long huge;
int n,m;

huge tempo[1999];
int lis [1999];
int dah(huge t){

  huge ent = 0;
  int c = 0;
  for(int i=0;i<n;i++){
    if (t%tempo[i]==0){
      lis[c++]=i+1;
      ent += t/tempo[i];

    }else {
      ent += 1+(t-1)/tempo[i];
    }
  }
  //  if(t==10)printf("<%d %d %d>",ent,c,m);
  if (ent+c<m){
    return -1;
  } else if (ent>=m){
    return 9999;
  }
  else {
    return lis[m-ent-1];
  }
  return true;
}
int main () {
  int tt;
  scanf("%d",&tt);
  for(int rr=1;rr<=tt;rr++){
    int ret =0;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
      scanf("%lld",&tempo[i]);
    //test
    huge t1 = 0,t2 = 10000000000000000ll;
    huge x;
    while(t1<t2){
      x = (t1+t2)/2;
      int r = dah(x);
      if (r<1){
	t1 = x+1;
      }else if(r>n){
	t2 = x-1;
      }
      else{
	break;
      }
    }
    x = (t1+t2)/2;
    ret = dah(x);
    
    /* while(ret<1){
      x++;
      ret = dah(x);
    
    }

    while (x>1) {
      int r = dah(x-1);
      if (r>=1 && r<=n){
	ret = r;
	x--;
      }
      else break;
      }*/
    if(x>1)assert(dah(x-1)<1);
    assert(dah(x+1)>n);
    

    /*    for(int i=0;i<=25*n;i++){
      int x = dah(i);
      if (x>=1 && x<=n){
	ret = x;
	break;
      }
      }*/
    
    printf("Case #%d: %d\n",rr,ret);
    
  }
  return 0;
}
