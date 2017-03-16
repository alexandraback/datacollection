#include<stdio.h>

int card[20],card2[20];
int main()
{
	FILE *fi=fopen("input.txt","r");
	FILE *fo=fopen("output.txt","w");
	int t,p,i,j,k,l,cnt,a;

	fscanf(fi,"%d",&t);
	for(p=0;p<t;p++){
		fscanf(fi,"%d",&a);
		cnt = 0;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				fscanf(fi,"%d",&k);
				if(i == a-1)
					card[cnt++]=k;
			}
		}
		fscanf(fi,"%d",&a),cnt=0;
		for(i=0;i<4;i++){
			for(j=0;j<4;j++){
				fscanf(fi,"%d",&k);
				if(i == a-1){
					for(l = 0;l<4;l++) if(card[l] == k) break; 
					if(l !=4) card2[cnt++] = k;
				}
			}
		}
		fprintf(fo,"Case #%d: ",p+1);
		if(cnt == 0) fprintf(fo,"Volunteer cheated!\n");
		else if(cnt >=2) fprintf(fo,"Bad magician!\n");
		else fprintf(fo,"%d\n",card2[0]);
	}
}