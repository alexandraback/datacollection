#include<cstdio>
#include<cstdlib>

void work(){
  int ans[20]={0};
  for(int m = 0; m <2; m++){
    int b;
    scanf("%d", &b);
    for(int i = 1; i <=4; i++)
      for(int j = 1; j <=4;j++){
	int x;
	scanf("%d", &x);
	if(i==b)
	  ans[x]++;
      }
  }
  int tot = 0,res;
  for(int i = 1; i<=16;i++){
    if(ans[i]==2){
      tot++;
      res = i;
    }
      
  }
  if(tot == 1){
    printf("%d\n",res);
    return;
  }
  if(tot ==0){
    printf("Volunteer cheated!\n");
    return;
  }
  printf("Bad magician!\n");
}
int main()
{
  int T;
  scanf("%d", &T);
  for(int i = 1; i <=T; i++){
    printf("Case #%d: ",i);
    work();
  }
}
