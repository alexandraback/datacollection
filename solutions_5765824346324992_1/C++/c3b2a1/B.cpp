#include<stdio.h>


long long int m[1000];
int B;

long long int val(long long int n){
  long long int res=0;
  for(int i=0;i<B;i++){
    res+=1+(n)/m[i];
  }
  return res;
}

int main(int agrc,char*argv[]){
  int T;scanf("%d",&T);
  for(int tc=1;tc<=T;tc++){
    long long int N;scanf("%d%lld",&B,&N);
    for(int i=0;i<B;i++) scanf("%lld",&m[i]);
    long long int rm=0;
    long long int it=0;
    long long int d=1100000000;d*=1000;
    while (d>0){
      it=rm+d/2;
      if (!((N-1)<val(it)))   
        { rm=++it; d-=d/2+1;  }
      else d=d/2;
    }
    d=N-val(rm-1);
   // printf("\n%lld %lld\n",d,rm);
   // printf("%lld\n",d);
    int res=0;
    while(d!=0){
      if(rm/m[res]!=(rm-1)/m[res])
        d--;
      res++;
  //    printf(".\n");
    }
    printf("Case #%d: %d\n",tc,res);
  }
  return 0;
}
