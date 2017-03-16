#include <cstdio>
int t;
int a;
int b;
int c[22];
int main(void){
  int T;
  scanf("%d",&T);
  for(int t = 1; t <= T; t++){
    for(int i = 0; i < 22; i++) c[i] = 0;

    for(int k = 0; k < 2; k++){
      scanf("%d",&a);
      for(int i = 1; i <= 4; i++){
	for(int j = 1; j <= 4; j++){
	  scanf("%d",&b);
	  if(a == i) c[b]++;
	}
      }
    }

    int ans = -1;
    bool f = true;
    for(int i = 1; i <= 16; i++){
      if(c[i] >= 2){
	if(ans != -1){
	  printf("Case #%d: Bad magician!\n",t);
	  f = false;
	  break;
	}
	ans = i;
      }
    }
    if(f){
      if(ans != -1) printf("Case #%d: %d\n",t,ans);
      else printf("Case #%d: Volunteer cheated!\n",t);
    }
  }
}
