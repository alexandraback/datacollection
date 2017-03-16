#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define FALSE 0
#define TRUE 1

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

int main(void)
{
  int i,j,k,n,count,row,pos[32],tmp;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    for(j=0;j<32;j++) pos[j]=0;
    for(k=0;k<2;k++){
      scanf("%d",&row);
      for(j=0;j<16;j++){
        scanf("%d",&tmp);
        if(row-1==j/4) pos[tmp]++;
      }
    }
    tmp=0;
    for(j=1;j<=16;j++)
      if(pos[j]==2){
        if(tmp) tmp=17;
        else tmp=j;
      }
    if(tmp==0){
      printf("Case #%d: Volunteer cheated!\n",i+1);
      continue;
    }
    if(tmp==17){
      printf("Case #%d: Bad magician!\n",i+1);
      continue;
    }
    printf("Case #%d: %d\n",i+1,tmp);
  }

  return 0;
}
