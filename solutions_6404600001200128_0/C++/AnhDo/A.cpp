#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
  freopen("A-small-attempt0.in", "r",stdin);
  freopen("output.txt", "w",stdout);
  int T, N, a[1005];
  scanf("%d",&T);
  for(int t = 1; t <= T; t++){
    scanf("%d",&N);
    for(int i = 0; i < N; i++)scanf("%d",&a[i]);
    //
    int res1 = 0;
    for(int i = 0; i < N-1; i++)res1 += max(a[i]-a[i+1],0);
    //
    int res2 = 0, per = 0;
    for(int i = 0; i < N-1; i++)per = max(per, (a[i]-a[i+1]+9)/10);
    for(int i = 0; i < N-1; i++)res2 += min(a[i], per*10);
    //
    printf("Case #%d: %d %d\n", t, res1, res2);
  }
  return 0;
}
