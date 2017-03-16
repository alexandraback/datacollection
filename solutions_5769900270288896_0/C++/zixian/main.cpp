#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
  int numTC, TC = 1, R, C, N, ans1, ans2, corner, side, rem;
  bool oddRow, oddCol;
  scanf("%d", &numTC);
  while(numTC--){
    scanf("%d %d %d", &R, &C, &N);
    if(N<=((R*C+1)>>1)){ printf("Case #%d: 0\n", TC++); continue; }
    
    //Try 1st method
    rem = N-((R*C+1)>>1); oddRow = (R&1); oddCol = (C&1); ans1 = side = 0;
    corner = (oddRow && oddCol)? 0: 2;
    side+=oddRow? ((R>>1)<<1): (((R-1)>>1)<<1);
    side+=oddCol? ((C>>1)<<1): (((C-1)>>1)<<1);
    while(corner || side){
      if(corner){ ans1+=2; corner--; }
      else{ ans1+=3; side--; }
      if(!(--rem)) break;
    }
    ans1+=(rem<<2);

    //Try 2nd method
    rem = N-((R*C)>>1); ans2 = side = 0;
    corner = (oddRow && oddCol)? 4: 2;
    side+=oddRow? ((R-2)>>1)<<1: ((R-1)>>1)<<1;
    side+=oddCol? ((C-2)>>1)<<1: ((C-1)>>1)<<1;
    while(corner || side){
      if(corner){ ans2+=2; corner--; }
      else{ ans2+=3; side--; }
      if(!(--rem)) break;
    }
    ans2+=(rem<<2);
    printf("Case #%d: %d\n", TC++, min(ans1, ans2));
  }
  return 0;
}
