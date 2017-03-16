#include <stdio.h>

int main(){
	int n,x;
	int i,j,k,l;
	int hoge;
	int c[4];
	int ans;
	scanf("%d",&n);
	for(l=1;l<=n;l++){
		scanf("%d",&x);
		for(i=0;i<4;i++){
			if(i+1 == x){ for(j=0;j<4;j++){ scanf("%d", c+j);}}
			else{ for(j=0;j<4;j++){ scanf("%d", &hoge);} }
		}
		scanf("%d",&x);
		for(i=0;i<4;i++){
			if(i+1 == x){
				ans = 0;
				for(j=0;j<4;j++){
					scanf("%d", &hoge);
					if(ans == -1) continue;
					for(k=0;k<4;k++){ if(c[k] == hoge) break; }
					if(k!=4){
						if(ans == 0){ans = hoge;}
						else{ans = -1; }
					}
				}
				if(ans==0){ printf("Case #%d: Volunteer cheated!\n",l);}
				else if(ans==-1){ printf("Case #%d: Bad magician!\n",l);}
				else{ printf("Case #%d: %d\n",l,ans);}
			}
			else{ for(j=0;j<4;j++){ scanf("%d", &hoge);} }
		}
	}
}
