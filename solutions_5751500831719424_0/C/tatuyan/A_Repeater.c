#include<stdio.h>
#include<string.h>

#define ABS(x) (((x)<0)?(-(x)):(x))

int main(void){
  int num[100][100];
  char pch[100];
  char str[100][101];
  int i,j,k,l,T,N,test,numch,flg,nowmax,count;
  int sub;
  
  scanf("%d%*c",&T);
  for(test=1;test<=T;test++){
    scanf("%d%*c",&N);
    for(i=0;i<N;i++) scanf("%s%*c",str[i]);
    for(i=0;i<100;i++) pch[i]=0;
    for(i=0;i<100;i++) for(j=0;j<100;j++) num[i][j]=0;
    
    l=strlen(str[0]);
    numch=0;
    for(i=0;i<l;i++)
      if(numch==0 || pch[numch-1]!=str[0][i]) pch[numch++]=str[0][i];
    
    flg=0;
    for(i=0;i<N;i++){
      l=strlen(str[i]);
      k=0;
      for(j=0;j<l;j++){
	while(pch[k]!=str[i][j]){
	  k++;
	  if(k==numch){
	    flg=1;
	    break;
	  }
	}
	if(k==numch) break;
	num[i][k]++;
      }
      if(k==numch) break;
    }

    /*for(i=0;i<N;i++){
      for(j=0;j<numch;j++)
	printf("%d%c",num[i][j],(j==numch-1)?'\n':' ');
	}*/
    
    
    for(i=0;i<N;i++){
      l=strlen(str[i]);
      for(j=0;j<numch;j++){
	if(num[i][j]==0) flg=2;
	l-=num[i][j];
      }
      if(l!=0) flg=3;
    }
    
    if(flg){
      printf("Case #%d: Fegla Won\n",test);
      continue;
    }

    count=0;
    for(i=0;i<numch;i++){
      nowmax=100000;
      for(j=1;j<=100;j++){
	l=0;
	for(k=0;k<N;k++) l+=ABS(num[k][i]-j);
	if(nowmax>=l) nowmax=l;
	else break;
      }
      count+=nowmax;
    }

    /*sub=0;
      for(i=0;i<numch;i++) sub+=ABS(num[0][i]-num[1][i]);*/

    printf("Case #%d: %d\n",test,count);
  }
  return 0;
}
