#include <stdio.h>

int arr1[5][5];
int arr2[5][5];

int main(){
  int jcase;
  int r1, r2;
  int ans, ctAns;
  
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(int icase=0; icase<jcase; icase++){
    scanf("%d", &r1);
    for(int i=0; i<4; i++){
      for(int j=0; j<4; j++) scanf("%d", &arr1[i][j]);
    }
    scanf("%d", &r2);
    for(int i=0; i<4; i++){
      for(int j=0; j<4; j++) scanf("%d", &arr2[i][j]);
    }
    
    ctAns = 0;
    r1--; r2--;
    for(int i=0; i<4; i++){
      for(int j=0; j<4; j++){
        if(arr1[r1][i] == arr2[r2][j]){
          ans = arr1[r1][i];
          ctAns++;
        }
      }
    }
    
    printf("Case #%d: ", icase+1);
    if(ctAns == 0) printf("Volunteer cheated!\n");
    else if(ctAns > 1) printf("Bad magician!\n");
    else printf("%d\n", ans);
  }
  return 0;
}
