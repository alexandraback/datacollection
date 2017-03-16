#include <cstdio>
#include <cstdlib>
int T,r,s[4],cnt[17],total,note,i,j,k,l;
int main (){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("GCJ14_Q_Q1_output.out","w",stdout);
	scanf("%d",&T);
	for (i=1;i<=T;i++){
		for (j=1;j<=16;j++) cnt[j]=0;
		for (j=0;j<2;j++){
			scanf("%d",&r);
			for (k=1;k<=4;k++){
				for (l=0;l<4;l++){
					scanf("%d",&s[l]);
					if (r==k) cnt[s[l]]++;
				}
			}
		}
		total=0;
		for (j=1;j<=16;j++){
			if (cnt[j]==2){
				total++;
				note=j;
			}
		}
		printf("Case #%d: ",i);
		if (total==0){
			printf("Volunteer cheated!\n");
		} else if (total==1){
			printf("%d\n",note);
		} else {
			printf("Bad magician!\n");
		}
	}
	return 0;
}
