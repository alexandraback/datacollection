#include <stdio.h>
#include <string.h>

struct node{
  char c;
  int count;
};

int T,N,tam, ok, K, resp, aux, maximo, atual;
node v[110][110];
int num[110];
char s[110];

int abs(int a){
  if(a<0) return -a;
  return a;
}

int main(){
  scanf(" %d", &T);
  for(int u=1; u<=T; u++){
    scanf(" %d", &N);
    memset(num, 0, sizeof(num));
    
    for(int i=0; i<N; i++){
      scanf(" %s", s);
      tam = strlen(s);
      
      v[i][0].c = s[0];
      v[i][0].count = 1;
      num[i] = 1;
      for(int j=1; j<tam; j++){
        if(s[j] == v[i][num[i]-1].c){
          v[i][num[i]-1].count++;
        }
        else{
          num[i]++;
          v[i][num[i]-1].count = 1;
          v[i][num[i]-1].c = s[j];
        }
      }
    }
    
    ok = 1;
    for(int i=1; i<N; i++){
      if(num[i] != num[i-1]){
        ok = 0;
      }
    }
    
    if(ok==1){
      K = num[0];
      for(int i=1; i<N; i++){
        for(int j=0; j<K; j++){
          if(v[i][j].c != v[i-1][j].c){
            ok = 0;
          }
        }
      }
    }
    
    printf("Case #%d: ", u);
    if(ok == 0) printf("Fegla Won\n");
    else{
      resp = 0;
      for(int j=0; j<K; j++){
        maximo = 0;
        for(int i=0; i<N; i++){
          if(v[i][j].count>maximo) maximo = v[i][j].count;
        }
        
        aux = 2000000000;
        
        for(int k=0; k<=maximo; k++){
          atual = 0;
          for(int i=0; i<N; i++){
            atual += abs(k-v[i][j].count);
          }
          if(atual<aux) aux = atual;
        }
        
        resp += aux;
      }
      printf("%d\n", resp);
    }
  }
  return 0;
}
