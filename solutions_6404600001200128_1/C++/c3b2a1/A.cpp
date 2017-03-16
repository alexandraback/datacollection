#include<stdio.h>

int cnt[1000];

int main(int agrc,char*argv[]){
  int T;scanf("%d",&T);
  for(int tc=1;tc<=T;tc++){
    int N;scanf("%d",&N);
    for(int i=0;i<N;i++) scanf("%d",&cnt[i]);
    int mn=0;
    int y=0;for(int i=1;i<N;i++){
      if(cnt[i-1]>cnt[i]){
        y-=cnt[i]-cnt[i-1];
        if(cnt[i-1]-cnt[i]>mn) mn=cnt[i-1]-cnt[i];
      }
    }
   // mn=((mn)/10+((mn%10==0?0:1)))*10;
    //printf("\n%d\n",mn);
    int z=0;
    for(int i=0;i<N-1;i++){
      z+=(cnt[i]>=mn)?mn:cnt[i];
    }
    printf("Case #%d: %d %d\n",tc,y,z);
  }
  return 0;
}
