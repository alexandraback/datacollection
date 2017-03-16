#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
  freopen("B-small-attempt1.in","r",stdin);
  freopen("output.txt","w",stdout);
  int T, N, B, a[2000];
  scanf("%d", &T);
  for (int t = 1; t <= T; t++){
    scanf("%d%d",&N,&B);
    for(int i = 0; i < N; i++)scanf("%d",&a[i]);
    long long l = 0, h = 1LL*100000*1000*1000*1000+1,r,m, tmp;
    while( l <= h){
      m = (l + h)/2;
      tmp = 0;
      for(int i = 0; i < N; i++)tmp += m/a[i] + 1;
      if(tmp>=B) h = m - 1, r = m;
        else l = m + 1;
    }
    //cout << r <<endl;
    int cnt = B;
    for(int i = 0; i < N; i++)cnt -= (r+a[i]-1)/a[i];
    for(int i = 0; i < N; i++)if(r%a[i]==0){
        cnt--;
        if(cnt==0){printf("Case #%d: %d\n",t,i+1);
          break;
          }
      }
    //cout<<cnt<<endl;
  }
  return 0;
}
