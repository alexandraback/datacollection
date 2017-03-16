#include "stdio.h"
int v[30];
void proc(int q){
  int n;
  scanf("%d",&n);
  int sum=0;
  for(int i=0;i<n;i++){
    scanf("%d",&v[i]);
    sum+=v[i];
  }
  int mx1=0,mx2=0;
  int left=n;
  printf("Case #%d: ",q);
  while(true){
    mx1=0;
    mx2=0;
    for(int i=1;i<n;i++){
      if(v[i]>v[mx1])mx1=i;
    }
    if(mx1==0)mx2=1;
    for(int i=1;i<n;i++){
      if(v[i]>v[mx2]&&i!=mx1)mx2=i;
    }
    printf("%c",mx1+'A');
    v[mx1]--;
    for(int i=0;i<n;i++){
      if(v[i]*2>sum-1){
        printf("%c",i+'A');
        v[mx2]--;
        sum--;
      }
    }
    printf(" ");
    sum--;
    if(sum==0)break;

  }
  printf("\n");
}
int main(){
  int q;
  scanf("%d",&q);
  for(int i=1;i<=q;i++)proc(i);
  return 0;
}
