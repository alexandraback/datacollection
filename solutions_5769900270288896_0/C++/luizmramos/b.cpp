#include <stdio.h>
#include <algorithm>

int v[20000];
int n,r,c;

void set(int i, int j, int x) {
	v[i*c+j]=x;
}

int get(int i, int j){
	return v[i*c+j];
}
int dx[]={0,1,-1,0};
int dy[]={-1,0,0,1};


int count(int x) {
	int indice=0;
	for(int i=0;i<r*c;i++)set(i/c,i%c,0);
	while(x>0){
		if(x&1){
			set(indice/c,indice%c,1);
		}
		indice++;
		x=x>>1;
	}
	int contador=0;
	//for(int i=0;i<r;i++){
	//	for(int j=0;j<c;j++)printf("%d ", get(i,j));
	//		printf("\n");
	//}
	for(int indice = 0; indice<r*c;indice++){
		int i=indice/c;
		int j=indice%c;
		if(get(i,j)==0)continue;
		for(int d=0;d<4;d++){
			int ni=i+dx[d];
			int nj=j+dy[d];
			if(ni<0 || nj<0 || ni>=r||nj>=c)continue;
			if(get(ni,nj)!=0){
				contador++;
			}
		}
	}
	return contador/2;
}

int main(){
	int testes;
	scanf("%d",&testes);
	for(int xxx=0;xxx<testes;xxx++) {
		scanf("%d %d %d",&r,&c,&n);
		int ans=100000;
		for(int i=0;i<(1<<(r*c));i++){
			if(__builtin_popcount(i)!=n)continue;
			ans=std::min(ans,count(i));
		}
		printf("Case #%d: %d\n",xxx+1, ans);

	}
}