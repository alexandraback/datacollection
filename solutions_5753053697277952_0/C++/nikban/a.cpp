#include<bits/stdc++.h>
using namespace std;

int sort2d(int p[][2], int n){
	int i, j, tmp;
	for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(p[i][0]<p[j][0]){
				tmp=p[i][0];
				p[i][0]=p[j][0];
				p[j][0]=tmp;

				tmp=p[i][1];
				p[i][1]=p[j][1];
				p[j][1]=tmp;
			}
		}
	}
	return 0;
}

int main(){
	int t,n,p[100][2],i;
	scanf("%d",&t);
	for(int cas=1;cas<=t;cas++){
		printf("Case #%d: ",cas);

		scanf("%d",&n);
		for(i=0;i<n;i++){
			scanf("%d",&p[i][0]);
			p[i][1]=i;
		}

		sort2d(p, n);
		while(p[0][0]){
			if(p[0][0]==p[1][0]){
				if(p[1][0]==p[2][0]){
					p[0][0]--;
					printf("%c ", (65+p[0][1]));
				}
				else{
					p[0][0]--;
					p[1][0]--;
					printf("%c%c ", (65+p[0][1]), (65+p[1][1]));
				}
			}
			else{
				p[0][0]--;
				printf("%c ", (65+p[0][1]));
			}
			sort2d(p, n);
		}

		printf("\n");
	}
	return 0;
}