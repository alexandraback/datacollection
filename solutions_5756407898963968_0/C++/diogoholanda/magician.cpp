#include <stdio.h>
#include <string.h>

int T, resp,cont, ultimo;
int marcado[20];
int tabela[5][5];

int main(){
  scanf(" %d", &T);
  for(int u=1; u<=T; u++){
    memset(marcado,0,sizeof(marcado));
    scanf(" %d", &resp);
    for(int i=1; i<=4; i++){
      for(int j=1; j<=4; j++){
        scanf(" %d", &tabela[i][j]);
      }
    }
    
    for(int j=1; j<=4; j++){
      marcado[tabela[resp][j]]++;
    }
    
    scanf(" %d", &resp);
    for(int i=1; i<=4; i++){
      for(int j=1; j<=4; j++){
        scanf(" %d", &tabela[i][j]);
      }
    }
    
    for(int j=1; j<=4; j++){
      marcado[tabela[resp][j]]++;
    }
    
    cont=0;
    for(int i=1; i<=16; i++){
      if(marcado[i]==2){
        cont++;
        ultimo = i;
      }
    }
    
    printf("Case #%d: ", u);
    if(cont==0) printf("Volunteer cheated!\n");
    else if(cont==1) printf("%d\n", ultimo);
    else printf("Bad magician!\n");
  }
  return 0;
}
