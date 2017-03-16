#include <cstdio>
#include <algorithm>
using namespace std;

int R, C, N;
bool ap[16][16];
int minn;

void put(int idx, int placed, int unhap){
  int temp = 0;

  if(placed == N){
    minn = min(unhap, minn);
    return;
  }
  else if(idx == R*C)return;

  ap[idx / C][idx % C] = 1;
  if(idx / C > 0 && ap[idx / C - 1][idx % C])temp++;
  if(idx % C > 0 && ap[idx / C][idx % C - 1])temp++;
  put(idx + 1, placed + 1, unhap + temp);

  ap[idx / C][idx % C] = 0;
  put(idx + 1, placed, unhap);
}

int main(){
  int T;
  scanf("%d", &T);

  for(int tt = 1; tt <= T; tt++){
    scanf("%d %d %d", &R, &C, &N);

    minn = 256;
    put(0, 0, 0);

    printf("Case #%d: %d\n", tt, minn);
  }
}
