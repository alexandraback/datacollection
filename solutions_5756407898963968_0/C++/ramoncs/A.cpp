#include <cstdio>

int main(){
	int r,t,test=0,v;
	bool vet[20];
	scanf("%d",&t);
	while(t--){
		for(int i=1; i<=16; i++)vet[i]=false;
		scanf("%d",&r);
		for(int i=1; i<=4; i++){
			for(int j=1; j<=4; j++){
				scanf("%d",&v);
				if(r==i){
					vet[v]=true;
					//printf("vet[\n");
				}
			}
		}

		scanf("%d",&r);
		for(int i=1; i<=4; i++){
			for(int j=1; j<=4; j++){
				scanf("%d",&v);
				if(r==i && vet[v]){
					vet[v]=true;
				}else{
					vet[v]=false;
				}
			}
		}
		int cont=0;
		for(int i=1; i<=16; i++){
			if(vet[i]){
				cont++;
				v = i;
			}
		}
		printf("Case #%d: ",++test);
		if(cont==1){
			printf("%d\n",v);
		}else if(cont>1){
			printf("Bad magician!\n");
		}else{
			printf("Volunteer cheated!\n");
		}

	}
	return 0;
}