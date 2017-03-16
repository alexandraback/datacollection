#include <cstdio>

int main(){
  for(int TT, T = (scanf("%d", &TT), 1); T <= TT; T++){
    printf("Case #%d: ", T);
    int X, Y, K;
    scanf("%d %d %d", &X, &Y, &K);
    int ans = 0;
    for(int x = 0; x < X; x++)
      for(int y = 0; y < Y; y++){
        if((x & y) < K){
          ans++;
        }
      }
    printf("%d\n", ans);
  }
  return 0;
}
